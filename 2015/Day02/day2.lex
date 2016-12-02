%{
#include <stdio.h>
#include "day2.y.h"
%}

%%
[0-9]+      { yylval.side = atoi(yytext); return SIDE; }
"x"         return BY;
"\n"        return NEWLINE;
[ \t]       ;
.           ;
%%
