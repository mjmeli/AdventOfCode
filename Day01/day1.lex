%{
#include <stdio.h>
int floorNum = 0;
int enteredBasement = 0;
int enteredBasementAt = 0;
%}

%%
"("         { floorNum++; if (!enteredBasement) enteredBasementAt++; }
")"         { floorNum--; if (!enteredBasement) enteredBasementAt++; if (floorNum < 0) enteredBasement++; }
[ \t\n]+    ;
.           ;
%%

int main(int argc, char **argv) {
    if (argc > 0)
        yyin = fopen(argv[1], "r");
    else
        yyin = stdin;
    yylex();
    printf("Santa is on floor %d!\n", floorNum);
    printf("He first entered the basement at character %d.\n", enteredBasementAt);
    return 0;
}
