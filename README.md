# Sensirion Raspberry Pi I2C SDP Driver

This document explains how to set up the SDP sensor to run on a Raspberry Pi
using the provided code.

<center><img src="images/SDP8xx.png" width="250px"><img src="images/SDP3x.png" width="250px"></center>


Click [here](https://www.sensirion.com/en/flow-sensors/differential-pressure-sensors/test-your-sdp3x-differential-pressure-sensor-with-the-evaluation-kit-ek-p4/) to learn more about the SDP3x Sensor Evaluation Kit.

Click [here](https://www.sensirion.com/en/flow-sensors/differential-pressure-sensors/evaluation-kit-for-sensors-of-the-sdp800-series/) to learn more about the SDP800 series Sensor Evaluation Kit.


## Setup Guide

### Connecting the Sensor

Your sensor has the four different connectors: VCC, GND, SDA, SCL. Use
the following pins to connect your Sdp:

 *Sdp*  |    *Raspberry Pi*
 :------: | :------------------:
   VCC    |        Pin 1
   GND    |        Pin 6
   SDA    |        Pin 3
   SCL    |        Pin 5

<center><img src="images/GPIO-Pinout-Diagram.png" width="900px"></center>

### Raspberry Pi

- [Install the Raspberry Pi OS on to your Raspberry Pi](https://projects.raspberrypi.org/en/projects/raspberry-pi-setting-up)
- [Enable the I2C interface in the raspi-config](https://www.raspberrypi.org/documentation/configuration/raspi-config.md)
- Download the driver for the [Sensirion Github Page](https://github.com/Sensirion/raspberry-pi-i2c-sdp) and extract the `.zip` on your Raspberry Pi
- Compile the driver
    1. Open a [terminal](https://www.raspberrypi.org/documentation/usage/terminal/?)
    2. Navigate to the driver directory. E.g. `cd ~/raspberry-pi-i2c-sdp`
    3. Run the `make` command to compile the driver

       Output:
       ```
       rm -f sdp_i2c_example_usage
       cc -Os -Wall -fstrict-aliasing -Wstrict-aliasing=1 -Wsign-conversion -fPIC -I. -o sdp_i2c_example_usage  sdp_i2c.h sdp_i2c.c sensirion_i2c_hal.h sensirion_i2c.h sensirion_i2c.c \
           sensirion_i2c_hal.c sensirion_config.h sensirion_common.h sensirion_common.c sdp_i2c_example_usage.c
       ```
- Test your connected sensor
    - Run `./sdp_i2c_example_usage` in the same directory you used to
      compile the driver.

      Output:
      ```
      Product number: 0x03020b01
      Serial Number: 1902067650
      Differential pressure: -0.17 Pa
      Temperature: 28.80 °C
      Differential pressure: -0.03 Pa
      Temperature: 28.80 °C
      Differential pressure: -0.03 Pa
      Temperature: 28.80 °C
      Differential pressure: -0.03 Pa
      ...
      ```

## Troubleshooting

### Building driver failed

If the execution of `make` in the compilation step 3 fails with something like

> -bash: make: command not found

your RaspberryPi likely does not have the build tools installed. Proceed as follows:

```
$ sudo apt-get update
$ sudo apt-get upgrade
$ sudo apt-get install build-essential
```

### Initialization failed

```
Error executing sdp_get_serial_number(): -1
Error executing sdp_read_product_identifier(): -1
Error executing sdp_start_continuous_measurement_with_diff_pressure_t_comp_and_averaging(): -1
Error executing sdp_read_measurement(): -1
```

then go through the below troubleshooting steps.

-   Ensure that you connected the sensor correctly: All cables are fully
    plugged in and connected to the correct pin.
-   Ensure that I2C is enabled on the Raspberry Pi. For this redo the steps on
    "Enable the I2C interface in the raspi-config" in the guide above.
-   Ensure that your user account has read and write access to the I2C device.
    If it only works with user root (`sudo ./sdp_i2c_example_usage`), it's
    typically due to wrong permission settings. See the next chapter how to solve this.

### Missing I2C permissions

If your user is missing access to the I2C interface you should first verfiy
the user belongs to the `i2c` group.

```
$ groups
users input some other groups etc
```
If `i2c` is missing in the list add the user and restart the Raspberry Pi.

```
$ sudo adduser your-user i2c
Adding user `your-user' to group `i2c' ...
Adding user your-user to group i2c
Done.
$ sudo reboot
```

If that did not help you can make globally accessible hardware interfaces
with a udev rule. Only do this if everything else failed and you are 
reasoably confident you are the only one having access to your Pi.

Go into the `/etc/udev/rules.d` folder and add a new file named 
`local.rules`.
```
$ cd /etc/udev/rules.d/
$ sudo touch local.rules
```
Then add a single line `ACTION=="add", KERNEL=="i2c-[0-1]*", MODE="0666"` 
to the file with your favorite editor.
```
$ sudo vi local.rules
```
