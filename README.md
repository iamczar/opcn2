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

# Documentation

A brief overview of the functionality of this package follows below. For a more thorough overview,
please check out the [python version of this code][1].

## `class OPCN2(uint8_t chip_select)`

> **chip_select**: Chip Select pin for SPI communication.

> *Returns*: An instance of the OPCN2 class.

### `bool ping()`

> Issues the `check_status` command and returns true if a connection is good.

### `bool on()`

> Turn on the OPC laser and fan. Returns `true` if it works.

### `bool off()`

> Turn off the OPC laser and fan. Returns `true` if it works.

### `bool write_config_variables( byte values[] )`

> ping details

### `bool write_config_variables2( byte values[] )`

> ping details

### `bool write_serial_number_string( byte values[] )`

> ping details

### `bool save_config_variables()`

> ping details

### `bool enter_bootloader()`

> ping details

### `bool set_fan_power( uint8_t value )`

> ping details

### `bool set_laser_power( uint8_t value )`

> ping details

### `bool toggle_fan( bool state )`

> ping details

### `bool toggle_laser( bool state )`

> ping details

### `String read_information_string()`

> Returns a String containing the OPC firmware version and serial number.

### `String read_serial_number()`

> ping details

### `Firmware read_firmware_version()`

> ping details

### `Status read_status()`

> ping details

### `ConfigVars read_configuration_variables()`

> asdasd

### `ConfigVars2 read_configuration_variables2()`

> asdasd

### `PMData read_pm_data()`

> asdasd

### `HistogramData read_histogram( bool convert_to_conc )`

> asdasda

[1]: https://github.com/dhhagan/py-opc
