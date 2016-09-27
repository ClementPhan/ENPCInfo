#include <Imagine/Graphics.h>
#include <iostream>
using namespace Imagine;

void draw(int x1, int y1, int x2, int y2)
{
    drawLine(x1,y1,x2,y2,RED);
}

const int width = 512;
const int height = 512;

int main()
{
    int x0,y0,x1,y1,x2,y2;
    bool clickDroit = false;
    openWindow(width,height);

    clickDroit = ( getMouse(x0,y0) == 3);
    x1 = x0;
    x2 = x0;
    y1 = y0;
    y2 = y0;

    do
    {
        drawLine(x1,y1,x2,y2,RED);
        x1 = x2;
        y1 = y2;
        clickDroit = ( getMouse(x2,y2) == 3);

    } while (clickDroit != true);
    drawLine(x0,y0,x1,y1,RED);

    endGraphics();

    return 0;
}
