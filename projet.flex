%option noyywrap
%{
  #include "projet.y.hpp"
%}
%%
[0-9]+(\.[0-9]*)?([Ee][0-9]+)?  { yylval.valeur = atof(yytext); return NUMBER;  }
POSITION|Position|position|POS|Pos|pos  { return POSITION;  }
\n								{ return '\n'; }
\r								{ return '\n'; }
[ \t]							{ }
.                 { return yytext[0];}
%%
