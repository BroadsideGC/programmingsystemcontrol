#ifndef PLANT_H
#define PLANT_H

#include "control.h"

class Plant {
public:
    Plant();
    void setAMatrix(double *arr);
    void setBMatrix(double *arr);
    void setCMatrix(double *arr);
    void setState();
    double getState();
    double update(double dt, bool flag);
    double x1 = 0, x2 = 0, x3 = 0, xdiff1, xdiff2, xdiff3;

private:
    double state;
    double *arrA;
    double *arrB;
    double *arrC;
    control ctrl = control();

};

#endif // PLANT_H
