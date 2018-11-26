%option noyywrap
%{
  #include "projet.y.hpp"
  #include <iostream>
%}
%%
[0-9]+(\.[0-9]*)?([Ee][0-9]+)?  { yylval.valeur = atof(yytext); return NUMBER;  }

VRAI|Vrai|vrai  { yylval.valeur = 1; return NUMBER; }
FAUX|Faux|faux  { yylval.valeur = 0; return NUMBER; }

POSITION|Position|position|POS|Pos|pos  { return POSITION;  }

SI|Si|si                          { return IF; }
SINON|Sinon|sinon                 { return ELSE;  }
FINSI|Finsi|finsi                 { return ENDIF;  }
REPETE|Repete|repete              { return REPEAT;  }
FINREPETE|FinRepete|finrepete     { return ENDREPEAT; }

[a-zA-Z_]+                        { strcpy(yylval.nom,yytext); return IDENTIFIER; }

\n								{ return '\n'; }
\r								{ return '\n'; }
[ \t]							{ }
.                 { return yytext[0];}
%%
