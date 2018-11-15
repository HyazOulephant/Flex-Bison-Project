%option noyywrap
%{
#include <string>
#include <iostream>
#include "projet.bison.hpp"
using namespace std;
%}
%%
[0-9]+(\.[0-9]*)?([Ee][0-9]+)?	{ yylval.valeur = atof(yytext); return NUMBER; }


(plus|\+)	{  return '*'; }
(fois|\*)	{  return '*'; }
(moins|\-)	{  return '-'; }
(divise|\/) {  return '/'; }

[A-Za-z_][0-9A-Za-z_]*   { strcpy(yylval.nom,yytext); return IDENTIFIER; }

\n								{  return '\n'; }
\r								{  return '\n'; }
[ \t]							{ }
.								{  return yytext[0]; }
%%
int main(){
  yylex();
}

