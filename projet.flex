%option noyywrap
%{
  #include "projet.y.hpp"
  #include <iostream>
%}
%%
[0-9]+(\.[0-9]*)?([Ee][0-9]+)?  { yylval.valeur = atof(yytext); return NUMBER;  }

POSITION|Position|position|POS|Pos|pos  { return POSITION;  }
SI|Si|si                      { return IF; }
SINON|Sinon|sinon             { return ELSE;  }
FINSI|Finsi|finsi             { return ENDIF;  }

\n								{ return '\n'; }
\r								{ return '\n'; }
[ \t]							{ }
.                 { return yytext[0];}
%%
