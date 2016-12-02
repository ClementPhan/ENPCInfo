#include "balle.h"

void Choc(Balle &B1, Balle &B2){
    Choc(B1.centre.x, B1.centre.y, B1.speed.x, B1.speed.y,B1.mass,B2.centre.x,B2.centre.y,B2.speed.x,B2.speed.y,B2.mass);
}

void ChocSimple(Balle &B, Balle S){ // Surcharge du choc simple avec la structures Balle
    ChocSimple(B.centre.x, B.centre.y, B.speed.x, B.speed.y,B.mass,S.centre.x,S.centre.y,S.speed.x,S.speed.y);
}

bool Collision(Balle B1, Balle B2){ // Surcharge de Collision pour prendre en compte la structure Balle
    return Collision(B1.centre.x, B1.centre.y, B1.speed.x, B1.speed.y, B1.radius,
              B2.centre.x, B2.centre.y, B2.speed.x, B2.speed.y, B2.radius);
}

void AfficheBalle(Balle D){ // Affichage de la balle
    fillCircle(int(D.centre.x),int(D.centre.y),int(D.radius),D.col);
}

void EffaceBalle(Balle D){ // Effacage de la balle
    fillCircle(int(D.centreOld.x),int(D.centreOld.y),int(D.radius),WHITE);
}

void BougeBalle(Balle soleils[], int balle, int length, double dt){ // Déplacement de la balle

    for(int i=0;i<length;i++){ // test de collision pour chaque soleil
        if (i!=balle){
            if (Collision(soleils[balle],soleils[i])){
                ChocSimple(soleils[balle],soleils[i]);
            }
        }
    }
    soleils[balle].centre = soleils[balle].centre + soleils[balle].speed*dt;
}

void BougeBalle(Balle soleils[], int balle, int length, double dt, int JActif){ // Déplacement de la balle POUR LE DUEL

    for(int i=0;i<length;i++){ // test de collision pour chaque soleil
        if ((i!=balle)&&(i!=JActif)){
            if (Collision(soleils[balle],soleils[i])){
                ChocSimple(soleils[balle],soleils[i]);
            }
        }
    }
    soleils[balle].centre = soleils[balle].centre + soleils[balle].speed*dt;
}


void Accel(Balle &D, vect a, double dt){ // Intégration de l'accélération de la balle par methode d'Euler
    D.speed = D.speed + a*dt;
}

vect grav(Balle soleils[], int balle, int length, double G){ // Détermination du vecteur accéleration
    vect a={0,0};
    for(int i=0;i<length;i++){
        if (i!=balle){
            a = a -(soleils[balle].centre-soleils[i].centre) * (soleils[i].mass*G/pow((soleils[i].centre-soleils[balle].centre).Norme(),3));
        }
    }
    return a;
}

vect grav(Balle soleils[], int balle, int length, double G, int JActif){ // Détermination du vecteur accéleration POUR LE DUEL
    vect a={0,0};
    for(int i=0;i<length;i++){
        if ((i!=balle)&&(i!=JActif)){
            a = a -(soleils[balle].centre-soleils[i].centre) * (soleils[i].mass*G/pow((soleils[i].centre-soleils[balle].centre).Norme(),3));
        }
    }
    return a;
}

vect RandVectLoc(int r, int largeur, int hauteur){ // Vecteur aléatoire dans la boite, avec une marge r
    vect v;
    v.x = int(Random(r,largeur-r));
    v.y = int(Random(r,hauteur-r));
    return v;
}

Balle InitBalle(int largeur, int hauteur){ // Initialistion aléatoire de la balle
    Balle B;
    B.radius = int(Random(5,15));
    B.centre= RandVectLoc(B.radius, largeur, hauteur);
    B.centreOld = B.centre;
    B.mass = B.radius/20.0;
    B.speed.x = 0;
    B.speed.y = 0;
    B.col = RED;
    return B;
}

Balle InitSoleils(Balle balles[], int start, int end, int largeur, int hauteur, double rSoleilsMin, double rSoleilsMax){ // Initialisation aléatoire des nbSoleils soleis, sans collisions
    bool clip;
    for(int i=start; i<end; i++){
        balles[i].col = YELLOW;
        balles[i].radius = Random(rSoleilsMin,rSoleilsMax);
        balles[i].mass = balles[i].radius/20.0;
        balles[i].speed.x = 0;
        balles[i].speed.y = 0;
    }
    for(int i=start; i<end; i++){
        do{
            clip = false;
            balles[i].centre = RandVectLoc(balles[i].radius, largeur, hauteur); // Génération du soleil


            if (i > 0)
                for(int j=0;j<i;j++){ // Le soleil est-il dans un autre soleil ?
                    if ((balles[i].centre-balles[j].centre).Norme() < (balles[j].radius + balles[i].radius))
                        clip = true;
                }
        }while(clip);

    }
}

Balle InitSoleilsDuel(Balle balles[], int start, int end, int largeur, int hauteur, double rSoleilsMin, double rSoleilsMax){ // Initialisation aléatoire des nbSoleils soleis, sans collisions
    bool clip;
    for(int i=start; i<end; i++){
        balles[i].col = YELLOW;
        balles[i].radius = Random(rSoleilsMin,rSoleilsMax);
        balles[i].mass = balles[i].radius/20.0;
        balles[i].speed.x = 0;
        balles[i].speed.y = 0;
    }
    for(int i=start; i<end; i++){
        do{
            clip = false;
            balles[i].centre = RandVectLoc(balles[i].radius, largeur, hauteur); // Génération du soleil


            if (i > 0)
                for(int j=0;j<i;j++){ // Le soleil est-il dans un autre soleil ?
                    if ((j==0)||(j==1)){
                        if ((balles[i].centre-balles[j].centre).Norme() < (balles[j].radius + balles[i].radius +100))
                            clip = true;
                    }
                    else{
                        if ((balles[i].centre-balles[j].centre).Norme() < (balles[j].radius + balles[i].radius))
                            clip = true;
                    }
                }
        }while(clip);

    }
}
