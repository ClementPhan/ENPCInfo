// Imagine++ project
// Project:  Tennis
// Author:   renaud
// Date:     2007/10/9
// TP #2 du cours de C++ de l'ENPC

#include <Imagine/Graphics.h>
#include <iostream>
using namespace Imagine;

//////////////////////////////////////////////////////////////////
// Fonction de gestion du clavier
// Pour l'instant, utiliser sans se soucier du fontionnement
// Retourne dans sens1 (resp. sens2) -1, 1 ou 0 pour le joueur 1
// (resp. joueur 2) suivant qu'il appuie sur la touche gauche,
// droite ou sur aucune touche.
void Clavier(int& sens1, int& sens2) {
	static bool left1=false,right1=false,left2=false,right2=false;
	Event e;
	do {
		getEvent(0,e);
		if (e.type==EVT_KEY_ON || e.type==EVT_KEY_OFF) {
			bool push=(e.type==EVT_KEY_ON);
			switch (e.key) {
				case 's':
					left1=push;
					break;
				case 'd':
					right1=push;
					break;
				case 'k':
					left2=push;
					break;
				case 'l':
					right2=push;
					break;
			}
		}
	} while (e.type!=EVT_NONE);
	sens1=(left1?-1:(right1?1:0));
	sens2=(left2?-1:(right2?1:0));
}


// Taille de la fenetre, de la balle, vitesse des raquettes
const int width = 512;
const int height = 512;
const int ballSize = 3;
const int speedR = 3;

// Dessin de la balle et des raquettes
void DessineBalle(int x,int y,int radius,Color col, int xr1,int yr1,int lengthr1,int heightr1,Color colr1, int xr2,int yr2,int lengthr2,int heightr2,Color colr2)
{
    fillRect(x-radius,y-radius,2*radius+1,2*radius+1,col);
    fillRect(xr1-lengthr1, yr1-heightr1, 2*lengthr1+1, 2*heightr1+1, colr1);
    fillRect(xr2-lengthr2, yr2-heightr2, 2*lengthr2+1, 2*heightr2+1, colr2);
    milliSleep(20);
    fillRect(x-radius,y-radius,2*radius+1,2*radius+1,WHITE);
    fillRect(xr1-lengthr1, yr1-heightr1, 2*lengthr1+1, 2*heightr1+1, WHITE);
    fillRect(xr2-lengthr2, yr2-heightr2, 2*lengthr2+1, 2*heightr2+1, WHITE);
}

// Détéction de collision raquettes

void Collision(int xb, int yb, int &ub, int &vb, int radius, int x1, int y1,int h1, int l1, int x2, int y2,int h2, int l2)
{
    if ((vb<0) && (xb+ub+radius<x1+l1) && (xb+ub+radius>x1-l1) && (yb+vb-radius<y1+h1 )) // raquette 1
    {
        vb = -vb;
        ub = int(ub + 3*(xb-x1)/l1);
    }
    else if ((vb>0) && (xb+ub+radius<x2+l2) && (xb+ub+radius>x2-l2)&& (yb+vb+radius>y2-h2 ))// raquette 2
    {
        vb = -vb;
        ub = int(ub + 3*(xb-x2)/l2);
    }
}

// Déplacement de la balle
void BougeBalle(int &x, int &y, int &u, int &v, int radius,int &score1, int &score2)
{
    // Rebond latéral
    if ((x+u>width-radius) || (x+u<radius))
        u=-u;
    // Rebond haut et bas
    if (y+v>height-radius)
    {
        v=-v;
        score1 ++;
        std::cout << "Score : " ;
        std::cout << score1;
        std::cout << " - ";
        std::cout << score2;
        std::cout << std::endl;
    }
    else if (y+v<radius)
    {
        v=-v;
        score2 ++;
        std::cout << "Score : " ;
        std::cout << score1;
        std::cout << " - ";
        std::cout << score2;
        std::cout << std::endl;
    }

    // Mise a jour de la position de la balle
    x+=u;
    y+=v;
}


// Déplacement raquette
void BougeRaquette(int &x1,int l1, int &x2, int l2, int speedR)
{
    int u1,
        u2,
        X1,
        X2;

    Clavier(u1,u2);
    X1 = x1 + speedR * u1;
    X2 = x2 + speedR * u2;

    if (X1 >width - l1)
        x1 = width - l1;
    else if (X1 < l1)
        x1 = l1;
    else
        x1 = X1;

    if (X2 >width - l2)
        x2 = width - l2;
    else if (X2 < l2)
        x2 = l2;
    else
        x2 = X2;
}

//////////////////////////////////////////////////////////////////
// Fonction principale
int main()
{
    //Initialistion des raquettes
    int heightR = ballSize,
        lr1 = 10*ballSize,
        lr2 = 10*ballSize,
        xr1 = width/2,
        yr1 = int(ballSize*2.5),
        xr2 = width/2,
        yr2 = height - int(ballSize*2.5),
        score1 = 0,
        score2 = 0;



	// Ouverture de la fenetre
    openWindow(width,height);
	// Position et vitesse de la balle
    int xb=height/2,
		yb=20,
        ub=0,
        vb=5;
	// Boucle principale
    while (true)
    {
        // Dessin de la balle
        DessineBalle(xb, yb, ballSize, RED, xr1,yr1,lr1,heightR, BLACK, xr2,yr2,lr2,heightR, BLACK);
        // détection des collisions balles-raquettes
        Collision(xb,yb,ub,vb,ballSize,xr1,yr1,heightR,lr1,xr2,yr2,heightR,lr2);
        // Déplacement de la balle
        BougeBalle(xb,yb,ub,vb,ballSize,score1,score2);
        // Déplacement des raquettes
        BougeRaquette(xr1,lr1,xr2,lr2,speedR);
    }
	endGraphics();
	return 0;
}
