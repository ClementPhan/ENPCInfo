#ifndef TOOLS_H
#define TOOLS_H

void InitRandom();
double Random(double a, double b);
void Choc(double x,  double y,  double &vx,  double &vy,  double m,
          double x2, double y2, double &vx2, double &vy2, double m2);
void ChocSimple(double x,  double y,  double &vx, double &vy, double m,
                double x2, double y2, double vx2, double vy2);
bool Collision(double x1, double y1, double vx1, double vy1, double r1,
               double x2, double y2, double vx2, double vy2, double r2);

#endif // TOOLS_H
