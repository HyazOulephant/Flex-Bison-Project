#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

int x = 0;  //Position X
int y = 0;  //Position Y
int r = 0;  //Rouge
int v = 0;  //Vert
int b = 0;  //Bleu
int inclinaison = 0;  //Inclinaison sur 360
SDL_Renderer* renderer = NULL;



void couleur(int R,int V,int B){      //Couleur selon Rouge, Vert, Bleu
  if ((R > -1) | (R < 256)) {
    r = R;
  }
  if ((V > -1) | (V < 256)) {
    v = V;
  }
  if ((B > -1) | (B < 256)) {
    b = B;
  }
  else{cout << "Limite couleur depassee" << endl;}
  SDL_SetRenderDrawColor(renderer, r, v, b, SDL_ALPHA_OPAQUE);  //Application parametres
}

void incliner(int a){
  if ((a <= 360)|(a >= 0)) {
    inclinaison = a;
  }
  else{cout << "Inclinaison depassee" << endl;}
}

void position(int X, int Y, int INCLINAISON = 0){    //Postion x et y
  x = X;
  y = Y;
  incliner(INCLINAISON);

}



/*                  ####################################
                    #             DOITES               #
                    ####################################
*/
void droite(int a){
  SDL_RenderDrawLine(renderer, x, y, a, y);                          //Draw line from:to
}
void gauche(int a){
  SDL_RenderDrawLine(renderer, x, y, -a, y);                          //Draw line from:to
}
void haut(int a){
  SDL_RenderDrawLine(renderer, x, y, x, a);                          //Draw line from:to
}
void bas(int a){
  SDL_RenderDrawLine(renderer, x, y, x, -a);                          //Draw line from:to
}
void ligne_par_coordonnes(int a,int b){
  SDL_RenderDrawLine(renderer, x, y, a, b);                          //Draw line from:to
}















int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Window* window = NULL;


        if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0) {
            SDL_bool done = SDL_FALSE;

            while (!done) {
                SDL_Event event;

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);               //Set_Color
                SDL_RenderClear(renderer);                                                 //Apply Set_Color on font

                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);         //Set_Color
                SDL_RenderDrawLine(renderer, 100, 100, 480, 640);                          //Draw line from:to
                SDL_RenderPresent(renderer);                                               //Apply Set_Color on line

                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        done = SDL_TRUE;
                    }
                }
            }
        }

        if (renderer) {
            SDL_DestroyRenderer(renderer);
        }
        if (window) {
            SDL_DestroyWindow(window);
        }
    }
    SDL_Quit();
    return 0;
}
