#include <Imagine/Graphics.h>
using namespace Imagine;

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

#include "point.h" //Taille de la grille 'N' définie ici

// ****** Constantes ******

const int taille = 50;
const int cote = taille*N;
const int Xini = N/2,
          Yini = N/2;

point chemin[N*N];
bool grid[N][N];
bool mvtPossible[5];


//****** Fonctions ******
void InitRandom(){
    srand((unsigned int)time(0));
}

int Random(){
    return int(4*rand()/RAND_MAX);
}

void CheckPoint(point p, bool mvtPossible[5]){
    int x=p.x,
        y=p.y;
    if ((x!=0)&&(x!=N-1)){
        if ((y!=0)&&(y!=N-1)){
            mvtPossible[0]=grid[x-1][y];
            mvtPossible[1]=grid[x][y+1];
            mvtPossible[2]=grid[x+1][y];
            mvtPossible[3]=grid[x][y-1];
        }
        else if(y==0){
            mvtPossible[0]=grid[x-1][y];
            mvtPossible[1]=grid[x][y+1];
            mvtPossible[2]=grid[x+1][y];
            mvtPossible[3]=false;
        }
        else if(y==N-1){
            mvtPossible[0]=grid[x-1][y];
            mvtPossible[1]=false;
            mvtPossible[2]=grid[x+1][y];
            mvtPossible[3]=grid[x][y-1];
        }
    }
    else if (x==0){
        if ((y!=0)&&(y!=N-1)){
            mvtPossible[0]=false;
            mvtPossible[1]=grid[x][y+1];
            mvtPossible[2]=grid[x+1][y];
            mvtPossible[3]=grid[x][y-1];
        }
        else if(y==0){
            mvtPossible[0]=false;
            mvtPossible[1]=grid[x][y+1];
            mvtPossible[2]=grid[x+1][y];
            mvtPossible[3]=false;
        }
        else if(y==N-1){
            mvtPossible[0]=false;
            mvtPossible[1]=false;
            mvtPossible[2]=grid[x+1][y];
            mvtPossible[3]=grid[x][y-1];
        }
    }
    else if (x==N-1){
        if ((y!=0)&&(y!=N-1)){
            mvtPossible[0]=grid[x-1][y];
            mvtPossible[1]=grid[x][y+1];
            mvtPossible[2]=false;
            mvtPossible[3]=grid[x][y-1];
        }
        else if(y==0){
            mvtPossible[0]=grid[x-1][y];
            mvtPossible[1]=grid[x][y+1];
            mvtPossible[2]=false;
            mvtPossible[3]=false;
        }
        else if(y==N-1){
            mvtPossible[0]=grid[x-1][y];
            mvtPossible[1]=false;
            mvtPossible[2]=false;
            mvtPossible[3]=grid[x][y-1];
        }
    }
    mvtPossible[4]=(mvtPossible[0]||mvtPossible[1]||mvtPossible[2]||mvtPossible[3]);
}



int Deplacement(int longueur){
    grid[chemin[longueur].x][chemin[longueur].y]=false;
    Update(chemin[longueur],grid,taille);
    CheckPoint(chemin[longueur],mvtPossible);
    if ((chemin[longueur].x==Xini)&&(chemin[longueur].y==Yini)&& (mvtPossible[4]==false)){
        return 0;
    }
    if (mvtPossible[4]){
        int i;
        do{
           i=Random();
        }while(mvtPossible[i]==false);
        chemin[longueur+1]=movePoint(chemin[longueur],i);
        Deplacement(longueur+1);
    }
    else{
        Deplacement(longueur-1);
    }
}

int main(){
    //****** Grapique ******
    openWindow(cote,cote);
    for(int i=1; i<cote;i++){
        drawLine(0,taille*i,cote,taille*i,BLACK);
        drawLine(taille*i,0,taille*i,cote,BLACK);
    }

    //****** Initialisation ******
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            grid[i][j]=true;
        }
    }
    InitRandom();
    chemin[0]=cPoint(Xini,Yini);


    Deplacement(0);




    endGraphics();
    return 0;
}
