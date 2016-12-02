#ifndef SERPENT_H
#define SERPENT_H

#include "utils.h"

//======================================
// Serpent

class Serpent{
    private:
        int _longueur;
        point *_corps;
        int _direction;
        int _vitesse;
        Color _col;

        void allonge();

        bool collision();// a regarder apres le deplacement
        bool collision(const Serpent &S);// a regarder apres le deplacement de tous les autres objets
        void affichage(); // apres tous les deplacements et les collisions


    public:
        void inputDir(int);
        void deplacement(bool); // bool pour savoir si on allonge
        void deplacement(Serpent,bool);

        int GetLongueur() const{
            return _longueur;
        }
        point* GetPoint() const{
            return _corps;
        }

        Serpent(){}
        Serpent(point tete, int direction, int longueur, int vitesse=3, const Color &col=BLACK){
            _longueur = longueur;
            _corps = new point[longueur];
            for(int i=0;i<longueur;i++){
                _corps[i]=tete+dir[direction]*double(i);
            }
            _col = col;
            _vitesse = vitesse;
        }
        ~Serpent(){
            if(_longueur!=0)
                delete[] _corps;
        }

};

#endif // SERPENT_H
