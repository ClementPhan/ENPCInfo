#include "serpent.h"

bool Serpent::collision(const Serpent &S){
    for(int i=1;i<_longueur;i++){
        if (_corps[0]==_corps[i]){
            return true;
        }
    }
    point* autre = S.GetPoint();
    int longeur_Autre = S.GetLongueur();
    for(int i=0;i<longeur_Autre;i++){
        if (_corps[0]==autre[i]){
            return true;
        }
    }
    return false;
}

bool Serpent::collision(){
    for(int i=1;i<_longueur;i++){
        if (_corps[0]==_corps[i]){
            return true;
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
}
void Serpent::affichage(){
    for(int i=0;i<_longueur;i++){
        ;
    }
}

void Serpent::inputDir(int){

}

void Serpent::deplacement(bool allonger){
    if(allonger){
        allonge();
    }
    for(int i=_longueur-1;i>0;i--){
        _corps[i]=_corps[i-1];
    }
    _corps[0]=_corps[1]+dir[_direction]*_vitesse;
}