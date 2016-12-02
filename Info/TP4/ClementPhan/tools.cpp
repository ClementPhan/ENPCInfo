#include <cstdlib>
#include <ctime>
#include "tools.h"
using namespace std;

const double dt = 0.1;

void InitRandom()
{
    srand((unsigned int)time(0));
}

double Random(double a, double b)
{
    double x = double(rand())/RAND_MAX;
    return a + (b-a)*x;
}

void Choc(double x,  double y,  double &vx,  double &vy,  double m,
          double x2, double y2, double &vx2, double &vy2, double m2)
{
    double vvx = (m * vx + m2 * vx2)/(m + m2);
    double vvy = (m * vy + m2 * vy2)/(m + m2);
    double deltax = x2 - x;
    double deltay = y2 - y;
    double norme = deltax * deltax + deltay * deltay;
    double scal = -2. * ((vx-vvx)*deltax + (vy-vvy)*deltay)/norme;
    vx += scal * deltax;
    vy += scal * deltay;
    scal = -2. * ((vx2-vvx)*deltax + (vy2-vvy)*deltay)/norme;
    vx2 += scal * deltax;
    vy2 += scal * deltay;
}

void ChocSimple(double x,  double y,  double &vx, double &vy, double m,
                double x2, double y2, double vx2, double vy2)
{
    Choc(x,y,vx,vy,m,x2,y2,vx2,vy2,1000*m);
}

bool Collision(double x1, double y1, double vx1, double vy1, double r1,
               double x2, double y2, double vx2, double vy2, double r2)
{
    double dx=x1-x2,dy=y1-y2,dvx=vx1-vx2,dvy=vy1-vy2,r=r1+r2;
    if (dvx*dvx + dvy*dvy != 0) {
        double t_min = -(dx*dvx + dy*dvy)/(dvx*dvx + dvy*dvy);
        double t_vrai;
        if (t_min < 0)
            t_vrai = 0;
        else if (t_min > dt)
            t_vrai = dt;
        else
            t_vrai = t_min;
        dx += dvx * t_vrai;
        dy += dvy * t_vrai;
    }
    return ((dx*dx + dy*dy) <= r*r);
}

