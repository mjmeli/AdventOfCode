%{
#include "day6.y.h"
%}

%%
"turn on"       return TURN_ON;
"toggle"        return TOGGLE;
"turn off"      return TURN_OFF;
"through"       return THROUGH;
[0-9]+          { yylval.num = atoi(yytext); return NUM; }
","             return COMMA;
"\n"            return NEWLINE;
[ \t]           ;
.               ;
%%
