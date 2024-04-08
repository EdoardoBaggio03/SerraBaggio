#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>
#include "RTClib.h"

RTC_DS3231 rtc;

  #define TFT_CS        10
  #define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
  #define TFT_DC         8

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
int minuti;
void setup() {
  // put your setup code here, to run once:

    Serial.begin(57600);

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }
tft.init(240, 320); 
tft.fillScreen(ST77XX_BLACK);
tft.invertDisplay(false);



}

void loop() {
   DateTime now = rtc.now();
  // put your main code here, to run repeatedly:
tft.setTextSize(4);

tft.setCursor(10,10);
    tft.print(now.hour(), DEC);
    tft.print(':');
    tft.print(now.minute(), DEC);
    tft.setCursor(10,60);
    tft.setTextSize(2);
        tft.print(now.day(), DEC);
    tft.print('/');
    tft.print(now.month(), DEC);
    tft.print('/');
    tft.print(now.year(), DEC);
Serial.print(now.minute(), DEC);
if(now.minute()!=minuti){
tft.fillScreen(ST77XX_BLACK);
minuti = now.minute();
}
//tft.drawRect(0,0,240,320,ST77XX_WHITE);

}
