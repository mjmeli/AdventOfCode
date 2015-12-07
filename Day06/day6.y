%{
    #include <stdio.h>
    #include <stdbool.h>
    #define OFF     (false)
    #define ON      (true)
    #define FLIP    (-1)
    extern int yylex();
    int yyerror(char const * s);
    void changeLightStates(int, int, int, int, int);
    bool lights[1000][1000] = {false};
    int brightness[1000][1000] = {0};
%}
%union {
    int num;
}
%token TURN_ON TOGGLE TURN_OFF THROUGH NEWLINE COMMA
%token <num> NUM
%%

command_list:
    command_list command
  | command
;

command:
    TURN_ON NUM COMMA NUM THROUGH NUM COMMA NUM NEWLINE
    {
        changeLightStates($2, $4, $6, $8, ON);
    }
  | TOGGLE NUM COMMA NUM THROUGH NUM COMMA NUM NEWLINE
    {
        changeLightStates($2, $4, $6, $8, FLIP);
    }
  | TURN_OFF NUM COMMA NUM THROUGH NUM COMMA NUM NEWLINE
    {
        changeLightStates($2, $4, $6, $8, OFF);
    }
;

%%

// Change the state of a range of lights
void changeLightStates(int x1, int y1, int x2, int y2, int new)
{
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            switch (new) {
                case ON:
                    lights[i][j] = ON;
                    brightness[i][j]++;
                    break;
                case OFF:
                    lights[i][j] = OFF;
                    brightness[i][j]--;
                    break;
                case FLIP:
                    lights[i][j] = !lights[i][j];
                    brightness[i][j] += 2;
                    break;
                default: break;
            }
            if (brightness[i][j] < 0) brightness[i][j] = 0;
        }
    }
}

extern FILE * yyin;
int main(int argc, char **argv) {
    if (argc > 0)
        yyin = fopen(argv[1], "r");
    else
        yyin = stdin;
    yyparse();
    int numOn = 0, totalBrightness = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (lights[i][j]) numOn++;
            totalBrightness += brightness[i][j];
        }
    }
    printf("There are %d lights turned on.\n", numOn);
    printf("The total brightness is %d.\n", totalBrightness);
    return 0;
}

int yyerror(char const * s)
{
  fprintf(stderr, "%s\n", s);
  return 1;
}
