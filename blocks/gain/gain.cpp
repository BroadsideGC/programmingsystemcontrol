#include "gain.h"
#include <iostream>

gain::gain(float gainValue)
{
    this->gain_value = gainValue;
}

float gain::getValue() const {
        return this->gain_value;
}

float gain::update(float input) {
    return input*(this->getValue());
}
