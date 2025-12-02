# DATA LOGGING WITH ARDUINO

In this tutorial, you will learn **how to log sensor data** to a .CSV file using an Arduino.

We will use a [DHT11](https://github.com/kingston-hackSpace/DHT) temperature-and-humidity sensor as an example, but the same approach can be applied to any other sensor you want to log.

By the end of this tutorial, you will be able to record sensor readings over time and save them for analysis on your computer.

----
# TUTORIAL

----
### HARDWARE

- Arduino UNO

- LED

- 220 ohms resistor

- DHT11 sensor

- RTC module + 3V battery

- SD Card module + micro SD Card

  
----
### WIRING

Diagram reference image : [here](https://github.com/kingston-hackSpace/DataLogging_DHT11/blob/main/DataLogging_DHT11_bb.jpg)

|Arduino |SD CARD Module |
|------- |-------        |
| GND    | GND           |
| pin 13 | CLK           |
| pin 12 | Do            |
| pin 11 | Di            |
| pin 10 | CS            |
| 5V     | 5V            |


|Arduino |DHT11 sensor     |
|------- |---------------  |
| GND    | GND             |
| 5V     | 5V or VCC or (+)|
| pin 2  | S (signal) or DAT (data)|


|Arduino |RTC Module     |
|------- |-------        |
| GND    | GND           |
| 5V     | VCC           |
| pin A4 | SDA           |
| pin A5 | SCL           |


|Arduino        |LED              |
|-------------- |-------          |
| GND           | LED (+) lead    |
| pin 7         | resistor 220 ohms ---- LED (-) lead |


----
### CODE AND INSTRUCTIONS

- Download the following libraries:
  
    - [RTClib](https://github.com/kingston-hackSpace/DataLogging_DHT11/blob/main/Libraries/RTClib.zip)
      
    - [DHT](https://github.com/kingston-hackSpace/DataLogging_DHT11/blob/main/Libraries/DHT_sensor_library.zip)
      
    - [Adafruit_Sensor](https://github.com/kingston-hackSpace/DataLogging_DHT11/blob/main/Libraries/Adafruit_Unified_Sensor.zip)

    - [Adafruit_BusIO](https://github.com/kingston-hackSpace/DataLogging_DHT11/blob/main/Libraries/Adafruit_BusIO.zip)
 
- Once donwloaded, follow the installation instructions. In this case, we install via [Importing a .zip Library](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries/)

- Download [this code](https://github.com/kingston-hackSpace/DataLogging_DHT11/blob/main/DataLogging_DHT11.ino)

- Insert the SD card into the SD card module (if you haven’t done it already)

- Plug The Arduino Board to your computer and upload the code


**CONGRATULATIONS!** You have built an environmental sensor device that records data every 5
seconds and saves it in .CSV format.


----
# WHAT TO DO NEXT?
You can now modify the code to customise it according to your own ideas, goals, or project requirements. For example:

 - Adjust the data logging interval (e.g. every 1 minute instead of every 5 seconds)
 
 - Change the sensor output units (e.g. from Celsius to Fahrenheit)
 
 - Modify RTC usage (e.g. log only the date, not the time)
 
 - Alter LED behaviour
 
 - Integrate additional sensors for more environmental data



