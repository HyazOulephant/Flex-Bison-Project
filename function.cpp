#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <math.h>
#include "function.h"
using namespace std;

float x = 0;  //Position X
float y = 0;  //Position Y

int r = 0;  //Rouge
int v = 0;  //Vert
int b = 0;  //Bleu

unsigned int delai = 5; // Temps entre les animations

int inclinaison = 0;  //Inclinaison sur 360 degrees
int epaisseur = 5;  //Rayon du trait

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
  couleur(255,255,255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

void afficher(){
  SDL_RenderPresent(renderer);
}

void position(int X, int Y){    //Position x et y
  x = X;
  y = Y;
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
    std::cout << distance << " trist" << std::endl;
    afficher();
    SDL_Delay(delai);
  }

  /*
  if(fabs(Fx) > fabs(Fy)){
    for(int i = 0; i < fabs(Fx); i++){
      circle(epaisseur, x + i * fabs(Fx)/Fx, y + i * (fabs(Fy/Fx)) * fabs(Fy)/Fy);
      SDL_Delay(delai);

      afficher();
    }
  }else{
    for(int i = 0; i < fabs(Fy); i++){
      circle(epaisseur, x + i * (fabs(Fx/Fy)) * fabs(Fx)/Fx, y + i * fabs(Fy)/Fy);
      SDL_Delay(delai);

      afficher();
    }
  }
  */
  x += Fx;
  y += Fy;
}

/*                  #####################################
                    #              FORMES               #
                    #####################################
*/

void circle(int r, float xi, float yi){
  for(int i = 0; i < r; i++){
    for(float th = 0; th < M_PI*2*r; th++){
      SDL_RenderDrawPoint(renderer, xi + cos(th/r) * i, yi + sin(th/r) * i);
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
