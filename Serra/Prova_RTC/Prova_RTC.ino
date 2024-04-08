#include "RTClib.h"

RTC_DS3231 rtc;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
    DateTime now = rtc.now();
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    delay(200);
}
