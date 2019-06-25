#include "integrator.h"

integrator::integrator(double init) { state = init; }

double integrator::getState() const { return state; }

double integrator::update(double input, double dt) {
    state = state + (prev_in + input) * dt / 2;
    prev_in = input;
    return state;
}


