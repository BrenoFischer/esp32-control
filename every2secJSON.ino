#define ARDUINOJSON_USE_DOUBLE 1
#define NUM_ARR 10
#include <ArduinoJson.h>

typedef struct {
  int id;
  unsigned char type;
  double lat;
  double lng;
  float high;
  String dat;
} MyJson;

MyJson arr[NUM_ARR];

StaticJsonDocument<200> doc;
int ind;

void setup() {
  ind = 0;
  arr[0].id = 1; arr[0].type = 'a'; arr[0].lat = 53.2839936; arr[0].lng = -9.302038; arr[0].high = 10.2; arr[0].dat = "teste";
  arr[1].id = 2; arr[1].type = 'b'; arr[1].lat = 52.6515985; arr[1].lng = -8.7001799; arr[1].high = 11.1; arr[1].dat = "test2";
  arr[2].id = 3; arr[2].type = 'c'; arr[2].lat = 52.6948993; arr[2].lng = -8.9329527; arr[2].high = 12.2; arr[2].dat = "teste3";
  arr[3].id = 4; arr[3].type = 'd'; arr[3].lat = 52.7593546; arr[3].lng = -8.9229964; arr[3].high = 13.1; arr[3].dat = "test4";
  arr[4].id = 5; arr[4].type = 'e'; arr[4].lat = 52.865394; arr[4].lng = -8.7187193; arr[4].high = 14.2; arr[4].dat = "teste5";
  arr[5].id = 6; arr[5].type = 'f'; arr[5].lat = 52.6661757; arr[5].lng = -9.4953154; arr[5].high = 15.1; arr[5].dat = "test6";
  arr[6].id = 7; arr[6].type = 'g'; arr[6].lat = 51.9228794; arr[6].lng = -9.7095488; arr[6].high = 16.2; arr[6].dat = "teste7";
  arr[7].id = 8; arr[7].type = 'h'; arr[7].lat = 51.8447055; arr[7].lng = -8.6990932; arr[7].high = 17.1; arr[7].dat = "test8";
  arr[8].id = 9; arr[8].type = 'i'; arr[8].lat = 52.2845609; arr[8].lng = -7.9121975; arr[8].high = 18.2; arr[8].dat = "teste9";
  arr[9].id = 10; arr[9].type = 'j'; arr[9].lat = 53.3230993; arr[9].lng = -6.5897182; arr[9].high = 19.1; arr[9].dat = "test10";
  delay(5000);
  
  Serial.begin(115200);
  while (!Serial) continue;
}

void loop() {
  delay(5000);
  
  doc["id"] = arr[ind].id;
  doc["type"] = arr[ind].type;
  doc["lat"] = arr[ind].lat;
  doc["lng"] = arr[ind].lng;
  doc["high"] = arr[ind].high;
  doc["data"] = arr[ind].dat;
  serializeJson(doc, Serial);
  Serial.println();
  
  if(ind == NUM_ARR - 1) ind = 0;
  else ind++;
}
