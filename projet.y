%{
  #include <iostream>
  #include <time.h>
  #include <vector>
  #include <string>
  #include <map>
  #include <math.h>
  #include <utility>
  #include <SDL2/SDL.h>

  #include "numerique.h"
  #include "instruction.h"
  #include "function.h"

  extern FILE *yyin;
  extern int yylex ();
  int yyerror(char *s) { printf("%s\n", s); }

  std::map< std::pair< std::string, unsigned int> , std::pair<unsigned int, std::vector<std::string> > > fonctions;

  std::vector<Instruction> pile = {};
%}

%code requires {
  #include "numerique.h"
  #include <vector>
  #include <string>
}

%union
{
  double valeur;
  char nom[50];
  Numerique * expr;
  std::vector<std::string> * tabNoms;
  std::vector<Numerique *> * tabVals;
}

%token <valeur> NUMBER
%token <nom> IDENTIFIER
%token PI

%token COMMENT
%token BIGCOMMENT

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
%token SINUS
%token COSINUS
%token ARCSINUS
%token ARCCOSINUS
%token SQUAREROOT

%token IF
%token ELSE
%token ENDIF
%token REPEAT
%token ENDREPEAT
%token WHILE
%token ENDWHILE
%token FUNCTION
%token ENDFUNCTION

%token POSITION
%token TURTLE
%token COLOUR
%token ROTATE
%token FORWARD
%token WIDTH
%token POINT
%token TIME
%token WAIT
%token FRAMESKIP

%type <expr> expression
%type <tabNoms> parametresIds
%type <tabVals> parametresNbs

%left OP_OR OP_AND
%left OP_EQUAL OP_LESSER OP_GREATER OP_LESSEREQUAL OP_GREATEREQUAL OP_DIFFERENT
%left OP_PLUS OP_MINUS     /* associativité à gauche */
%left OP_MULTIPLY OP_DIVIDE     /* associativité à gauche */

%%
ligne : ligne instruction '\n'
      | ligne instruction COMMENT '\n'
      | ligne instruction BIGCOMMENT '\n'
      |    /* Epsilon */
      ;

parametresIds : IDENTIFIER {
                  std::vector<std::string> * t = new std::vector<std::string>;
                  t->push_back($1);
                  $$ = t;
                }
              | IDENTIFIER ',' parametresIds {
                  std::vector<std::string> * v = new std::vector<std::string>;
                  v->push_back($1);
                  std::vector<std::string> * v2 = $3;
                  v->insert( v->end(), v2->begin(), v2->end() );
                  $$ = v;
                }
              | /* Pas de parametres */ {
                  std::vector<std::string> * t = new std::vector<std::string>;
                  $$ = t;
                }
              ;

parametresNbs : expression {
                  std::vector<Numerique *> * t = new std::vector<Numerique *>;
                  t->push_back($1);
                  $$ = t;
                }
              | expression ',' parametresNbs {
                  std::vector<Numerique *> * v = new std::vector<Numerique *>;
                  v->push_back($1);
                  std::vector<Numerique *> * v2 = $3;
                  v->insert( v->end(), v2->begin(), v2->end() );
                  $$ = v;
                }
              | /* Pas de parametres */ {
                  std::vector<Numerique *> * t = new std::vector<Numerique *>;
                  $$ = t;
                }
              ;

instruction : expression  {
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
            | WHILE expression {
                pile.push_back(Instruction (IDs::TantQue, {$2}));
              } ligne ENDWHILE {
                pile.push_back(Instruction (IDs::FinTantQue, {}));
              }
            | FUNCTION IDENTIFIER '(' parametresIds ')' {
                std::vector<std::string> * t = $4;
                std::vector<Numerique *> param;
                param.push_back(new Numerique($2));
                param.push_back(new Numerique(t->size()));
                for(int i = 0; i < t->size(); i++){
                  param.push_back(new Numerique( (std::string) t->at(i) ));
                }
                pile.push_back(Instruction (IDs::NouvelleFonction, param));
              } ligne ENDFUNCTION {
                pile.push_back(Instruction (IDs::FinNouvelleFonction, {}));
              }
            | IDENTIFIER '(' parametresNbs ')' {
                std::vector<Numerique *> * t = $3;
                std::vector<Numerique *> param;
                param.push_back(new Numerique($1));
                param.push_back(new Numerique(t->size()));
                for(int i = 0; i < t->size(); i++){
                  param.push_back(t->at(i));
                }
                pile.push_back(Instruction (IDs::Fonction, param));
              }
            | IDENTIFIER '=' expression {
                pile.push_back(Instruction (IDs::VariableSet, {new Numerique($1), $3}));
              }
            |  /* Ligne vide*/
            | POSITION '(' expression ',' expression ')' {
                pile.push_back(Instruction (IDs::Position, {$3, $5}));
              }
            | TURTLE expression {
                pile.push_back(Instruction (IDs::TortueActivation, {$2}));
              }
            | TURTLE '=' expression {
                pile.push_back(Instruction (IDs::TortueImage, {$3}));
              }
            | COLOUR '(' expression ',' expression ',' expression ')' {
                pile.push_back(Instruction (IDs::Couleur, {$3, $5, $7}));
              }
            | ROTATE expression {
                pile.push_back(Instruction (IDs::Inclinaison, {$2}));
              }
            | FORWARD expression {
                pile.push_back(Instruction (IDs::Avancer, {$2}));
              }
            | WIDTH expression {
                pile.push_back(Instruction (IDs::Epaisseur, {$2}));
              }
            | POINT {
                pile.push_back(Instruction (IDs::Point, {}));
              }
            | TIME expression {
                pile.push_back(Instruction (IDs::Delai, {$2}));
              }
            | WAIT expression {
                pile.push_back(Instruction (IDs::Attendre, {$2}));
              }
            | FRAMESKIP expression {
                pile.push_back(Instruction (IDs::SautImage, {$2}));
              }
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
          | expression OP_DIFFERENT expression      { $$ = new Numerique($1, Operateurs::Different, $3); }
          | SINUS '(' expression ')'                { $$ = new Numerique($3, Operateurs::Sinus, NULL); }
          | COSINUS '(' expression ')'              { $$ = new Numerique($3, Operateurs::Cosinus, NULL); }
          | ARCSINUS '(' expression ')'             { $$ = new Numerique($3, Operateurs::ArcSinus, NULL); }
          | ARCCOSINUS '(' expression ')'           { $$ = new Numerique($3, Operateurs::ArcCosinus, NULL); }
          | SQUAREROOT '(' expression ')'           { $$ = new Numerique($3, Operateurs::Racine, NULL); }
          | '(' expression ')'            { $$ = $2; }
          | PI                            { $$ = new Numerique(M_PI); }
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

      case IDs::TantQue: { // Repetition d'instructions tant que X
        int temp = i;
        double tempVerif = params[0]->getNum();
        while(tempVerif){
          i = temp;
          i = execution(stack, i+1);
          tempVerif = params[0]->getNum();
        }
        // Ici nous sommes a un "FinTantQue" donc nous passons simplement a l'instruction suivante
        break;
      }

      case IDs::FinTantQue: { // Instruction Obligatoire apres un "TantQue" !
        return i; // On retourne la position du "FinTantQue" et on revient au bloc d'instruction superieur
        break;
      }

      case IDs::NouvelleFonction: { // Creation d'une fonction
        std::vector<std::string> temp;
        for(int k = 2; k < params.size(); k++){
          temp.push_back(params[k]->getVarName());
        }
        fonctions[std::make_pair ( params[0]->getVarName(), params[1]->getNum() )] = std::make_pair(i+1, temp);
        i++;
        int nbf = 0; // Nombre de "FUNCTION" a l'interieur du bloc de fontion
        while(stack[i].getId() != IDs::FinNouvelleFonction || nbf > 0){
          if(stack[i].getId() == IDs::NouvelleFonction){
            nbf++;
          }else if(stack[i].getId() == IDs::FinNouvelleFonction){
            nbf--;
          }
          i++;
        }
        // Nous sommes a un "FinNouvelleFonction" donc nous passons simplement a l'instruction suivante
        break;
      }

      case IDs::FinNouvelleFonction: { // Instruction Obligatoire apres un "NouvelleFonction" !
        return 0; // On retourne simplement au bloc precedent
        break;
      }

      case IDs::Fonction: { // Appel d'une fonction
        if(fonctions[std::make_pair ( params[0]->getVarName(), params[1]->getNum() )].first == 0){
          std::cout << "Fonction \"" << params[0]->getVarName() << "\" inexistante." << std::endl;
        }else{
          std::vector< std::pair< std::string, double > > temp;
          for(int k = 2; k < params.size(); k++){
            temp.push_back(std::make_pair(fonctions[std::make_pair ( params[0]->getVarName(), params[1]->getNum() )].second[k-2], variables[fonctions[std::make_pair ( params[0]->getVarName(), params[1]->getNum() )].second[k-2]]));
            variables[fonctions[std::make_pair ( params[0]->getVarName(), params[1]->getNum() )].second[k-2]] = params[k]->getNum();
          }
          execution(stack, fonctions[std::make_pair ( params[0]->getVarName(), params[1]->getNum() )].first);
          for(int k = 0; k < temp.size(); k++){
            variables[temp[k].first] = temp[k].second;
          }
        }
        break;
      }

      case IDs::VariableSet: { // Assignation d'une valeur a une variable
        variables[params[0]->getVarName()] = params[1]->getNum();
        break;
      }

      // -------------------- Instructions de la SDL----------------------

      case IDs::Couleur: { // Changement de couleur de dessin
        couleur(params[0]->getNum(), params[1]->getNum(), params[2]->getNum());
        break;
      }
      case IDs::TortueImage: { // Changement de la position de la tortue
        imageTortue(params[0]->getNum());
        break;
      }

      case IDs::TortueActivation: { // Changement de la position de la tortue
        activationTortue(params[0]->getNum());
        break;
      }

      case IDs::Position: { // Changement de la position de la tortue
        position(params[0]->getNum(), params[1]->getNum());
        break;
      }

      case IDs::Inclinaison: { // Inclinaison de la tortue
        incliner(params[0]->getNum());
        break;
      }

      case IDs::Avancer: { // La tortue avance selon son inclinaison
        pixelAvancer(params[0]->getNum());
        break;
      }

      case IDs::Epaisseur: { // On change le rayon du trait de dessin
        rayonTrait(params[0]->getNum());
        break;
      }

      case IDs::Point: { // On change le rayon du trait de dessin
        createPoint();
        break;
      }

      case IDs::Delai: { // Delai entre chaque dessin pour la vitesse d'animation
        tempDelai(params[0]->getNum());
        break;
      }

      case IDs::Attendre: { // Delai entre chaque dessin pour la vitesse d'animation
        SDL_Delay(params[0]->getNum());
        break;
      }

      case IDs::SautImage: { // Delai entre chaque dessin pour la vitesse d'animation
        setFrameSkip(params[0]->getNum());
        break;
      }
    }
  }
}

int main(int argc, char* argv[])
{
  SDL_bool done = SDL_FALSE;
SDL_Event event;


  // Grammaire
  if ( argc > 1 )
  yyin = fopen( argv[1], "r" );
  else
  yyin = stdin;
  yyparse();

  // Creation de la fenetre
  taille_fenetre(1000,1000);

  // On execute les instructions
  execution(pile, 0);

  // On affiche l'etat final (au cas ou nous aurions saute cette frame)
  setFrameSkip(0);
  afficher();


  while (SDL_PollEvent(&event) || !done) {
    if (event.type == SDL_QUIT) {
      done = SDL_TRUE;
    }
  }


  SDL_Quit();
  return 0;
}
