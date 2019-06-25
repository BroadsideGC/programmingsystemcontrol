#include "control.h"
#include <iostream>

control::control() {

}

double control::update(double dt) {
    double leftExp = cos1.update(cos1.getState(), 2*dt);
    double rightExp = cos2.update(cos2.getState(), 5*dt);
    state = 0.2 * leftExp + 0.1 * rightExp;
    return state;
}
