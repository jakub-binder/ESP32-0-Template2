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



//--------------------------------------------------------------
// OLED Definition
//--------------------------------------------------------------
// https://github.com/adafruit/Adafruit_SSD1306.git
// https://github.com/adafruit/Adafruit-GFX-Library

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int tKelvin, tCelsius, tFahrenheit;
char _buffer[8];

void writeTemperature(float temperature) 
{
  //tCelsius = temperature * 10;
  // print temperature in degree Celsius
  //if (tCelsius >= 1000)    // if temperature >= 100.0 °C
    sprintf(_buffer, " %.1f C", temperature);
  //else
    //sprintf(_buffer, " %02f.%1f C", tCelsius / 10, tCelsius % 10);

  display.setTextSize(2);   // text size = 2

  display.setCursor(23, 10);
  display.print(_buffer);
  // print degree symbols ( ° )
  display.drawCircle(88, 12, 2, WHITE);
  display.display();
}

void SetInfo(String mess)
{
  // prvni rada od spodu, velikost 10px
  display.setTextSize(1);
  display.setCursor(0,56);
  display.print(mess);
  display.display();
  // druha rada od spodu velikost 10px
  //display.setTextSize(1);
  //display.setCursor(0,46);
  //display.print("ygq3456789abcdefghijk");
}


//--------------------------------------------------------------
// Serial
//-------------------------------------------------------------- 
void sendString(const String &str)
{
  // Prevod retezce na pole bytu
  uint8_t* data = (uint8_t*)str.c_str();
  size_t length = str.length();

  // Odeslani dat pomoci Serial.write
  Serial.write(data, length);
}


//--------------------------------------------------------------
// Setup
//-------------------------------------------------------------- 
void setup() 
{
  Serial.begin(115200);

  // ========================== OLED ==============================
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();

  // ------ Set Temperature
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE, BLACK); // Draw white text
  display.setCursor(15, 0);     // Start at top-left corner
  display.print("TEMPERATURE:");
  display.display();        // update the display

  // ------- Set Info text
  SetInfo("Info:");


}

void loop() 
{
  int d = 1000;

  for (int i = 0; i < 10; i++)
  {
    String vystup = "Numb: " + String(i) + " -- ";
    
    // Odeslani pomoci Serial.print(String)
    //Serial.print(vystup);

    // Odeslani pomoci Serial.write(byte[])
    sendString(vystup);

    SetInfo("               ");
    SetInfo(vystup);
    writeTemperature(i* 3);
    delay(d);
  }
}

