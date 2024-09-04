//
// Created by Joel Neumann on 22.12.23.
//

#include "TouchSensor.h"

void TouchSensor::setup(const std::vector<SensorData>& sensor_data, bool is_circular = false) {

    for (const auto& data : sensor_data) {
        Trill trill;

        if (trill.setup(Trill::TRILL_FLEX, data.address) != 0) {
            //TODO: Error Handling
            return;
        }

        delay(50);
        trill.setPrescaler(data.prescaler);
        delay(50);
        trill.updateBaseline();

        trill_sensors_.push_back(trill);
    }

    is_circular_ = is_circular;
}


void TouchSensor::readData() {
    data_.clear();

    auto read_sensor_data = [this](Trill &sensor) {
        sensor.requestRawData();
        while (sensor.rawDataAvailable()) {
            this->data_.push_back(sensor.rawDataRead());
        }
    };

    for (auto& sensor : trill_sensors_) {
        read_sensor_data(sensor);
    }
}

void TouchSensor::serialPrintRawData() {
    Serial.print("[");
    for (size_t i = 0; i < data_.size(); ++i) {
        Serial.print(data_[i]);
        if (i < data_.size() - 1) {
            Serial.print(" ");
        }
    }
    Serial.println("]");
}

TouchVector TouchSensor::getTouches() {
    return data_.extractTouches(is_circular_);
}

void TouchSensor::serialPrintTouches() {
    TouchVector touches = getTouches();

    Serial.print("[");
    for (const auto& touch : touches) {
        Serial.print("[Pos: ");
        Serial.print(touch.getPosition());
        Serial.print(", Ch: ");
        Serial.print(touch.getChannels());
        Serial.print(", Pres: ");
        Serial.print(touch.getPressure());
        Serial.print("]");
    }
    Serial.println("]");


}
