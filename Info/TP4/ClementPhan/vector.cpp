#include "vector.h"

vect operator +(vect m, vect n){
    vect p;
    p.x=n.x+m.x;
    p.y=n.y+m.y;
    return p;
}
vect operator -(vect m, vect n){
    vect p;
    p.x=m.x-n.x;
    p.y=m.y-n.y;
    return p;
}
vect operator -(vect n){
    vect p;
    p.x=-n.x;
    p.y=-n.y;
    return p;
}
vect operator *(vect n, double l){
    vect p;
    p.x = n.x*l;
    p.y = n.y*l;
    return p;
}
vect operator *(double l, vect n){
    return n*l;
}
