%option noyywrap
%{
  #include "projet.y.hpp"
  #include <iostream>
%}
%%
[0-9]+(\.[0-9]*)?([Ee][0-9]+)?  { yylval.valeur = atof(yytext); return NUMBER;  }

VRAI|Vrai|vrai|OUI|Oui|oui    { yylval.valeur = 1; return NUMBER; }
FAUX|Faux|faux|NON|Non|non    { yylval.valeur = 0; return NUMBER; }

PI|Pi|pi        { return PI; }

\/\/[^\n]*                          { return COMMENT; }
\/\*(.|\n)*\*\/                     { return BIGCOMMENT; }

\+                                  { return OP_PLUS; }
-                                   { return OP_MINUS; }
\*                                  { return OP_MULTIPLY; }
\/                                  { return OP_DIVIDE; }
\|\|                                { return OP_OR; }
\&\&                                { return OP_AND; }
>                                   { return OP_GREATER; }
>=                                  { return OP_GREATEREQUAL; }
==                                  { return OP_EQUAL; }
\<=                                 { return OP_LESSEREQUAL; }
\<                                  { return OP_LESSER; }
!=                                  { return OP_DIFFERENT; }
SIN|SINUS|Sin|Sinus|sin|sinus       { return SINUS; }
COS|COSINUS|Cos|Cosinus|cos|cosinus { return COSINUS; }

SI|Si|si                              { return IF; }
SINON|Sinon|sinon                     { return ELSE;  }
FINSI|Finsi|finsi                     { return ENDIF;  }
REPETE|Repete|repete                  { return REPEAT;  }
FINREPETE|FinRepete|finrepete         { return ENDREPEAT; }
TANTQUE|TantQue|Tantque|tantque       { return WHILE;  }
FINTANTQUE|FinTantQue|Tantque|tantque { return ENDWHILE; }

POSITION|Position|position        { return POSITION;  }
TORTUE|Tortue|tortue              { return TURTLE;  }
COULEUR|Couleur|couleur           { return COLOUR;  }
AVANCE|Avance|avance              { return FORWARD;  }
EPAISSEUR|Epaisseur|epaisseur     { return WIDTH;  }
POINT|Point|point                 { return POINT;  }
DELAI|Delai|delai                 { return TIME;  }
ATTENDRE|Attendre|attendre        { return WAIT;  }

INCLINE|Incline|incline                                 { return ROTATE;  }
SAUTIMAGE|SautImage|Sautimage|sautimage|SAUT|Saut|saut  { return FRAMESKIP;  }


[a-zA-Z_]+                        { strcpy(yylval.nom,yytext); return IDENTIFIER; }

\n								{ return '\n'; }
\r								{ return '\n'; }
[ \t]							{ }
.                 { return yytext[0];}
%%
