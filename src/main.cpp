//
// Created by Joel Neumann on 04.09.24.
//

#include <Arduino.h>
#include "TouchSensor.h"


TouchSensor touchSensor;


void setup() {
    Serial.begin(115200);

    touchSensor.setup(
            {
                    {
                            .prescaler = 3,
                            .address = 0x48
                    },
                    {
                            .prescaler = 3,
                            .address = 0x49
                    },
            }, false);

}


void loop() {
    touchSensor.readData();
    //touchSensor.serialPrintRawData();
    touchSensor.serialPrintTouches();
}