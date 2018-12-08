#ifndef FUNCTION_H
#define FUNCTION_H


void taille_fenetre(int X, int Y);
void afficher();

void position(int X, int Y);

void imageTortue(unsigned int id);
void activationTortue(bool estActive);

void couleur(int R,int V,int B);

void incliner(double a);

void rayonTrait(int X);    // Epaisseur du trait

void tempDelai(int X);    // Delai entre chaque pixel dessine

void setFrameSkip(int f);

void pixelAvancer(unsigned int distance);

void circle(int r, float xi, float yi);
#endif
