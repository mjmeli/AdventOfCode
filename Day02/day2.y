%{
    #include <stdio.h>
    #define SURFACE_AREA(a, b, c)  (2*a*b + 2*b*c + 2*a*c)
    #define MIN_SIDE_AREA(a, b, c) (b<a?c<a?b*c:b*a:c<b?a*c:a*b)
    #define MIN_PERIMETER(a, b, c) (b<a?c<a?2*(b+c):2*(b+a):c<b?2*(a+c):2*(a+b))
    #define VOLUME(a, b, c)        (a*b*c)
    extern int yylex();
    int yyerror(char const * s);
    struct Materials order;
%}

%code requires {
    struct Materials {
        int paper;
        int ribbon;
    };
}

%union {
    int side;
    struct Materials materials;
}
%token BY NEWLINE
%token <side> SIDE
%type <materials> dimension
%type <materials> dimension_list;

%%

dimension_list:
    dimension_list dimension
    {
        // Add paper/ribbon of each present together
        order.paper += $2.paper;
        order.ribbon += $2.ribbon;
        $$ = order;
    }
  | dimension
    {
        order.paper = $1.paper;
        order.ribbon = $1.ribbon;
        $$ = order;
    }
;

dimension:
    SIDE BY SIDE BY SIDE NEWLINE
    {
        // Fill a materials struct with the needed paper/ribbon for this present
        struct Materials s;
        int l = $1, w = $3, h = $5;
        s.paper = SURFACE_AREA(l, w, h) + MIN_SIDE_AREA(l, w, h);
        s.ribbon = MIN_PERIMETER(l, w, h) + VOLUME(l, w, h);
        $$ = s;
    }
;

%%

extern FILE * yyin;
int main(int argc, char **argv) {
    if (argc > 0)
        yyin = fopen(argv[1], "r");
    else
        yyin = stdin;
    yyparse();
    printf("The elves need %d sq ft of wrapping paper and %d feet of ribbon!\n",
            order.paper, order.ribbon);
    return 0;
}

int yyerror(char const * s)
{
  fprintf(stderr, "%s\n", s);
  return 1;
}
