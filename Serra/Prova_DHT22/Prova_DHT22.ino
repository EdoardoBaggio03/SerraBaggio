
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 4

#define DHTTYPE    DHT22

DHT_Unified dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  sensors_event_t event;
  dht.temperature().getEvent(&event);
    Serial.println(event.temperature);

    dht.humidity().getEvent(&event);
    Serial.println(event.relative_humidity);
}
