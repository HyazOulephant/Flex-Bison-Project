#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include "function.h"
using namespace std;

int x = 0;  //Position X
int y = 0;  //Position Y
int r = 0;  //Rouge
int v = 0;  //Vert
int b = 0;  //Bleu
int inclinaison = 0;  //Inclinaison sur 360
SDL_Renderer* renderer = NULL;
SDL_Window* window = NULL;



void couleur(int R,int V,int B){      //Couleur selon Rouge, Vert, Bleu
  r = R%256;  //Depassement
  v = V%256;
  b = B%256;
  SDL_SetRenderDrawColor(renderer, r, v, b, SDL_ALPHA_OPAQUE);  //Application parametres
}

void incliner(int a){
  inclinaison += a%360;
}

void taille_fenetre(int X, int Y){
  SDL_CreateWindowAndRenderer(X, Y, 0, &window, &renderer);
  SDL_SetRenderDrawColor(renderer, r, v, b, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

void afficher(){
  SDL_RenderPresent(renderer);
}

void position(int X, int Y){    //Postion x et y
  x = X;
  y = Y;
}

/*                  #####################################
                    #             DROITES               #
                    #####################################
*/
void droite(int a){
  SDL_RenderDrawLine(renderer, x, y, x+a, y);                          //Draw line from:to
  x += a;
}
void gauche(int a){
  SDL_RenderDrawLine(renderer, x, y, x-a, y);                          //Draw line from:to
  x -= a;
}
void haut(int a){
  SDL_RenderDrawLine(renderer, x, y, x, y-a);                          //Draw line from:to
  y -= a;
}
void bas(int a){
  SDL_RenderDrawLine(renderer, x, y, x, y+a);                          //Draw line from:to
  y += a;
}
void ligne_par_coordonnes(int a,int b){
  SDL_RenderDrawLine(renderer, x, y, x+a, y+b);                          //Draw line from:to
  x += a;
  y += b;
}
void ligne_par_coordonnee_absolue(int a,int b){
  SDL_RenderDrawLine(renderer, x, y, a, b);                          //Draw line from:to
  x = a;
  y = b;
}
