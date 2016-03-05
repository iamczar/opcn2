/*
*/

#include "opcn2/opcn2.h"

#define CS A2

OPCN2 alpha(CS);

void setup(){
    Serial.begin(9600);

    Serial.print("Testing OPC-N2 v0.0.1");
    Serial.println(alpha.firmware_version);

    // Read and print the configuration variables
    ConfigurationVariables vars = alpha.config();

    Serial.println("\nConfiguration Variables");
    Serial.print("\tGSC:\t"); Serial.println(vars.gsc);
    Serial.print("\tSFR:\t"); Serial.println(vars.sfr);
    Serial.print("\tLaser DAC:\t"); Serial.println(vars.laser_dac);
    Serial.print("\tFan DAC:\t"); Serial.println(vars.fan_dac);
    Serial.print("\tToF-SFR:\t"); Serial.println(vars.tof_sfr);
}

void loop(){
    alpha.on();

    delay(5000);

    alpha.off();

    delay(5000);

    /*
    values = alpha.histogram();

    Serial.println("");
    Serial.print("Sampling Period:\t"); Serial.println(values.period);
    Serial.print("PM1: "); Serial.println(values.pm1);
    Serial.print("PM2.5: "); Serial.println(values.pm25);
    Serial.print("PM10: "); Serial.println(values.pm10);
    */
}
