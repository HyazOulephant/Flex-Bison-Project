#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <math.h>
#include "function.h"
using namespace std;

unsigned int winWidth;
unsigned int winHeight;

double x = 0;  //Position X
double y = 0;  //Position Y

int r = 0;  //Rouge
int v = 0;  //Vert
int b = 0;  //Bleu

unsigned int delai = 0; // Temps entre les animations

double inclinaison = 0;  //Inclinaison sur 360 degrees
int epaisseur = 20;  //Rayon du trait

SDL_Renderer* renderer = NULL;
SDL_Window* window = NULL;
SDL_Surface* pSprite  = NULL;
SDL_Texture* drawingTexture = NULL;
SDL_Texture* turtleTexture = NULL;

void couleur(int R,int V,int B){      //Couleur selon Rouge, Vert, Bleu
  r = R%256;  //Depassement
  v = V%256;
  b = B%256;
  SDL_SetRenderDrawColor(renderer, r, v, b, SDL_ALPHA_OPAQUE);  //Application parametres
}

void incliner(double a){
  inclinaison += a;
}

void taille_fenetre(int X, int Y){
  window = SDL_CreateWindow("Turtle Drawing SDL2",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,X,Y, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

  pSprite = SDL_LoadBMP("nyan.bmp");
  turtleTexture = SDL_CreateTextureFromSurface(renderer,pSprite); // Préparation du sprite

  // Texture du dessin
  drawingTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, X, Y);

  //SDL_CreateWindowAndRenderer(X, Y, 0, &window, &renderer);
  couleur(255,255,255);
  SDL_SetRenderTarget(renderer, drawingTexture); // On dessine dans la zone de dessin
  SDL_RenderClear(renderer);

  afficher();
}

void afficher(){
  SDL_SetRenderTarget(renderer, NULL); // On dessine dans la fenetre
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, r, v, b, SDL_ALPHA_OPAQUE);

  SDL_Rect drawingR = { 0,0, 1000, 1000};
  SDL_RenderCopy(renderer,drawingTexture,NULL,&drawingR); // On affiche la texture de la zone de dessin

  SDL_Rect spriteR = { x - (pSprite->w * epaisseur)/512, y - (pSprite->w * epaisseur)/700, (pSprite->w * epaisseur)/256, (pSprite->h * epaisseur)/256};
  SDL_RenderCopyEx(renderer,turtleTexture,NULL,&spriteR,-inclinaison,NULL,SDL_FLIP_NONE); // Copie du sprite grâce au SDL_Renderer

  SDL_RenderPresent(renderer);
  SDL_SetRenderTarget(renderer, drawingTexture); // On dessine dans la zone de dessin
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
