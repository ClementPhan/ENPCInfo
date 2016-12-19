#include "serpent.h"

bool Serpent::collision(const Serpent &S){
    if(_longueur>=5){
        for(int i=5;i<_longueur;i++) {
            if ((_corps[0] -_corps[i]).normeInf() <=2) {
                return true;
            }
        }
    }

    point* autre = S.GetPoint();
    int longeur_Autre = S.GetLongueur();
    for(int i=0;i<longeur_Autre;i++){
        if ((_corps[0]-autre[i]).normeInf()<=2){
            return true;
        }
    }
    return false;
}

bool Serpent::collision(){
    if(_longueur>=5){
        for(int i=5;i<_longueur;i++) {
            if ((_corps[0] -_corps[i]).normeInf() <=2) {
                return true;
            }
        }
    }
    return false;
}

void Serpent::allonge(){
    point *tmp = new point[_longueur+_vitesse];
    for(int i=0;i<_longueur;i++){
        tmp[i]=_corps[i];
    }
    delete[] _corps;
    _corps = tmp;
    _longueur+=_vitesse;
}
void Serpent::affichage(){
    for(int i=0;i<_longueur;i++){
        fillRect(_corps[i].x-1,_corps[i].y-1,3,3,_col);
    }
}

void Serpent::effacage(){
    for(int i=0;i<_longueur;i++){
        fillRect(_corps[i].x-1,_corps[i].y-1,3,3,WHITE);
    }
}

void Serpent::inputDir(int i){
    _direction = i%4;
}

void Serpent::deplacement(bool allonger){
    if(allonger){
        allonge();
    }
    for(int i=_longueur-1;i>=0;i--){
        _corps[i]=_corps[i-1];
    }
    _corps[0]=_corps[1]+dir[_direction]*_vitesse;
}

void GetDir(int joueurs[2]){
    int i=Clavier();
    switch(i){
        case 'q':
            joueurs[0]=(joueurs[0]-1+4)%4;
            break;
        case 'd':
            joueurs[0]=(joueurs[0]+1+4)%4;
            break;
        case 'j':
            joueurs[1]=(joueurs[1]-1+4)%4;
            break;
        case 'l':
            joueurs[1]=(joueurs[1]+1+4)%4;
            break;
        default:break;
    }
}
