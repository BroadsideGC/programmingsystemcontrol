#ifndef INTEGRATOR_H
#define INTEGRATOR_H

class integrator {
public:
    integrator(double init);
    double update(double input, double dt);
    double getState() const;
private:
    double state;
    double prev_in = 0;
};

#endif // INTEGRATOR_H
