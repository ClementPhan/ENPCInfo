#ifndef VECTOR_H
#define VECTOR_H
#include <cmath>
using namespace std;

struct vect{ //Structure de vecteurs, avec les calculs appropriés (dont la norme)
    double x;
    double y;
    double Norme(){
        return sqrt(x*x+y*y);
    }
};

vect operator +(vect m, vect n);
vect operator -(vect m, vect n);
vect operator -(vect n);
vect operator *(vect n, double l);
vect operator *(double l, vect n);
vect operator -(vect n);

#endif // VECTOR_H
