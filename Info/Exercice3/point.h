#ifndef POINT_H
#define POINT_H

#include <Imagine/Graphics.h>
using namespace Imagine;

const int N=15;

struct point{
    int x;
    int y;
};

void fillPoint(point p, int taille, Color C);

point movePoint(point p, int i);

void Update(point robot, bool grid[N][N], int taille);

point cPoint(int x, int y);

#endif // POINT_H
