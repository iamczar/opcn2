/*
*/

#include "opcn2-library/opcn2-library.h"

#define CS A2

Opcn2Library::OPCN2 alpha(CS);

void setup(){
    Serial.begin(9600);

    Serial.print("Testing OPC-N2 v0.0.1");
    Serial.println(alpha.firmware_version);
}

void loop(){
    alpha.on();
    delay(5000);
    alpha.off();
    delay(10000);

    /*
    values = alpha.histogram();

    Serial.println("");
    Serial.print("Sampling Period:\t"); Serial.println(values.period);
    Serial.print("PM1: "); Serial.println(values.pm1);
    Serial.print("PM2.5: "); Serial.println(values.pm25);
    Serial.print("PM10: "); Serial.println(values.pm10);
    */
}
