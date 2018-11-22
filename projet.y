%{
  #include <iostream>
  #include <string>
  #include <SDL2/SDL.h>

  extern FILE *yyin;
  extern int yylex ();
  int yyerror(char *s) { printf("%s\n", s); }

  int posx = 0;
  int posy = 0;
%}

%union
{
  double valeur;
}

%token <valeur> NUMBER
%token POSITION
%type <valeur> expression

%left '+' '-'     /* associativité à gauche */
%left '*' '/'     /* associativité à gauche */

%%
ligne : ligne instruction '\n'
      |    /* Epsilon */
      ;
instruction : POSITION '(' expression ',' expression ')' { posx = $3; posy = $5; }
            | expression  { std::cout << $1 << "bing" << std::endl; }
            |  /* Ligne vide*/
            ;
expression: expression '+' expression     { $$ = $1 + $3; }
          | expression '-' expression     { $$ = $1 - $3; }
          | expression '*' expression     { $$ = $1 * $3; }
          | expression '/' expression     { $$ = $1 * $3; }
          | '(' expression ')'            { $$ = $2; }
          | NUMBER                        { $$ = $1; }
          ;
%%
int main(int argc, char **argv) {
  // Creation de la fenetre
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer);

  // Grammaire
  if ( argc > 1 )
    yyin = fopen( argv[1], "r" );
  else
    yyin = stdin;
  yyparse();


  SDL_RenderDrawPoint(renderer, posx, posy);

  // Affichage de la fenetre
  SDL_RenderPresent(renderer);

  // Simulation de PAUSE, entrez n'importe quelle caractere pour quitter le programme
  std::string a;
  std::cin >> a;
}
