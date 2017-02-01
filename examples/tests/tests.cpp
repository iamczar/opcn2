/*
  Run tests for the entire OPC-N2 library.
*/

#include "opcn2.h"

#define CS A2

OPCN2 alpha(CS);

HistogramData hist;
PMData pm;
ConfigVars vars;
ConfigVars2 vars2;

void setup(){
    delay(2000);
    Serial.begin(9600);

    // Test the Firmware methods
    Serial.println("Testing Firmware Methods");

    // Test the Info String
    Serial.print("\t.read_information_string()");
    Serial.println("\t" + alpha.read_information_string());

    if (alpha.firm_ver.major >= 18){
      Serial.print("\t.read_firmware_version()");
      Firmware tmp = alpha.read_firmware_version();

      Serial.println("\tv" + String(tmp.major) + "." + String(tmp.minor));
    }

    // Read and print the configuration variables
    vars  = alpha.read_configuration_variables();

    Serial.println("\n.read_configuration_variables()");
    Serial.print("\tbb0: "); Serial.println(vars.bb0);
    Serial.print("\tbb1: "); Serial.println(vars.bb1);
    Serial.print("\tbb2: "); Serial.println(vars.bb2);
    Serial.print("\tbb3: "); Serial.println(vars.bb3);
    Serial.print("\tbb4: "); Serial.println(vars.bb4);
    Serial.print("\tbb5: "); Serial.println(vars.bb5);
    Serial.print("\tbb6: "); Serial.println(vars.bb6);
    Serial.print("\tbb7: "); Serial.println(vars.bb7);
    Serial.print("\tbb8: "); Serial.println(vars.bb8);
    Serial.print("\tbb9: "); Serial.println(vars.bb9);
    Serial.print("\tbb10: "); Serial.println(vars.bb10);
    Serial.print("\tbb11: "); Serial.println(vars.bb11);
    Serial.print("\tbb12: "); Serial.println(vars.bb12);
    Serial.print("\tbb13: "); Serial.println(vars.bb13);
    Serial.print("\tbb14: "); Serial.println(vars.bb14);

    Serial.print("\tbpv0: "); Serial.println(vars.bpv0);
    Serial.print("\tbpv1: "); Serial.println(vars.bpv1);
    Serial.print("\tbpv2: "); Serial.println(vars.bpv2);
    Serial.print("\tbpv3: "); Serial.println(vars.bpv3);
    Serial.print("\tbpv4: "); Serial.println(vars.bpv4);
    Serial.print("\tbpv5: "); Serial.println(vars.bpv5);
    Serial.print("\tbpv6: "); Serial.println(vars.bpv6);
    Serial.print("\tbpv7: "); Serial.println(vars.bpv7);
    Serial.print("\tbpv8: "); Serial.println(vars.bpv8);
    Serial.print("\tbpv9: "); Serial.println(vars.bpv9);
    Serial.print("\tbpv10: "); Serial.println(vars.bpv10);
    Serial.print("\tbpv11: "); Serial.println(vars.bpv11);
    Serial.print("\tbpv12: "); Serial.println(vars.bpv12);
    Serial.print("\tbpv13: "); Serial.println(vars.bpv13);
    Serial.print("\tbpv14: "); Serial.println(vars.bpv14);
    Serial.print("\tbpv15: "); Serial.println(vars.bpv15);

    Serial.print("\tbpd0: "); Serial.println(vars.bpd0);
    Serial.print("\tbpd1: "); Serial.println(vars.bpd1);
    Serial.print("\tbpd2: "); Serial.println(vars.bpd2);
    Serial.print("\tbpd3: "); Serial.println(vars.bpd3);
    Serial.print("\tbpd4: "); Serial.println(vars.bpd4);
    Serial.print("\tbpd5: "); Serial.println(vars.bpd5);
    Serial.print("\tbpd6: "); Serial.println(vars.bpd6);
    Serial.print("\tbpd7: "); Serial.println(vars.bpd7);
    Serial.print("\tbpd8: "); Serial.println(vars.bpd8);
    Serial.print("\tbpd9: "); Serial.println(vars.bpd9);
    Serial.print("\tbpd10: "); Serial.println(vars.bpd10);
    Serial.print("\tbpd11: "); Serial.println(vars.bpd11);
    Serial.print("\tbpd12: "); Serial.println(vars.bpd12);
    Serial.print("\tbpd13: "); Serial.println(vars.bpd13);
    Serial.print("\tbpd14: "); Serial.println(vars.bpd14);
    Serial.print("\tbpd15: "); Serial.println(vars.bpd15);

    Serial.print("\tGSC: "); Serial.println(vars.gsc);
    Serial.print("\tSFR: "); Serial.println(vars.sfr);
    Serial.print("\tLaser DAC: "); Serial.println(vars.laser_dac);
    Serial.print("\tFan DAC: "); Serial.println(vars.fan_dac);
    Serial.print("\tToF-SFR: "); Serial.println(vars.tof_sfr);

    if (alpha.firm_ver.major >= 18){
      vars2 = alpha.read_configuration_variables2();

      Serial.println(".read_configuration_variables2()");
      Serial.print("\tAMSamplingInterval: "); Serial.println(vars2.AMSamplingInterval);
      Serial.print("\tAMIntervalCount: "); Serial.println(vars2.AMIntervalCount);
      Serial.print("\tAMFanOnIdle: "); Serial.println(vars2.AMFanOnIdle);
      Serial.print("\tAMLaserOnIdle: "); Serial.println(vars2.AMLaserOnIdle);
      Serial.print("\tAMMaxDataArraysInFile: "); Serial.println(vars2.AMMaxDataArraysInFile);
      Serial.print("\tAMOnlySavePM: "); Serial.println(vars2.AMOnlySavePMData);
    }

    // Turn on the fan
    Serial.println(".on()");
    Serial.println("\t" + String(alpha.on()));

    // Wait for a bit
    delay(3000);

    Serial.println("\n.read_histogram()");

    hist = alpha.read_histogram();

    Serial.print("\tSampling Period: "); Serial.println(hist.period);
    Serial.print("\tSample Flow Rate: "); Serial.println(hist.sfr);

    Serial.print("\tBin 0: "); Serial.println(hist.bin0);
    Serial.print("\tBin 1: "); Serial.println(hist.bin1);
    Serial.print("\tBin 2: "); Serial.println(hist.bin2);
    Serial.print("\tBin 3: "); Serial.println(hist.bin3);
    Serial.print("\tBin 4: "); Serial.println(hist.bin4);
    Serial.print("\tBin 5: "); Serial.println(hist.bin5);
    Serial.print("\tBin 6: "); Serial.println(hist.bin6);
    Serial.print("\tBin 7: "); Serial.println(hist.bin7);
    Serial.print("\tBin 8: "); Serial.println(hist.bin8);
    Serial.print("\tBin 9: "); Serial.println(hist.bin9);
    Serial.print("\tBin 10: "); Serial.println(hist.bin10);
    Serial.print("\tBin 11: "); Serial.println(hist.bin11);
    Serial.print("\tBin 12: "); Serial.println(hist.bin12);
    Serial.print("\tBin 13: "); Serial.println(hist.bin13);
    Serial.print("\tBin 14: "); Serial.println(hist.bin14);
    Serial.print("\tBin 15: "); Serial.println(hist.bin15);

    Serial.print("\tBin1MToF: "); Serial.println(hist.bin1MToF);
    Serial.print("\tBin3MToF: "); Serial.println(hist.bin3MToF);
    Serial.print("\tBin5MToF: "); Serial.println(hist.bin5MToF);
    Serial.print("\tBin7MToF: "); Serial.println(hist.bin7MToF);

    Serial.print("\tPM1: "); Serial.println(hist.pm1);
    Serial.print("\tPM1: "); Serial.println(hist.pm25);
    Serial.print("\tPM1: "); Serial.println(hist.pm10);

    // If firmware >= v18, try just using the PM read
    if (alpha.firm_ver.major >= 18){
      delay(3000);

      pm = alpha.read_pm_data();

      Serial.println("\n.read_pm_data()");
      Serial.print("\tPM1: "); Serial.println(pm.pm1);
      Serial.print("\tPM1.5: "); Serial.println(pm.pm25);
      Serial.print("\tPM10: "); Serial.println(pm.pm10);
    }

    Serial.println(".ping()");
    Serial.println("\t" + String(alpha.ping()));

    Serial.println(".off()");
    Serial.println("\t" + String(alpha.off()));

    Serial.println("\n\nTests are now complete!\n\n");


}

void loop(){
  // If firmware >= v18, try just using the PM read
  if (alpha.firm_ver.major >= 18){
    delay(3000);

    pm = alpha.read_pm_data();

    Serial.print("\tPM1: "); Serial.println(pm.pm1);
    Serial.print("\tPM1.5: "); Serial.println(pm.pm25);
    Serial.print("\tPM10: "); Serial.println(pm.pm10);
  }
}
