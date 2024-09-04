//
// Created by Joel Neumann on 22.12.23.
//

#ifndef DREA_V2_TOUCH_RING_SENSOR_H
#define DREA_V2_TOUCH_RING_SENSOR_H

#include "Touches/TouchData.h"
#include <Trill.h>

class TouchSensor {
private:
    Trill sensor1_, sensor2_;
    TouchData data_{};

public:
    void setup(int prescaler);
    TouchData readData();
};

#endif// DREA_V2_TOUCH_RING_SENSOR_H
