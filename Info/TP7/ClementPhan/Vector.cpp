#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;
#include "Vector.h"

Vector Vector::operator+(Vector b) {
	Vector c;
    for(int i=0;i<DIM;i++){
        c.Set(i,Get(i)+b.Get(i));
    }
	return c;
}

Vector Vector::operator -(Vector b) {
    Vector c;
    for(int i=0;i<DIM;i++){
        c.Set(i,Get(i)-b.Get(i));
    }
	return c;
}

Vector Vector::operator*(double lambda) {
    Vector c;
    for(int i=0;i<DIM;i++){
        c.Set(i,Get(i)*lambda);
    }
	return c;
}

Vector Vector::operator/(double lambda) {
    Vector c;
    for(int i=0;i<DIM;i++){
        c.Set(i,Get(i)/lambda);
    }
    return c;
}

double Vector::operator*(Vector b){
    double sum;
    for(int i=0;i<DIM;i++){
        sum+= Get(i)*b.Get(i);
    }
    return sum;
}

double Vector::Norm() {
    return sqrt(*this * *this);
}

Vector Vector::Rotate(double angle) {
	angle *= M_PI / 180;
	Vector c;
	double co = cos(angle);
	double si = sin(angle);
    c.Set(0,co * Get(0) + si * Get(1));
    c.Set(1,- si * Get(0) + co * Get(1));
	return c;
}

double Vector::Get(int i){
    return coord[i];
}

void Vector::Set(int i, double x){
    coord[i]=x;
}
