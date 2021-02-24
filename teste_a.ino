#include <ArduinoJson.h>

String string_test;
StaticJsonDocument<200> doc;
  // Allocate the JSON document
  //
  // Inside the brackets, 200 is the RAM allocated to this document.
  // Don't forget to change this value to match your requirement.
  // Use arduinojson.org/v6/assistant to compute the capacity.

  // StaticJsonObject allocates memory on the stack, it can be
  // replaced by DynamicJsonDocument which allocates in the heap.
  //
  // DynamicJsonDocument  doc(200);


void setup() {
  Serial.begin(115200);
  Serial.println("Hello World!");
  
  while (!Serial) continue;
  
  // Add values in the document
  //
  doc["sensor"] = "gps";
  doc["time"] = 1351824120;
}

void loop() {
  while(Serial.available())  
  {  
      string_test = Serial.readString( ); 
      
      // Add an array.
      //
      JsonArray data = doc.createNestedArray("data");
      
      if (string_test.equals("A\n") || string_test.equals("a\n")) {
        data.add(48.756080);
        data.add(2.302038);
        //Serial.println("JSON type A");
        // Generate the minified JSON and send it to the Serial port.
        //
        serializeJson(doc, Serial);
        // The above line prints:
        // {"sensor":"gps","time":1351824120,"data":[48.756080,2.302038]}
        Serial.println();
        // Generate the prettified JSON and send it to the Serial port.
        //
        //serializeJsonPretty(doc, Serial);
        // The above line prints:
        // {
        //   "sensor": "gps",
        //   "time": 1351824120,
        //   "data": [
        //     48.756080,
        //     2.302038
        //   ]
        // }
        //Serial.println();
      } else if (string_test.equals("B\n") || string_test.equals("b\n")) {
          data.add(53.2839936);
          data.add(-9.1187864);
          //Serial.println("JSON type B");
          serializeJson(doc, Serial);
          Serial.println();
          //serializeJsonPretty(doc, Serial);
          //Serial.println();
      } else {
        Serial.println("Type Unknown");
      }
  }  
}
