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
	const int w=150;
	const int h=100;
	const int z=4;
	openWindow(w*z,h*z);
    point x={200,200};
    Serpent plop(x, 0, 20, 1, RED);
    plop.affichage();
    for(int i=0; i<500;i++){
        plop.deplacement(false);
        plop.affichage();
        milliSleep(50);
    }


	endGraphics();
	return 0;
}
