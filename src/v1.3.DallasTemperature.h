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
    https://github.com/PaulStoffregen/OneWire.git

    https://github.com/Gbertaz/NonBlockingDallas.git

*/
//
// ----------------------------------------------------------------

// ----------------------------------------------------------------
// Librares
// ----------------------------------------------------------------
// ---- Arduino core
#include <Arduino.h>
// ---- Dallas Temperature DS18B20
#include <Wire.h>
#include <DallasTemperature.h>
#include <NonBlockingDallas.h>


//--------------------------------------------------------------
// Definition
//--------------------------------------------------------------
// DS18B20 temperature sensor
#define ONE_WIRE_BUS 15  


//--------------------------------------------------------------
// DS18B20 - Dallas Temp sensor Definition
//--------------------------------------------------------------
#define TIME_INTERVAL 1500                      //Time interval among sensor readings [milliseconds]
int deviceCount = 0;
float temp[6];
char data[100];

// vytvoření instance oneWireDS z knihovny OneWire
OneWire oneWireDS(ONE_WIRE_BUS);
// vytvoření instance senzoryDS z knihovny DallasTemperature
DallasTemperature dallasTemp(&oneWireDS);
NonBlockingDallas sensorDs18b20(&dallasTemp);    //Create a new instance of the NonBlockingDallas class

//unsigned long previousMillisTemp1=0;
//unsigned long previousMillisTemp2=1000;

//int intervalTemp1 = 2000;
//int intervalTemp2 = 2000;

//Invoked at every sensor reading (TIME_INTERVAL milliseconds)
void handleIntervalElapsed(int deviceIndex, int32_t temperatureRAW)
{
  //sprintf(data, "Temperature: %.3f °C", temperature);
  //Serial.print(data);
  //writeTemperature(temperature);
  float tC = sensorDs18b20.rawToCelsius(temperatureRAW);
  String vystup = "Temperature: " + String(tC);

  //display.setCursor(15, 0);     // Start at top-left corner
  //display.setCursor(15, 0);     // Start at top-left corner
  //display.setTextSize(1);      // Normal 1:1 pixel scale
  //display.setTextColor(WHITE, BLACK); // Draw white text
  //display.setCursor(15, 0);     // Start at top-left corner
  //display.print("PES:");

  /*
   *  DO SOME AMAZING STUFF WITH THE TEMPERATURE
   */
}

//Invoked ONLY when the temperature changes between two sensor readings
void handleTemperatureChange(int deviceIndex, int32_t temperatureRAW)
{
  //sprintf(data, "Temperature: %.3f °C", temperature);
  //Serial.print(data);
  //writeTemperature(temperature);
  float tC = sensorDs18b20.rawToCelsius(temperatureRAW);
  String vystup = "Temperature: " + String(tC);
  /*
   *  DO SOME AMAZING STUFF WITH THE TEMPERATURE
   */
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

  // ========================== DS18B20 =============================
  //dallasTemp.begin();  // Otevření knihovny
  //deviceCount = dallasTemp.getDeviceCount();

  // Inicializace senzoru procházejícího rozlišením, měrnou jednotkou a intervalem čtení [milisekundy]
  sensorDs18b20.begin(NonBlockingDallas::resolution_12, TIME_INTERVAL);
  //Callbacks
  sensorDs18b20.onIntervalElapsed(handleIntervalElapsed);
  sensorDs18b20.onTemperatureChange(handleTemperatureChange);

  // Následující funkci zavolejte, kdykoli budete chtít požádat o nový údaj o teplotě, aniž byste čekali, než uplyne TIME_INTERVAL
  sensorDs18b20.requestTemperature();


}

void loop() 
{
  int d = 1000;

}

