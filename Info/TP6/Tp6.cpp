// Imagine++ project
// Project:  Tp7
// Author:   keriven
// Date:     2007/10/23

#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <Imagine/Graphics.h>
using namespace Imagine;
using namespace std;

#include "image.h"

////////////////////////////////////////////
///
/// Question 8
/*
byte *alloueImage(int W,int H){
    return new byte[W*H];
}

void detruitImage(byte *I){
    delete[] I;
}

void afficheImage(byte *I, int W, int H){
    putGreyImage(0,0,I,H,W);
}

byte *chargeImage(const char* name, int &W, int &H){
    byte* I;
    loadGreyImage(name,I,W,H);
    return I;
}
*/
/////////////////////////////////////////////////////
///
/// Quastion 12

Image Negatif(Image I){
    Image J = alloueImage(I.W,I.H);
    for(int i=0;i<I.H;i++){
        for(int j=0;j<I.W;j++){
            Set(J,i,j,255-Get(I,i,j));
        }
    }
    return J;
}

Image Flou(Image I){
    Image J = alloueImage(I.W,I.H);
    byte moyenne;
    for(int i=0;i<I.H;i++){
        for(int j=0;j<I.W;j++){
            if((j==0)||(j==I.H)||(i==0)||(i==I.W)){
                Set(J,i,j,Get(I,i,j));
                continue;
            }
            moyenne = byte((Get(I,i-1,j-1)+Get(I,i-1,j)+Get(I,i-1,j+1)+Get(I,i,j-1)+Get(I,i,j)+Get(I,i,j+1)+Get(I,i+1,j-1)+Get(I,i+1,j)+Get(I,i+1,j+1))/9);
            Set(J,i,j,moyenne);
        }
    }
    return J;
}

Image Relief(Image I){
    Image J = alloueImage(I.W,I.H);
    for(int i=0;i<I.H;i++){
        for(int j=0;j<I.W;j++){
            if((j==0)||(j==I.H)||(i==0)||(i==I.W)){
                Set(J,i,j,Get(I,i,j));
                continue;
            }
            Set(J,i,j,(Get(I,i-1,j-1)-Get(I,i+1,j+1)+256)/2);
        }
    }
    return J;
}

Image contour(Image I, double seuil){
    Image J = alloueImage(I.W,I.H);
    double dx,dy;
    for(int i=0;i<I.H;i++){
        for(int j=0;j<I.W;j++){
            if((j==0)||(j==I.H)||(i==0)||(i==I.W)){
                Set(J,i,j,Get(I,i,j));
                continue;
            }
            dx=(Get(I,i,j+1)-Get(I,i,j-1))/2;
            dy=(Get(I,i+1,j)-Get(I,i-1,j))/2;
            if((dx*dx+dy*dy)>seuil) Set(J,i,j,255);
            else Set(J,i,j,0);
        }
    }
    return J;
}

Image deforme(Image I){
    Image J = alloueImage(I.W,I.H);
    for(int i=0;i<I.H;i++){
        for(int j=0;j<I.W;j++){
            Set(J,i,j,Get(I,int(sin(i*M_PI/2/I.H)*I.H),int(sin(j*M_PI/2/I.W)*I.W)));
        }
    }
    return J;
}

Image retrecit(Image I,double r){
    int W = int(I.W/r),
        H = int(I.H/r);
    Image J = alloueImage(W,H);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            Set(J,i,j,Get(I,int(i*r),int(j*r)));
        }
    }
    return J;
}

Image contraste(Image I,double r){
    Image J = alloueImage(I.W,I.H);
    for(int i=0;i<I.H;i++){
        for(int j=0;j<I.W;j++){
            Set(J,i,j,int(atan((Get(I,i,j)-128)*r)/M_PI*2*128+128));
        }
    }
    return J;
}


int main()
{
    int W,H;
    cout << "entrer H :";
    cin >> H;
    cout << "entrer W :";
    cin >> W;

    Window W1 = openWindow(W,H);

    Image grey = alloueImage(W,H);

    ////////////////////////////////////////////
    ///
    /// Question 3

    for(int i=0;i<grey.W;i++){
        for(int j=0;j<grey.H;j++){
            Set(grey,i,j,0);
        }
    }
    afficheImage(grey);
    click();

    for(int i=0;i<grey.W;i++){
        for(int j=0;j<grey.H;j++){
            Set(grey,i,j,255);
        }
    }
    cout << grey.t[0]<<endl;
    afficheImage(grey);
    click();

    for(int i=0;i<grey.W;i++){
        for(int j=0;j<grey.H;j++){
            Set(grey,i,j,byte(255.0*i/grey.W));
        }
    }
    afficheImage(grey);
    click();

    for(int i=0;i<grey.W;i++){
        for(int j=0;j<grey.H;j++){
            Set(grey,i,j,byte(128+128*sin(4*M_PI*i/grey.W)* sin(4*M_PI*j/grey.H)));
        }
    }
    afficheImage(grey);
    click();

    detruitImage(grey);

    ////////////////////////////////////////////
    ///
    /// Question 4


    byte *r,*g,*b;
    r= new byte[W*H];
    g= new byte[W*H];
    b= new byte[W*H];
    for(int i=0;i<W;i++){
        for(int j=0;j<H;j++){
            r[i+W*j]=byte(255.0*i/W);
            g[i+W*j]=byte(255.0*(W-i)/W);
            b[i+W*j]=byte(255.0*j/W);
        }
    }
    putColorImage(0,0,r,g,b,W,H);
    click();

    delete[] r;
    delete[] g;
    delete[] b;
    closeWindow(W1);

    ////////////////////////////////////////////
    ///
    /// Question 6

    loadColorImage(srcPath("ppd.jpg"),r,g,b,W,H);
    W1 = openWindow(W,H);
    putColorImage(0,0,r,g,b,W,H);
    click();

    delete[] r;
    delete[] g;
    delete[] b;
    closeWindow(W1);


    ////////////////////////////////////////////
    ///
    /// Question 7

    Image ppd = chargeImage(srcPath("ppd.jpg"));
    W1 = openWindow(ppd.W,ppd.H);
    afficheImage(ppd);
    click();


    ////////////////////////////////////////////
    ///
    /// Question 12

    Image ppdMod;

    // Negatif
    ppdMod = Negatif(ppd);
    afficheImage(ppdMod);
    click();
    detruitImage(ppdMod);

    // Flou
    ppdMod = Flou(ppd);
    afficheImage(ppdMod);
    click();
    detruitImage(ppdMod);

    // Relief
    ppdMod = Relief(ppd);
    afficheImage(ppdMod);
    click();
    detruitImage(ppdMod);

    //Contour
    ppdMod = contour(ppd,200);
    afficheImage(ppdMod);
    click();
    detruitImage(ppdMod);

    //Deforme
    ppdMod = deforme(ppd);
    afficheImage(ppdMod);
    click();
    detruitImage(ppdMod);

    //contraste
    ppdMod = contraste(ppd,0.2);
    afficheImage(ppdMod);
    click();
    detruitImage(ppdMod);

    //retrecissement
    ppdMod = retrecit(ppd,2);
    closeWindow(W1);
    W1 = openWindow(ppdMod.W,ppdMod.H);
    afficheImage(ppdMod);
    detruitImage(ppdMod);


    endGraphics();
    return 0;
}
