// Imagine++ project
// Project:  Tp8
// Author:   keriven
// Date:     2007/10/23

#include <Imagine/Graphics.h>
using namespace Imagine;

#include"Vector.h"

///////////////////////////////
///
/// Fonctions

// Q2
void drawLine(Vector u, Vector v, Color c, int pen_w){
    drawLine(u.Get(0),u.Get(1),v.Get(0),v.Get(1),c,pen_w);
}
void drawLine(Vector u, Vector v, Color c){
    drawLine(u,v,c,1);
}

void drawTriangle(Vector u, Vector v, Vector w,Color c, int pen_w){
    drawLine(u.Get(0),u.Get(1),w.Get(0),w.Get(1),c,pen_w);
    drawLine(u.Get(0),u.Get(1),v.Get(0),v.Get(1),c,pen_w);
    drawLine(w.Get(0),w.Get(1),v.Get(0),v.Get(1),c,pen_w);
}


//Q3 Serpinski
void serpinski(Vector u, Vector v, Vector w, int pen_w){
    if (pen_w==0){
        return;
    }
    drawTriangle(u,v,w,BLACK,pen_w);
    serpinski(u,(v+u)/2,(w+u)/2,pen_w-1);
    serpinski((u+v)/2,v,(w+v)/2,pen_w-1);
    serpinski((u+w)/2,(v+w)/2,w,pen_w-1);
    return;
}

//Q6 Arbre
void arbre(Vector u, Vector v, int n){
    if(n==0){
        drawLine(u,v,BLACK);
        return;
    }
    Vector a=(u+v)/2,
           b=a+(a-u).Rotate(20),
           c=a+(a-u).Rotate(-20);
    drawLine(u,a,BLACK);
    arbre(a,b,n-1);
    arbre(a,c,n-1);
}

//Q9 Koch
void flocon(Vector u, Vector v, int n){
    drawLine(u,v,BLACK);
    if(n==0){
        return;
    }
    Vector a = u+(v-u)/3,
           c = u+(v-u)*2/3;
    Vector b = a+(c-a).Rotate(60);
    drawLine(a,c,WHITE,4);
    flocon(u,a,n-1);
    flocon(a,b,n-1);
    flocon(b,c,n-1);
    flocon(c,v,n-1);
}




int main()
{
    const int width = 512, height = 512;
    // Serpinski
    setActiveWindow(openWindow(width,height));
    Vector u,v,w;
    u.Set(0,10);
    u.Set(1,height-10);
    v.Set(0,width-10);
    v.Set(1,height-10);
    w=u+(v-u).Rotate(60);
    serpinski(u,v,w,6);

    // Arbre
    setActiveWindow(openWindow(width,height));
    Vector x,y;
    x.Set(0,10);
    x.Set(1,height/2.0);
    y.Set(0,width-10);
    y.Set(1,height/2.0);
    arbre(x,y,5);

    // Flocon
    setActiveWindow(openWindow(width,height));
    Vector a,b,c;
    a.Set(0,width/6);
    a.Set(1,height*2/3);
    b.Set(0,width*5/6);
    b.Set(1,height*2/3);
    c=a+(b-a).Rotate(60);
    flocon(b,a,4);
    flocon(c,b,4);
    flocon(a,c,4);
	endGraphics();
	return 0;
}
