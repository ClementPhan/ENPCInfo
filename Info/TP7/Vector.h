#pragma once

const int DIM = 2;

class Vector {
    double coord[DIM];
    double operator*(Vector b);

    public:
    // Somme de deux vecteurs
    Vector operator+(Vector b);
    // Difference de deux vecteurs
    Vector operator-(Vector b);
    // Multiplication scalaire * vecteur
    Vector operator*(double lambda);
    Vector operator/(double lambda);

    // Norme d'un vecteur
    double Norm();

    // Rotation (angle en degres)
    Vector Rotate(double angle);

    // Accesseur
    double Get(int i);
    void Set(int i, double x);

};


