#ifndef UTILS_H
#define UTILS_H

#include <Imagine/Graphics.h>
using namespace Imagine;

//======================================
// Structure point

struct point
{
	int x;
	int y;
    point operator+(const point &p) const{
        point q;
        q.x=x+p.x;
        q.y=y+p.y;
        return q;
    }
    point operator-(const point &p) const{
        point q;
        q.x=x-p.x;
        q.y=y-p.y;
        return q;
    }
    point operator*(int lambda) const{
        point q;
        q.x=x*lambda;
        q.y=y*lambda;
        return q;
    }
    bool operator==(point p) const{
        return ((x==p.x)&&(y==p.y));
    }

};

const int droite = 0;
const int bas = 1;
const int gauche = 2;
const int haut = 3;
const point dir[4] = {{1,0},{0,1},{-1,0},{0,-1}};

//======================================
// Gestion du clavier

int Clavier();




#endif // UTILS_H
