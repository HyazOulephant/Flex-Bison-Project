#include <SDL2/SDL.h>
#include <string>
#include <math.h>
#include "function.h"

// Sources pour debugging
#include <iostream>
#include <time.h>

using namespace std;

unsigned int winWidth;
unsigned int winHeight;

int frameSkip = 5; // Nombre de frames que l'on saute (accelere l'execution)
unsigned int counter = 0;
unsigned int delai = 0; // Temps entre les animations

bool tortueAffichage = 1;
bool tortueActive = 1;

double x = 0;  //Position X
double y = 0;  //Position Y

int r = 0;  //Rouge
int v = 0;  //Vert
int b = 0;  //Bleu


double inclinaison = 0;  //Inclinaison sur 360 degrees
int epaisseur = 20;  //Rayon du trait

SDL_Renderer* renderer = NULL;
SDL_Window* window = NULL;
SDL_Surface* pSprite  = NULL;
SDL_Texture* drawingTexture = NULL;
SDL_Texture* turtleTexture = NULL;

int nb_frame_sprite = 1;
float frame_sprite = 0;

void taille_fenetre(int X, int Y){
  winWidth = X;
  winHeight = Y;

  window = SDL_CreateWindow("Turtle Drawing SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, winWidth, winHeight, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

  pSprite = SDL_LoadBMP("turtles/pinceau.bmp");
  turtleTexture = SDL_CreateTextureFromSurface(renderer,pSprite); // Préparation du sprite

  // Texture du dessin
  drawingTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, winWidth, winHeight);

  couleur(255,255,255);
  SDL_SetRenderTarget(renderer, drawingTexture); // On dessine dans la zone de dessin
  SDL_RenderClear(renderer);
  couleur(0,0,0);

  afficher();
}

void afficher(){
  if(counter >= frameSkip){
    counter = 0;

    SDL_SetRenderTarget(renderer, NULL); // On dessine dans la fenetre
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, r, v, b, SDL_ALPHA_OPAQUE);

    SDL_Rect drawingR = { 0,0, winWidth, winHeight};
    SDL_RenderCopy(renderer,drawingTexture,NULL,&drawingR); // On affiche la texture de la zone de dessin

    if(tortueAffichage){
      frame_sprite+=0.1;
      if(frame_sprite >= nb_frame_sprite){
        frame_sprite = 0;
      }
      SDL_Rect spriteR = { x - 2 * epaisseur * (pSprite->w / nb_frame_sprite) / pSprite->h, y - 2 * epaisseur, 4 * epaisseur * (pSprite->w / nb_frame_sprite) / pSprite->h, 4 * epaisseur};
      SDL_Rect spriteS = {0 + floor(frame_sprite) * pSprite->w / nb_frame_sprite, 0, pSprite->w / nb_frame_sprite, pSprite->h};
      SDL_RenderCopyEx(renderer,turtleTexture,&spriteS,&spriteR,-inclinaison,NULL,SDL_FLIP_NONE); // Copie du sprite grâce au SDL_Renderer

    }

    SDL_RenderPresent(renderer);

    SDL_SetRenderTarget(renderer, drawingTexture); // On dessine dans la zone de dessin
  }else{
    counter++;
  }
}

void position(int X, int Y){    //Position x et y
  x = X;
  y = Y;
}

void imageTortue(unsigned int id){
  tortueAffichage = id;
  switch(id){
    // case 0:  break; // Quand l'id vaut 0, nous n'affichons pas l'image

    case 1: {
      pSprite = SDL_LoadBMP("turtles/pinceau.bmp");
      nb_frame_sprite = 1;
      break;
    }

    case 2: {
      pSprite = SDL_LoadBMP("turtles/isen.bmp");
      nb_frame_sprite = 1;
      break;
    }

    case 3: {
      pSprite = SDL_LoadBMP("turtles/NYAN2.bmp");
      nb_frame_sprite = 8;
      break;
    }

    case 4: {
      pSprite = SDL_LoadBMP("turtles/carapace_bleue.bmp");
      nb_frame_sprite = 1;
      break;
    }

    case 5: {
      pSprite = SDL_LoadBMP("turtles/terre.bmp");
      nb_frame_sprite = 1;
      break;
    }
  }
  frame_sprite = 0;
  turtleTexture = SDL_CreateTextureFromSurface(renderer,pSprite);
}

void activationTortue(bool estActive){ // Activer/Desactiver le dessin de la tortue
  tortueActive = estActive;
}

void couleur(int R,int V,int B){      //Couleur selon Rouge, Vert, Bleu
  r = R%256;  //Depassement
  v = V%256;
  b = B%256;
  SDL_SetRenderDrawColor(renderer, r, v, b, SDL_ALPHA_OPAQUE);  //Application parametres
}

void rayonTrait(int X){    // Epaisseur du trait
  epaisseur = X;
}

void createPoint(){    // Cree un point
  circle(epaisseur, x, y);
  afficher();
}

void tempDelai(int X){    // Delai entre chaque pixel dessine
  delai = X;
}

void setFrameSkip(int f){
  frameSkip = f;
}

/*                  ########################################
                    #             ANIMATIONS               #
                    ########################################
*/

void incliner(double a){
  if(a < 1){ // On evite la boucle for si on incline de moins de 1
    inclinaison += a;
    afficher();
    SDL_Delay(delai);
  }else{
    for(int i = 0; i < floor(a); i++){
      inclinaison += a/floor(a);
      afficher();
      SDL_Delay(delai);
    }
  }
}

void pixelAvancer(double distance){
  if(distance < 1){ // On evite la boucle for si on avance de moins de 1
    x += cos((float)inclinaison * M_PI / 180) * distance;
    y -= sin((float)inclinaison * M_PI / 180) * distance;
    circle(epaisseur, x, y);
    afficher();

    SDL_Delay(delai);
  }else{
    for(unsigned int i = 0; i < floor(distance); i++){
      x += cos((float)inclinaison * M_PI / 180) * distance/floor(distance);
      y -= sin((float)inclinaison * M_PI / 180) * distance/floor(distance);
      circle(epaisseur, x, y);
      afficher();

      SDL_Delay(delai);
    }
  }
}

/*                  #####################################
                    #              FORMES               #
                    #####################################
*/

void circle(int r, float xi, float yi){
  if(tortueActive){
    /*for(int i = 0; i < r; i++){ // MODE POLAIRE
      for(float th = 0; th < M_PI*4*i; th++){
        SDL_RenderDrawPoint(renderer, xi + cos(th/i) * i, yi + sin(th/i) * i);
      }
    }*/
    for(int i = xi-r; i < xi+r+1; i++){ // MODE CARTESIEN
      for(int j = yi-r; j < yi+r+1; j++){
        if((i-xi)*(i-xi) + (j-yi)*(j-yi) <= r*r) SDL_RenderDrawPoint(renderer, i, j);
      }
    }
  }
}
