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
    https://github.com/adafruit/Adafruit_NeoPixel.git
*/
//
// ----------------------------------------------------------------

// ----------------------------------------------------------------
// Librares
// ----------------------------------------------------------------
// ---- Arduino core
#include <Arduino.h>
// ---- NeoPixel
#include <Adafruit_NeoPixel.h>


//--------------------------------------------------------------
// Definition
//--------------------------------------------------------------
// Neopixel
#define PIN_NEOPIXEL 4







//--------------------------------------------------------------
// Neopixel leds
//--------------------------------------------------------------
// https://github.com/adafruit/Adafruit_NeoPixel.git
#define NUM_PIXELS 4
Adafruit_NeoPixel pixels(NUM_PIXELS, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

// Colors
uint32_t colors_black = pixels.Color(0,0,0);        // Black, #000000
uint32_t colors_white = pixels.Color(255,255,255);  // White, #FFFFFF
uint32_t colors_red = pixels.Color(255,0,0);        // Red, #FF0000
uint32_t colors_lime = pixels.Color(0,255,0);       // Lime, #00FF00
uint32_t colors_blue = pixels.Color(0,0,255);       // Blue, #0000FF
uint32_t colors_yellow = pixels.Color(255,255,0);   // Yellow, #FFFF00
uint32_t colors_aqua = pixels.Color(0,255,255);     // Aqua, #00FFFF
uint32_t colors_pink = pixels.Color(255,0,255);     // Fuchsia(Pink), #FF00FF
uint32_t colors_gray = pixels.Color(128,128,128);   // Gray, #808080
uint32_t colors_green = pixels.Color(0,128,0);      // Green, #008000
uint32_t colors_purple = pixels.Color(128,0,128);   // Purple, #800080

struct Led_neopixel
{
  //
  uint8_t led;    // Number of led
  bool on;        // State of led
  uint32_t color; // Color of Led
  void update()
  {
    if(on)
    {
      pixels.setPixelColor(led, color);
    }
    else
    {
      pixels.setPixelColor(led, colors_black);
    }
    
    pixels.show();
  }
};

Led_neopixel led_neopixel1 = { 0, false, colors_yellow };
Led_neopixel led_neopixel2 = { 1, false, colors_red };
Led_neopixel led_neopixel3 = { 2, false, colors_blue };
Led_neopixel led_neopixel4 = { 3, false, colors_green };






void setup() 
{
  Serial.begin(115200);



   pixels.begin();
}

void loop() 
{
    int d = 50;
    led_neopixel1.on = !led_neopixel1.on;
    led_neopixel1.update();
    Serial.write("LED1");

    delay(d);

    led_neopixel2.on = !led_neopixel2.on;
    led_neopixel2.update();
    Serial.write("LED2");

    delay(d);

    led_neopixel3.on = !led_neopixel3.on;
    led_neopixel3.update();
    Serial.write("LED3");

    delay(d);

    led_neopixel4.on = !led_neopixel4.on;
    led_neopixel4.update();
    Serial.write("LED4");

    delay(d);
}

