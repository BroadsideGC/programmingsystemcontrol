#ifndef CONTROL_H
#define CONTROL_H

#include "blocks/integrator.h"

class control {
public:
    control();
    double update(double dt);
private:
    double state;
    integrator cos1 = integrator(1);
    integrator cos2 = integrator(1);
};

#endif // CONTROL_H
