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
const int pasdaff = 100;
const double dt = 0.1;
const double G = 5;

const int nbSoleils = 10;
const int rSoleilsMin = 5;
const int rSoleilsMax = 15;

////////////////////////////////////////////////
///
///  Fonctions

void BougeToutesBalle(Balle soleils[], int length, double dt){ // Déplacement de la balle

    for(int i=1;i<length;i++){// test de collision pour chaque soleil
        for(int j=0;j<i;j++){
            if (Collision(soleils[i],soleils[j])){
                Choc(soleils[i],soleils[j]);
            }
        }
    }
    for(int i=0;i<length;i++){
        soleils[i].centre = soleils[i].centre + soleils[i].speed*dt;
    }
}

/////////////////////////////////////////////
int main()
{
    //openWindow(largeur, hauteur);
	InitRandom();

	//****************** INITIALISATION *******************
    Balle soleils[nbSoleils];
    InitSoleils(soleils,0, nbSoleils, largeur, hauteur, rSoleilsMin, rSoleilsMax);

    openWindow(largeur, hauteur);


	//****** Boucle principale ******
	for (int temps=0;temps<10000*pasdaff;temps++) {
		//******** Affichage ************
		if ((temps%pasdaff)==0){
			noRefreshBegin();
            for(int i=0;i<nbSoleils;i++){ //****** Affichage des soleils ******
                EffaceBalle(soleils[i]);
                AfficheBalle(soleils[i]);
                soleils[i].centreOld=soleils[i].centre;
            }
			noRefreshEnd();
			milliSleep(50);
		}
        //***** Intégrations successives ******
        for(int i=0;i<nbSoleils;i++){
            Accel(soleils[i],grav(soleils,i, nbSoleils, G),dt);
        }
        BougeToutesBalle(soleils, nbSoleils, dt);
	}
	endGraphics();
	return 0;
}
