#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

double x = 0;  //Position X
double y = 0;  //Position Y
double r = 0;  //Rouge
double v = 0;  //Vert
double b = 0;  //Bleu
double inclinaison = 0;  //Inclinaison sur 360
SDL_Renderer* renderer = NULL;



void couleur(int R,int V,int B){      //Couleur selon Rouge, Vert, Bleu
  r = R%256;  //Depassement
  v = V%256;
  b = B%256;
  SDL_SetRenderDrawColor(renderer, r, v, b, SDL_ALPHA_OPAQUE);  //Application parametres
}

void incliner(int a){
  inclinaison += a%360;
}

void position(int X, int Y, int INCLINAISON = inclinaison){    //Postion x et y
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

