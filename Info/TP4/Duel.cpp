// Imagine++ project
// Project:  Tp4_Initial
// Author:   keriven
// Date:     2007/10/23

#include <Imagine/Graphics.h>
using namespace Imagine;

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

#include "tools.h"
#include "vector.h"
#include "balle.h"

const int largeur = 512;
const int hauteur = 512;
const int pasdaff = 500;
const double dt = 0.1;
const double G = 1;

// Config soleils
const int nbSoleils = 5;
const int rSoleilsMin = 5;
const int rSoleilsMax = 15;

// Config Joueurs
const int rJ1 = 10; // Rayon des balles des joueurs
const int rJ2 = 10;


////////////////////////////////////////////////
///
///  Fonctions

vect GetMouse(){ // Renvoie le vecteur correspondant au clic souris
    int x,y;
    getMouse(x,y);
    vect p ={double(x),double(y)};
    return p;

}

Balle TirJoueur(Balle J){
    Balle tir;
    tir = J;
    tir.speed = (GetMouse()-J.centre)*0.0005;
    tir.radius = 2;
    tir.col = BLACK;
    tir.mass = 0.1;
    return tir;
}

bool BouclePrinipale(Balle soleils[], int length, int JActif, int cible){ // Gère l'affichage, les déplacement et les conditions de victoire
    //Initialistion du booleen
    bool touche = false;

    int tir = length-1; //dernier indice

    //****** Acquisition du tir ******
    soleils[tir] = TirJoueur(soleils[JActif]);

    //****** Boucle principale ******
    for (int temps=0;temps<250*pasdaff;temps++) {
        //******** Affichage ************
        if ((temps%pasdaff)==0){
            noRefreshBegin();
            EffaceBalle(soleils[tir]);
            AfficheBalle(soleils[JActif]); // La balle part du joueur actif, on asssure l'intégrité visuelle
            AfficheBalle(soleils[tir]);
            soleils[tir].centreOld=soleils[tir].centre;
            noRefreshEnd();
            milliSleep(50);
        }
        //***** Intégrations successives ******
        Accel( soleils[tir], grav(soleils,tir,length,G,JActif),dt);
        BougeBalle(soleils,tir,length,dt,JActif);
        //****** Test de colision cible ******
        touche = Collision(soleils[tir],soleils[cible]);
        if (touche){
            EffaceBalle(soleils[tir]);
            return true;
        }
    }
    EffaceBalle(soleils[tir]);
    return false;
}

/////////////////////////////////////////////
///
/// Configuration initiales
void initJoueurs(Balle soleils[]){
    Balle J1 = {{largeur/8,   hauteur/2}, {largeur/8,   hauteur/2}, {0,0}, rJ1, 0, BLUE},
          J2 = {{7*largeur/8, hauteur/2}, {7*largeur/8, hauteur/2}, {0,0}, rJ2, 0, GREEN};
    soleils[0]=J1;
    soleils[1]=J2;
}

void initSoleilCentral(Balle soleils[]){
    Balle soleilCentral={{largeur/2, hauteur/2}, {largeur/2, hauteur/2}, {0,0}, 40, 2, YELLOW};
    soleils[2]=soleilCentral;
}



/////////////////////////////////////////////
int main()
{
    openWindow(largeur, hauteur);
	InitRandom();

	//****************** INITIALISATION *******************
    Balle soleils[nbSoleils+4];
    initJoueurs(soleils);
    initSoleilCentral(soleils);
    InitSoleilsDuel(soleils,3,nbSoleils+3,largeur,hauteur,rSoleilsMin,rSoleilsMax);


    //****** Affichage des soleils et cibles ******
    for(int i=0;i<nbSoleils+3;i++){
        AfficheBalle(soleils[i]);
    }

    // Tours des joueurs
    bool victoire = false;
    while (victoire==false){
        // Joueur 1
        if (BouclePrinipale(soleils,nbSoleils+4,0,1)){
            cout<< "Le joueur 1 a gagne"<<endl;
            break;
        }
        // Joueur 2
        if (BouclePrinipale(soleils,nbSoleils+4,1,0)){
            cout<< "Le joueur 2 a gagne"<<endl;
            break;
        }

    }
    endGraphics();
    return 0;
}
