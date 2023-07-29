#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

Adafruit_BMP280 bmp; 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);
  
  if (!bmp.begin(0x76)) {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  //display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
}

void loop() {
  float altitude = bmp.readAltitude(1013.25);
  Serial.print("Altitude = ");
  Serial.print(altitude);
  Serial.println(" meters");

  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(1);
  display.print("OPEN PARACHUTE IN:");
  display.setCursor(0, 10);
  display.setTextSize(2);
  display.print(altitude);
  display.print(" m");
  display.display();
  delay(500);
}
