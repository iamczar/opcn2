/*
*/

#include "opcn2/opcn2.h"

#define CS A2

OPCN2 alpha(CS);
HistogramData hist;
ConfigurationVariables vars;

void setup(){
    Serial.begin(9600);

    Serial.print("Testing OPC-N2 v");
    Serial.println(alpha.firmware_version);

    // Read and print the configuration variables
    vars = alpha.config();

    Serial.println("\nConfiguration Variables");
    Serial.print("\tGSC:\t"); Serial.println(vars.gsc);
    Serial.print("\tSFR:\t"); Serial.println(vars.sfr);
    Serial.print("\tLaser DAC:\t"); Serial.println(vars.laser_dac);
    Serial.print("\tFan DAC:\t"); Serial.println(vars.fan_dac);
    Serial.print("\tToF-SFR:\t"); Serial.println(vars.tof_sfr);

    alpha.on();
    delay(1000);
}

void loop(){

    delay(3000);

    hist = alpha.histogram();

    // Print out the histogram data
    Serial.print("\nSampling Period:\t"); Serial.println(hist.period);
    Serial.print("PM1: "); Serial.println(hist.pm1);
    Serial.print("PM2.5: "); Serial.println(hist.pm25);
    Serial.print("PM10: "); Serial.println(hist.pm10);

}
