%{
  #include <iostream>
  #include <vector>
  #include <string>
  #include <map>
  #include <math.h>
  #include <SDL2/SDL.h>

  #include "numerique.h"
  #include "instruction.h"

  extern FILE *yyin;
  extern int yylex ();
  int yyerror(char *s) { printf("%s\n", s); }

  int posx = 0;
  int posy = 0;

  std::vector<Instruction> pile = {};
%}

%code requires {
  #include "numerique.h"
}

%union
{
  double valeur;
  char nom[50];
  Numerique * expr;
}

%token <valeur> NUMBER
%token <nom> IDENTIFIER

%token OP_PLUS
%token OP_MINUS
%token OP_MULTIPLY
%token OP_DIVIDE
%token OP_OR
%token OP_AND
%token OP_GREATER
%token OP_GREATEREQUAL
%token OP_EQUAL
%token OP_LESSEREQUAL
%token OP_LESSER
%token OP_DIFFERENT

%token POSITION
%token IF
%token ELSE
%token ENDIF
%token REPEAT
%token ENDREPEAT

%type <expr> expression

%left '+' '-'     /* associativité à gauche */
%left '*' '/'     /* associativité à gauche */

%%
ligne : ligne instruction '\n'
      |    /* Epsilon */
      ;

instruction : POSITION '(' expression ',' expression ')' {
                pile.push_back(Instruction (IDs::Position, {$3 ,$5}));
              }
            | expression  {
                pile.push_back(Instruction (IDs::ConsoleEcho, {$1}));
              }
            | IF expression {
                pile.push_back(Instruction (IDs::Si, {$2}));
              } ligne finInstructionSi
            | REPEAT expression {
                pile.push_back(Instruction (IDs::Repete, {$2}));
              } ligne ENDREPEAT {
                pile.push_back(Instruction (IDs::FinRepete, {}));
              }
            | IDENTIFIER '=' expression {
                pile.push_back(Instruction (IDs::VariableSet, {new Numerique($1) ,$3}));
              }
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

expression: expression OP_PLUS expression           { $$ = new Numerique($1, Operateurs::Plus, $3); }
          | expression OP_MINUS expression          { $$ = new Numerique($1, Operateurs::Moins, $3); }
          | expression OP_MULTIPLY expression       { $$ = new Numerique($1, Operateurs::Fois, $3); }
          | expression OP_DIVIDE expression         { $$ = new Numerique($1, Operateurs::Divise, $3); }
          | expression OP_OR expression             { $$ = new Numerique($1, Operateurs::Ou, $3); }
          | expression OP_AND expression            { $$ = new Numerique($1, Operateurs::Et, $3); }
          | expression OP_GREATER expression        { $$ = new Numerique($1, Operateurs::Superieur, $3); }
          | expression OP_GREATEREQUAL expression   { $$ = new Numerique($1, Operateurs::SuperieurEgal, $3); }
          | expression OP_EQUAL expression          { $$ = new Numerique($1, Operateurs::Egal, $3); }
          | expression OP_LESSEREQUAL expression    { $$ = new Numerique($1, Operateurs::InferieurEgal, $3); }
          | expression OP_LESSER expression         { $$ = new Numerique($1, Operateurs::Inferieur, $3); }
          | expression OP_DIFFERENT expression            { $$ = new Numerique($1, Operateurs::Different, $3); }
          | '(' expression ')'            { $$ = $2; }
          | NUMBER                        { $$ = new Numerique($1); }
          | IDENTIFIER                    { $$ = new Numerique($1); }
          ;
%%


unsigned int execution(std::vector<Instruction> stack, unsigned int iter){ // Programme d'execution finale
  for(int i = iter; i < stack.size(); i++){
    std::vector<Numerique *> params = stack[i].getParametres();
    IDs id = stack[i].getId();
    switch(id){
      case IDs::Rien: { // Ne fait rien... utile au deboquage
        // std::cout << "ATTENTION Il n'y a rien ici!" << std::endl;
        break;
      }

      case IDs::ConsoleEcho: { // Affiche une donnee dans la console
        std::cout << params[0]->getNum() << std::endl;
        break;
      }

      case IDs::Position: { // Applique une nouvelle position
        posx = params[0]->getNum(); posy = params[1]->getNum();
        break;
      }

      case IDs::Si: { // Condition Si
        if(params[0]->getNum()){
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
        break;
      }

      case IDs::FinSi: { // Instruction Obligatoire apres un "Si" !
        return i; // On retourne la position du "FinSi" et on revient au bloc d'instruction superieur
        break;
      }

      case IDs::Sinon: { // Instruction Obligatoire apres un "Si" !
        // Si nous tombons sur cette instruction alors c'est que nous sommes deja dans le bloc du "Si", auquel cas le bloc du sinon est evite
        return i; // On retourne la position du "Sinon" et le "Si" s'occupe de l'eviter
        break;
      }

      case IDs::Repete: { // Repetition d'instructions
        int temp = i;
        for(int j = 0; j < params[0]->getNum(); j++){
          i = temp;
          i = execution(stack, i+1);
        }
        // Ici nous sommes a un "FinRepete" donc nous passons simplement a l'instruction suivante
        break;
      }

      case IDs::FinRepete: { // Instruction Obligatoire apres un "Repete" !
        return i; // On retourne la position du "FinRepete" et on revient au bloc d'instruction superieur
        break;
      }

      case IDs::VariableSet: { // Assignation d'une valeur a une variable
        variables[params[0]->getVarName()] = params[1]->getNum();
        break;
      }
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
  std::cout << cos(M_PI) << std::endl;
  // On entre un caractere pour fermer la fenetre
  std::string a;
  std::cin >> a;
}
