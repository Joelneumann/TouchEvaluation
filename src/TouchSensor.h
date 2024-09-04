//
// Created by Joel Neumann on 22.12.23.
//

#ifndef DREA_V2_TOUCH_RING_SENSOR_H
#define DREA_V2_TOUCH_RING_SENSOR_H

#include "Touches/TouchData.h"
#include <Trill.h>

struct SensorData{
    int prescaler; //0-8
    uint8_t address; //Standard: 0x48
    int channel_count; //Standard: 30
};

class TouchSensor {
private:
    bool is_circular_;
    int channel_count_ = 0;
    std::vector<Trill> trill_sensors_;

    TouchData data_{};

public:
    void setup(const std::vector<SensorData>&, bool circular);
    void readData();

    void serialPrintRawData();
    void serialPrintTouches();
    TouchVector getTouches();


};

#endif// DREA_V2_TOUCH_RING_SENSOR_H
