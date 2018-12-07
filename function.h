#ifndef FUNCTION_H
#define FUNCTION_H

void couleur(int R,int V,int B);

void incliner(double a);
void pixelAvancer(unsigned int distance);

void taille_fenetre(int X, int Y);
void afficher();

void position(int X, int Y);

void rayonTrait(int X);    // Epaisseur du trait

void tempDelai(int X);    // Delai entre chaque pixel dessine

void circle(int r, float xi, float yi);
#endif
