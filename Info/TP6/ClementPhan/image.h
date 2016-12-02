#ifndef IMAGE_H
#define IMAGE_H

#include <cmath>
#include <Imagine/Graphics.h>
using namespace Imagine;
using namespace std;

struct Image{
    byte* t;
    int W,H;
};

Image alloueImage(int W, int H);

void detruitImage(Image I);

void afficheImage(Image I);

Image chargeImage(const char* name);

byte Get(Image I, int i, int j);

void Set(Image I, int i, int j, byte g);

#endif // IMAGE_H
