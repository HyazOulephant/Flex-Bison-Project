#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <math.h>
#include "function.h"
using namespace std;

double x = 0;  //Position X
double y = 0;  //Position Y

int r = 0;  //Rouge
int v = 0;  //Vert
int b = 0;  //Bleu

unsigned int delai = 0; // Temps entre les animations

int inclinaison = 0;  //Inclinaison sur 360 degrees
int epaisseur = 20;  //Rayon du trait

SDL_Renderer* renderer = NULL;
SDL_Window* window = NULL;
SDL_Renderer *pRenderer = NULL;
SDL_Surface* pSprite  = NULL;
SDL_Texture* pTexture = NULL;

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
  window = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1000,1000, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

  //SDL_CreateWindowAndRenderer(X, Y, 0, &window, &renderer);
  couleur(255,255,255);
  SDL_RenderClear(renderer);

  pSprite = SDL_LoadBMP("T.bmp");

  pTexture = SDL_CreateTextureFromSurface(renderer,pSprite); // Préparation du sprite

  SDL_Rect dest = { 640/4 - pSprite->w/4,480/4 - pSprite->h/4, pSprite->w/4, pSprite->h/4};
  SDL_RenderCopy(renderer,pTexture,NULL,&dest); // Copie du sprite grâce au SDL_Renderer

  SDL_RenderPresent(renderer); // Affichage
  SDL_Delay(1000);
}

void afficher(){
  SDL_RenderPresent(renderer);
}

void position(int X, int Y){    //Position x et y
  x = X;
  y = Y;
}

void rayonTrait(int X){    // Epaisseur du trait
  epaisseur = X;
}

void tempDelai(int X){    // Delai entre chaque pixel dessine
  delai = X;
}

/*                  ########################################
                    #             ANIMATIONS               #
                    ########################################
*/
void pixelAvancer(unsigned int distance){
  // Distances du Point d'arrive
  float Fx = cos((float)inclinaison * M_PI / 180) * distance;
  float Fy = 0 - sin((float)inclinaison * M_PI / 180) * distance;

  for(unsigned int i = 0; i < distance; i++){
    circle(epaisseur, x + cos((float)inclinaison * M_PI / 180) * i, y - sin((float)inclinaison * M_PI / 180) * i);
    x += cos((float)inclinaison * M_PI / 180);
    y -= sin((float)inclinaison * M_PI / 180);
    afficher();

    SDL_Delay(delai);
  }
  SDL_Rect dest = { x,y, pSprite->w/4, pSprite->h/4};
  SDL_RenderCopy(renderer,pTexture,NULL,&dest); // Copie du sprite grâce au SDL_Renderer

}

/*                  #####################################
                    #              FORMES               #
                    #####################################
*/

void circle(int r, float xi, float yi){
  for(int i = 0; i < r; i++){
    for(float th = 0; th < M_PI*2*i; th++){
      SDL_RenderDrawPoint(renderer, xi + cos(th/i) * i, yi + sin(th/i) * i);
    }
  }
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
