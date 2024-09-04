//
// Created by Joel Neumann on 22.12.23.
//

#ifndef DREA_V2_TOUCH_H
#define DREA_V2_TOUCH_H

#include <cmath>
#include <vector>

class Touch {
private:
    float position_;
    uint8_t channels_;
    int pressure_;

public:
    Touch(float position, int channels, int pressure);

    uint8_t getChannels() const;
    int getPressure() const;
    float getPosition() const;
    float getRelativeCircularPosition(float relative) const;
};

typedef std::vector<Touch> TouchVector;

#endif// DREA_V2_TOUCH_H
