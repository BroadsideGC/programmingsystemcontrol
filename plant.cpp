#include "plant.h"

Plant::Plant() {

}

void Plant::setAMatrix(double *arr) {
    this->arrA = arr;
}

void Plant::setBMatrix(double *arr) {
    this->arrB = arr;
}
void Plant::setCMatrix(double *arr) {
    this->arrC = arr;
}

void Plant::setState() {
    this->x1 = 1;
    this->x2 = 0;
    this->x3 = 0;
}

double Plant::getState() {
    return x1 * arrC[0] + x2 * arrC[1] + x3 * arrC[2];
}

double Plant::update(double dt, bool flag) {
    double tmp1 = 0;
    if (flag) {
        tmp1 = ctrl.update(dt);
    }

    xdiff1 = arrA[0] * x1 + arrA[1] * x2 + arrA[2] * x3 + arrB[0] * tmp1;
    xdiff2 = arrA[3] * x1 + arrA[4] * x2 + arrA[5] * x3 + arrB[1] * tmp1;
    xdiff3 = arrA[6] * x1 + arrA[7] * x2 + arrA[8] * x3 + arrB[2] * tmp1;
}


