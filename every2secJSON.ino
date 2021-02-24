#define ARDUINOJSON_USE_DOUBLE 1
#include <ArduinoJson.h>

String string_test;
StaticJsonDocument<128> doc;

void setup() {
  Serial.begin(115200);
  Serial.println("Hello World!");
  
  while (!Serial) continue;
}

void loop() {
  while(Serial.available())  
  {  
      string_test = Serial.readString( ); 
      
      if (string_test.equals("A\n") || string_test.equals("a\n")) {
        doc["id"] = "1";
        doc["type"] = "a";
        doc["lat"] = 56.756080;
        doc["lng"] = -9.302038;
        doc["high"] = 10.2;
        doc["data"] = "teste";

        serializeJson(doc, Serial);
        Serial.println();
      } else if (string_test.equals("B\n") || string_test.equals("b\n")) {
          doc["id"] = "2";
          doc["type"] = "b";
          doc["lat"] = 53.2839936;
          doc["lng"] = -9.1187864;
          doc["high"] = 11.1;
          doc["data"] = "teste2";

          serializeJson(doc, Serial);
          Serial.println();
      } else {
        Serial.println("Type Unknown");
      }
  }  
}
