#include "control.h"

control::control() {

}

double control::update(double dt) {
    double leftExp = exp1.update(exp1.getState(), -1 * dt);
    double rightExp = exp2.update(exp2.getState(), -0.5 * dt);
    state = 3 * leftExp + 5 * rightExp;
    return state;
}
