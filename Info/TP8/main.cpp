// Imagine++ project
// Project:  Tp9
// Author:   keriven
// Date:     2007/10/23

// Programme TRON

#include "utils.h"
#include "serpent.h"
using namespace std;

//======================================
// Serpent





//======================================
// Jeu TRON





int main()
{
	const int w=200;
	const int h=150;
	const int z=3;
	openWindow(w*z,h*z);
    point x={200,200};
    Serpent plop(x, droite, 20, 1, RED);
    plop.affichage();
    int joueurs[2]={droite,droite};
    while(plop.collision()==false){
        plop.effacage();
        plop.deplacement(true);
        plop.affichage();
        milliSleep(50);
        GetDir(joueurs);
        plop.inputDir(joueurs[0]);

    }


	endGraphics();
	return 0;
}
