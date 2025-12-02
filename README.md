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

- Power Bank 5V
  
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

- Upload this code to your Arduino board.

- Open Arduino's Serial Monitor to see the incoming data


