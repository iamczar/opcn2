/*
*/

#include "opcn2-library.h"

#define CS A2

OPCN2 alpha(CS);

void setup(){
    Serial.begin(9600);
    Serial.print("Testing OPC-N2 v");
    Serial.println(alpha.firmware_version);

    delay(1000);

    alpha.on();
}

void loop(){
    delay(3000);
    histogram_data = alpha.histogram();

    Serial.println("");
    Serial.print("Sampling Period:\t"); Serial.println(values.period);
    Serial.print("PM1: "); Serial.println(values.pm1);
    Serial.print("PM2.5: "); Serial.println(values.pm25);
    Serial.print("PM10: "); Serial.println(values.pm10);
}
