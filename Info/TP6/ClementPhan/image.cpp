#include "image.h"

Image alloueImage(int W, int H){
    Image I;
    I.H=H;
    I.W=W;
    I.t = new byte[W*H];
    return I;
}

void detruitImage(Image I){
    delete[] I.t;
}

void afficheImage(Image I){
    putGreyImage(0,0,I.t,I.W,I.H);
}

Image chargeImage(const char* name){
    Image I;
    loadGreyImage(name,I.t,I.W,I.H);
    return I;
}

byte Get(Image I, int i, int j){
    return I.t[i+I.W*j];
}

void Set(Image I, int i, int j, byte g){
    I.t[i+I.W*j]=g;
}
