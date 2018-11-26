%{
  #include <iostream>
  #include <vector>
  #include <SDL2/SDL.h>

  #include "instruction.h"

  extern FILE *yyin;
  extern int yylex ();
  int yyerror(char *s) { printf("%s\n", s); }

  int posx = 0;
  int posy = 0;

  std::vector<Instruction> pile = {};

%}

%union
{
  double valeur;
}

%token <valeur> NUMBER
%token POSITION
%token IF
%token ELSE
%token ENDIF

%type <valeur> expression

%left '+' '-'     /* associativité à gauche */
%left '*' '/'     /* associativité à gauche */

%%
ligne : ligne instruction '\n'
      |    /* Epsilon */
      ;

instruction : POSITION '(' expression ',' expression ')' {
                pile.push_back(Instruction (IDs::Position, {$3,$5}));
              }
            | expression  { std::cout << $1 << " bing" << std::endl; }
            | IF expression {
                pile.push_back(Instruction (IDs::Si, {$2}));
              }
              ligne finInstructionSi
            |  /* Ligne vide*/
            ;

finInstructionSi: ENDIF {
                    pile.push_back(Instruction (IDs::FinSi, {}));
                  }
                | ELSE {
                    pile.push_back(Instruction (IDs::Sinon, {}));
                  } ligne ENDIF {
                    pile.push_back(Instruction (IDs::FinSi, {}));
                  }
                ;

expression: expression '+' expression     { $$ = $1 + $3; }
          | expression '-' expression     { $$ = $1 - $3; }
          | expression '*' expression     { $$ = $1 * $3; }
          | expression '/' expression     { $$ = $1 * $3; }
          | '(' expression ')'            { $$ = $2; }
          | NUMBER                        { $$ = $1; }
          ;
%%


unsigned int execution(std::vector<Instruction> stack, unsigned int iter){ // Programme d'execution finale
  for(int i = iter; i < stack.size(); i++){
    std::vector<int> params = stack[i].getParametres();
    IDs id = stack[i].getId();
    switch(id){
      case IDs::Rien: // Ne fait rien... utile au deboquage
        // std::cout << "ATTENTION Il n'y a rien ici!" << std::endl;
        break;

      case IDs::Position: // Applique une nouvelle position
        posx = params[0]; posy = params[1];
        break;

      case IDs::Si: // Condition Si
        if(params[0]){
          i = execution(stack, i+1);

          if(stack[i].getId() == IDs::Sinon){ // Si nous avons un "Sinon", nous evitons son bloc d'instructions
            i++;
            int nbsi = 0; // Nombre de "SI" a l'interieur du bloc conditionnel
            while(stack[i].getId() != IDs::FinSi || nbsi > 0){
              if(stack[i].getId() == IDs::Si){
                nbsi++;
              }else if(stack[i].getId() == IDs::FinSi){
                nbsi--;
              }
              i++;
            }
          }
        }else{
          i++;
          int nbsi = 0; // Nombre de "SI" a l'interieur du bloc conditionnel
          while( (stack[i].getId() != IDs::FinSi && stack[i].getId() != IDs::Sinon) || nbsi > 0){
            if(stack[i].getId() == IDs::Si){
              nbsi++;
            }else if(stack[i].getId() == IDs::FinSi){
              nbsi--;
            }
            i++;
          }

          if(stack[i].getId() == IDs::Sinon){ // Si nous avons un "Sinon" nous appliquons son bloc d'instructions
            i = execution(stack, i+1);
          }
        }
        // Ici nous sommes a un "FinSi" donc nous passons simplement a l'instruction suivante
        i++;
        break;

      case IDs::FinSi: // Instruction Obligatoire apres un "Si" !
        return i; // On retourne la position du "FinSi" et on revient au bloc d'instruction superieur
        break;

      case IDs::Sinon: // Instruction Obligatoire apres un "Si" !
        // Si nous tombons sur cette instruction alors c'est que nous sommes deja dans le bloc du "Si", auquel cas le bloc du sinon est evite
        return i; // On retourne la position du "Sinon" et le "Si" s'occupe de l'eviter
        break;
    }
  }
}

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

  // On execute les instructions
  execution(pile, 0);


  SDL_RenderDrawPoint(renderer, posx, posy);

  // Affichage de la fenetre
  SDL_RenderPresent(renderer);

  // On entre un caractere pour fermer la fenetre
  std::string a;
  std::cin >> a;
}
