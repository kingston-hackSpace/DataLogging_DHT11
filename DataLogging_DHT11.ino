/* DATA LOGGING with Arduino

BRIEF: 
Log data (in .CSV format) from a 
DHT11 sensor (humidity and temperature) onto an SDcard.
Each entry includes date and time information provided 
by an RTC module, recorded every 5 seconds (modifiable).

HARDWARE: 
Arduino UNO
SD Card Module
RTC Module
DHT11 sensor
LED
Resistor 202ohms

*/

#include <Wire.h>
#include <RTClib.h>
#include <SD.h>
#include <SPI.h>
#include "DHT.h"

#define DHTPIN 2           // DHT11 data pin
#define DHTTYPE DHT11      // DHT 11
#define CSPIN 10           // SD card CS pin
#define LEDPIN 7           // Status LED pin

DHT dht(DHTPIN, DHTTYPE); // create dht object of class DHT
RTC_DS3231 rtc; // create rtc object of class RTC_DS3231
File dataFile; // create dataFile of class File

void setup() {
  Serial.begin(9600);
  dht.begin();
  Wire.begin();
  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, LOW);

  // Initialise RTC
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, setting the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  // Initialise SD card
  Serial.print("Initializing SD card...");
  if (!SD.begin(CSPIN)) {
    Serial.println("Card failed or not present!");
    while (1);
  }
  Serial.println("SD card initialised.");

  // Create / open log file
  dataFile = SD.open("DATALOG.CSV", FILE_WRITE);
  if (dataFile) {
    dataFile.println("Date,Time,Temperature (°C),Humidity (%)");
    dataFile.close();
  }
}

void loop() {
  DateTime now = rtc.now();
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  // Format date and time
  char dateBuffer[12];
  sprintf(dateBuffer, "%02d/%02d/%04d", now.day(), now.month(), now.year());
  char timeBuffer[10];
  sprintf(timeBuffer, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());

  // Turn on LED before writing
  digitalWrite(LEDPIN, HIGH);

  // Write to SD card
  dataFile = SD.open("DATALOG.CSV", FILE_WRITE);
  if (dataFile) {
    dataFile.print(dateBuffer);
    dataFile.print(",");
    dataFile.print(timeBuffer);
    dataFile.print(",");
    dataFile.print(t, 1);
    dataFile.print(",");
    dataFile.println(h, 1);
    dataFile.close();

    // Keep LED on for a second to show success
    delay(1000);
  } else {
    Serial.println("Error opening datalog file!");
    // Blink LED quickly 3 times to indicate an error
    for (int i = 0; i < 3; i++) {
      digitalWrite(LEDPIN, HIGH);
      delay(150);
      digitalWrite(LEDPIN, LOW);
      delay(150);
    }
  }

  // Turn off LED after recording
  digitalWrite(LEDPIN, LOW);

  // Print to Serial Monitor
  Serial.print(dateBuffer);
  Serial.print(" ");
  Serial.print(timeBuffer);
  Serial.print(" | Temp: ");
  Serial.print(t, 1);
  Serial.print(" °C | Hum: ");
  Serial.print(h, 1);
  Serial.println(" %");

  delay(5000); // Log every 5 seconds
}
