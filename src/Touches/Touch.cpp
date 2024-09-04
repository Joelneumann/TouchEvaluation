//
// Created by Joel Neumann on 22.12.23.
//

#include "Touch.h"

Touch::Touch(float position, int channels, int pressure)
    : position_(position), channels_(channels), pressure_(pressure) {}

uint8_t Touch::getChannels() const {
    return channels_;
}

int Touch::getPressure() const {
    return pressure_;
}

float Touch::getPosition() const {
    return position_;
}

float Touch::getRelativeCircularPosition(float relative) const {
    if (relative < 0) {
        relative = fmodf(-relative, float(2 * M_PI));
        relative = float(2 * M_PI) - relative;
    } else {
        relative = fmodf(relative, float(2 * M_PI));
    }

    float new_position = fmodf(getPosition() + relative, float(2 * M_PI));

    if (new_position < 0) {
        new_position += float(2 * M_PI);
    }

    return new_position;
}
