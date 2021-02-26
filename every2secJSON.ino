#define ARDUINOJSON_USE_DOUBLE 1
#include <ArduinoJson.h>

StaticJsonDocument<128> doc;
int ind;

void setup() {
  Serial.begin(115200);
  Serial.println("Hello World!");
  ind = 0;
  while (!Serial) continue;
}

void loop() {
  delay(10000);
  if(ind == 0) {
    doc["id"] = "1";
    doc["type"] = "a";
    doc["lat"] = 53.2839936;
    doc["lng"] = -9.302038;
    doc["high"] = 10.2;
    doc["data"] = "teste";
    serializeJson(doc, Serial);
    Serial.println();
    ind = 1;
  }
  else {
    doc["id"] = "2";
    doc["type"] = "b";
    doc["lat"] = 52.6515985;
    doc["lng"] = -8.7001799;
    doc["high"] = 11.1;
    doc["data"] = "teste2";
    serializeJson(doc, Serial);
    Serial.println();
    ind = 0;
  }  
}
