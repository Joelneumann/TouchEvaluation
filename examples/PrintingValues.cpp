//
// Created by Joel Neumann on 04.09.24.
//


void setup() {
    Serial.begin(115200);

    //Initializes two Trill Sensors
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
            }, true);

}


void loop() {
    touchSensor.readData();
    //Prints the raw values
    //touchSensor.serialPrintRawData();
    //Prints the detected Touches
    touchSensor.serialPrintTouches();
}