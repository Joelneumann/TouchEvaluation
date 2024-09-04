//
// Created by Joel Neumann on 22.12.23.
//

#include "TouchSensor.h"

void TouchSensor::setup(int prescaler) {
    int ret1 = sensor1_.setup(Trill::TRILL_FLEX);
    int ret2 = sensor2_.setup(Trill::TRILL_FLEX, 0x49);

    // TODO: Error handling
    if (ret1 != 0) {}
    if (ret2 != 0) {}

    delay(100);
    sensor1_.setPrescaler(prescaler);
    delay(50);
    sensor2_.setPrescaler(prescaler);
    delay(50);
    sensor1_.updateBaseline();
    delay(50);
    sensor2_.updateBaseline();
    delay(100);
}

TouchData TouchSensor::readData() {
    unsigned int loc = 0;
    auto read_sensor_data = [this, &loc](Trill &sensor) {
        sensor.requestRawData();
        while (sensor.rawDataAvailable()) {
            this->data_[loc++] = sensor.rawDataRead();
            // Serial.print(data[loc-1]);
            // Serial.print(", ");
        }
    };

    read_sensor_data(sensor1_);
    read_sensor_data(sensor2_);

    return this->data_;
}
