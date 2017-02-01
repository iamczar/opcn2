# Documentation

A brief overview of the functionality of this package follows below. For a more thorough overview,
please check out the [python version of this code][1].

### `class OPCN2(uint8_t chip_select)`

> **chip_select**: Chip Select pin for SPI communication.

> *Returns*: An instance of the OPCN2 class.

#### `bool ping()`

> Issues the `check_status` command and returns true if a connection is good.

#### `bool on()`

> Turn on the OPC laser and fan. Returns `true` if it works.

#### `bool off()`

> Turn off the OPC laser and fan. Returns `true` if it works.

#### `bool write_config_variables( byte values[] )`

> **NOT IMPLEMENTED (yet)**

#### `bool write_config_variables2( byte values[] )`

> **NOT IMPLEMENTED (yet)**

#### `bool write_serial_number_string( byte values[] )`

> **NOT IMPLEMENTED (yet)**

#### `bool save_config_variables()`

> Saves the configuration variables once changed. To be used in conjunction with
> `enter_bootloader`.

> *Returns:* boolean (true if successfull).

#### `bool enter_bootloader()`

> Enter into the bootloader to make permanent changes to configuration variables.
> Use only if you know what you're doing!

> *Returns:* boolean (true if successfull).

#### `bool set_fan_power( uint8_t value )`

> **value**: a uint8_t that corresponds to the desired fan power. Permitted values
> are between 0 - 255.

> *Returns:* boolean (true if successfull).

#### `bool set_laser_power( uint8_t value )`

> **value**: a uint8_t that corresponds to the desired laser power. Permitted values
> are between 0 - 255.

> *Returns:* boolean (true if successfull).

#### `bool toggle_fan( bool state )`

> **state**: true to turn the fan on, and false to turn it off.

> *Returns:* boolean (true if successfull).

#### `bool toggle_laser( bool state )`

> **state**: true to turn the laser on, and false to turn it off.

> *Returns:* boolean (true if successfull).

#### `String read_information_string()`

> Returns a String containing the OPC firmware version and serial number.

#### `String read_serial_number()`

> **Only available for firmware versions >= 18**

> *Returns:* a String containing the serial number.

#### `Firmware read_firmware_version()`

> *Returns*: a structure containing: `Firmware.major` and `Firmware.minor`.

#### `Status read_status()`

> **Only available for firmware versions >= 18**

> *Returns*: structure containing: `Status.fanON`, `Status.laserON`,
> `Status.fanDAC`, and `Status.laserDAC`.

#### `ConfigVars read_configuration_variables()`

> *Returns:* the ConfigVars structure which contains: `ConfigVars.bb0` -
> `ConfigVars.bb14`, `ConfigVars.bpv0` - `ConfigVars.bpv15`, `ConfigVars.bpd0` -
> `ConfigVars.bpd15`, `ConfigVars.bsvw0` - `ConfigVars.bsvw15`, `ConfigVars.gsc`,
> `ConfigVars.sfr`, `ConfigVars.laser_dac`, `ConfigVars.fan_dac`, and `ConfigVars.tof_sfr`.

#### `ConfigVars2 read_configuration_variables2()`

> **Only available for firmware versions >= 18**

> *Returns:* the ConfigVars2 structure which contains: `ConfigVars2.AMSamplingInterval`,
> `ConfigVars2.AMIntervalCount`, `ConfigVars2.AMFanOnIdle`, `ConfigVars2.AMLaserOnIdle`,
> `ConfigVars2.AMMaxDataArraysInFile`, and `ConfigVars2.AMOnlySavePMData`.

#### `PMData read_pm_data()`

> **Only available for firmware versions >= 18**

> *Returns:* the PMData structure containing: `PMData.pm1`, `PMData.pm25`, and `PMData.pm10`.

#### `HistogramData read_histogram( bool convert_to_conc )`

> **convert_to_conc:** (boolean) If true, the raw histogram is converted to concentration
> (#/cm3) by dividing the raw value by the product of the sampling period and the sample flow rate.

> *Returns:* the HistogramData structure containing: `period`, `sfr`, `bin0` - `bin15`,
> `bin1MToF`, `bin3MToF`, `bin5MToF`, `bin7MToF`, `temp_pressure`, `checksum`,
> `pm1`, `pm25`, and `pm10`.
