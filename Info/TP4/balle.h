#ifndef BALLE_H
#define BALLE_H

#include <Imagine/Graphics.h>
using namespace Imagine;
#include "vector.h"
#include "tools.h"

struct Balle{ // Structure de la balle
    vect centre;
    vect centreOld;
    vect speed;
    int radius;
    double mass;
    Color col;
};

void Choc(Balle &B1, Balle &B2); // Surcharge du choc avec la structures Balle

void ChocSimple(Balle &B, Balle S); // Surcharge du choc simple avec la structures Balle

bool Collision(Balle B1, Balle B2); // Surcharge de Collision pour prendre en compte la structure Balle

void AfficheBalle(Balle D); // Affichage de la balle

void EffaceBalle(Balle D); // Effacage de la balle

void BougeBalle(Balle soleils[], int balle, int length, double dt); // Déplacement de la balle
void BougeBalle(Balle soleils[], int balle, int length, double dt, int JActif); // Déplacement de la balle POUR LE DUEL

void Accel(Balle &D, vect a, double dt); // Intégration de l'accélération de la balle par methode d'Euler

vect grav(Balle soleils[], int balle, int length, double G); // Détermination du vecteur accéleration
vect grav(Balle soleils[], int balle, int length, double G, int JActif); // Détermination du vecteur accéleration POUR LE DUEL

vect RandVectLoc(int r, int largeur, int hauteur);

Balle InitBalle(int largeur, int hauteur);

Balle InitSoleils(Balle balles[], int start, int end, int largeur, int hauteur, double rSoleilsMin, double rSoleilsMax); // Initialisation aléatoire des nbSoleils soleis, sans collisions
Balle InitSoleilsDuel(Balle balles[], int start, int end, int largeur, int hauteur, double rSoleilsMin, double rSoleilsMax); // Initialisation aléatoire des nbSoleils soleis, sans collisions POUR LE DUEL

#endif // BALLE_H
