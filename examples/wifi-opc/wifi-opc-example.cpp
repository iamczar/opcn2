/*
Run the Alphasense OPC-N2 continuously and make the PM1, PM2.5, and PM10
values available to the user remotely by setting them as public variables.

Written by David H Hagan, Feb. 2017
*/

#include "opcn2.h"

#define CS A2

// Initiate the OPCN2
OPCN2 opc(CS);

// Setup some other variables
int     DELAY = 5000;
String  INFO  = "";

double    PM1, PM25, PM10;
Firmware  fw;
PMData    pmdata;

void setup() {
  Serial.begin(9600);

  // Turn on the OPC
  opc.on();
  delay(1000);

  // Gather some information
  fw = opc.read_firmware_version();
  INFO.concat("\nOPC SN: " + String(opc.read_serial_number()));
  INFO.concat("\nOPC FW: " + String(fw.major) + "." + String(fw.minor));

  Serial.println(INFO);

  waitUntil(Particle.connected);

  Particle.variable("PM1", PM1);
  Particle.variable("PM25", PM25);
  Particle.variable("PM10", PM10);
}

void loop() {
  // Read the PM data, update the variables, delay
  pmdata = opc.read_pm_data();

  PM1   = pmdata.pm1;
  PM25  = pmdata.pm25;
  PM10  = pmdata.pm10;

  Serial.println(String::format("PM1: %.1f, PM2.5: %.2f, PM10: %.2f", PM1, PM25, PM10));

  delay(DELAY);
}
