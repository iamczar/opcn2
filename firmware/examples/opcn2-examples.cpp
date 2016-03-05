/*
*/

#include "opcn2/opcn2.h"

#define CS A2

OPCN2 alpha(CS);

void setup(){
    Serial.begin(9600);

    Serial.print("Testing OPC-N2 v0.0.1");
    Serial.println(alpha.firmware_version);
}

void loop(){
    Serial.println(alpha.firmware_version);

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
