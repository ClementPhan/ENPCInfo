#include "point.h"


point cPoint(int x, int y){
    point p;
    p.x=x;
    p.y=y;
    return p;
}

void fillPoint(point p,int taille, Color C){
    fillRect(taille*p.x+1,taille*p.y+1,taille-1, taille-1, C);
}

point movePoint(point p,int i){
    point q=p;
    if (i==0)
        q.x--;
    else if (i==1)
        q.y++;
    else if (i==2)
        q.x++;
    else
        q.y--;
    return q;
}

void Update(point robot, bool grid[N][N], int taille){
    noRefreshBegin();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j]==false){
                fillPoint(cPoint(i,j),taille,GREEN);
            }
        }
    }
    fillPoint(robot,taille, RED);
    noRefreshEnd();
    milliSleep(100);
}
