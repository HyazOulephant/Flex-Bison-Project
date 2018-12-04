#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <iostream>
#include <string>
//#include "function.h"
using namespace std;

int x = 0;  //Position X
int y = 0;  //Position Y
int r = 0;  //Rouge
int v = 0;  //Vert
int b = 0;  //Bleu
int ep = 1;  //Epaisseur
int angle = 0;  //Inclinaison sur 360
int ray = 0;    //Rayon
const char *mot = NULL;
SDL_Renderer* renderer = NULL;
SDL_Window* window = NULL;



void couleur(int R,int V,int B){      //Couleur selon Rouge, Vert, Bleu
  r = R%256;  //Depassement
  v = V%256;
  b = B%256;
  SDL_SetRenderDrawColor(renderer, r, v, b, SDL_ALPHA_OPAQUE);  //Application parametres
  std::cout << r<<v<<b << std::endl;
}

void incliner(int a){
  angle += a%360;
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

void epaisseur(int a){ep = a;}

void rayon(int a){ray = a;}

/*                  #####################################
                    #             DROITES               #
                    #####################################
*/
void droite(int a){
  thickLineRGBA (renderer, x, y, x+a, y, ep,  r, v,b, SDL_ALPHA_OPAQUE);   //Draw line from:to
  x += a;
}
void gauche(int a){
  thickLineRGBA (renderer, x, y, x-a, y, ep,  r, v,b, SDL_ALPHA_OPAQUE);   //Draw line from:to
  x -= a;
}
void haut(int a){
  thickLineRGBA (renderer, x, y, x, y-a, ep,  r, v,b, SDL_ALPHA_OPAQUE);   //Draw line from:to
  y -= a;
}
void bas(int a){
  thickLineRGBA (renderer, x, y, x, y+a, ep,  r, v,b, SDL_ALPHA_OPAQUE);   //Draw line from:to
  y += a;
}
void ligne_par_coordonnes(int a,int b){
  thickLineRGBA (renderer, x, y, x+a, y+b, ep,  r, v,b, SDL_ALPHA_OPAQUE);   //Draw line from:to
  x += a;
  y += b;
}

void ligne_par_coordonnee_absolue(int a,int b){
  thickLineRGBA (renderer, x, y, a, b, ep,  r, v,b, SDL_ALPHA_OPAQUE);   //Draw line from:to
  x = a;
  y = b;
}

/*                  #####################################
                    #              FORMES               #
                    #####################################
*/

void ecrire_mot(const char *a){
  cout << a <<endl;
  mot = a;
  stringRGBA(renderer,x,y,mot,r,v,b,SDL_ALPHA_OPAQUE);
}

void rectangle_plein(int a, int b){
  boxRGBA(renderer,x, y, x+a, y+b, r, v, b, SDL_ALPHA_OPAQUE);
}

void rectangle_plein_absolue(int a, int b){
  boxRGBA(renderer,x, y, a, b, r, v, b, SDL_ALPHA_OPAQUE);
}

void rectangle_plein_arrondi(int a, int b){
  roundedBoxRGBA (renderer, x, y, x+a, y+b, angle, r, v, b, SDL_ALPHA_OPAQUE);
}

void rectangle_plein_arrondi_absolue(int a, int b){
  roundedBoxRGBA (renderer, x, y, a, b, angle, r, v, b, SDL_ALPHA_OPAQUE);
}
