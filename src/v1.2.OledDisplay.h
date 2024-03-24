// ----------------------------------------------------------------
// Testovano na:
// Arduino IDE: ESP32_IoT: Board / ESP32 Wrower Module
// VSCode: denky32
// 
//
// v1.1_Neopixel
// -----------------------------------------------------------------
// platform.ini

/*
[env:esp32doit-devkit-v1]
platform = espressif32
board = esp32doit-devkit-v1
framework = arduino
monitor_speed = 115200
lib_deps =
    https://github.com/adafruit/Adafruit_SSD1306.git
    https://github.com/adafruit/Adafruit-GFX-Library

*/
//
// ----------------------------------------------------------------

// ----------------------------------------------------------------
// Librares
// ----------------------------------------------------------------
// ---- Arduino core
#include <Arduino.h>
// ---- LCD 1306
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


//--------------------------------------------------------------
// Definition
//--------------------------------------------------------------














void setup() 
{
  Serial.begin(115200);




}

void loop() 
{
  int d = 200;

  Serial.write("Status 1");
  delay(d);


  Serial.write("Status 2");
  delay(d);

}

