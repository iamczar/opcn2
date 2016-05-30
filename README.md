# opcn2
C++ Library for the Alphasense OPC-N2 particle counter

![Alphasense OPC-N2](https://github.com/dhhagan/opcn2/blob/master/opcn2-photon.jpg)


# About

The Alphasense OPC-N2 is an optical particle counter for use in indoor and outdoor particle monitoring. This library
makes it easy to operate the OPC-N2 from a Particle Photon, Particle Electron, or Arduino (not yet tested).

# Example Usage

Two examples are located in the examples folder.

  1. opcn2-examples.cpp: Normal Example Run File
  2. tests.cpp: Runs through a solid portion of the methods and prints the results to the console.

# Recommended Components

In order to run the Alphasense OPC-N2 from a Particle Photon or Electron, you will need the Alphasense OPC-N2 and one of the microcontrollers from Particle. You will also need the appropriate 30 AWG wiring and either a breadboard, or alternate way to connect the OPC-N2 to the Particle controller.

# Circuit Diagram

Connect according to the table below, and as seen in the figure below.

| OPC-N2 Pin Number | Particle Photon Pin |
|:-----------------:|:-------------------:|
| 1 (GND) | GND |
| 2 (/CS) | A2 |
| 3 (MOSI) | A5 |
| 4 (MISO) | A4 |
| 5 (CLK) | A3 |
| 6 (VCC) | VIN |



![Alphasense OPC-N2](https://github.com/dhhagan/opcn2/blob/master/opcn2-photon-wiring.png)
