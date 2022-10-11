#pragma once
#include "DHT.h"

unsigned long previousMillis = 0UL;
unsigned long interval = 1000UL;

struct IR_SENSOR {
  const int Pin = 4;
  int CurrentValue = 0;
  int Read();
  int handleChange(int value);
};
IR_SENSOR IR;

int IR_SENSOR::Read(){
  return digitalRead(IR.Pin);
}

int IR_SENSOR::handleChange(int value){
  if(value != IR.CurrentValue){
    IR.CurrentValue = value;
    return value;
  }
  return -1;
}

struct DHT_SENSOR {
  const int Pin = 5;
  float temperature = 0;
  float humidity = 0;
  void Begin();
  void Read();
};
DHT_SENSOR DHTS;

DHT dht(DHTS.Pin, DHT11);

void DHT_SENSOR::Begin(){
  dht.begin();
}

void DHT_SENSOR::Read(){
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval)
  {
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();
 	  previousMillis = currentMillis;
    //Serial.println("TEMPERATURE: " + String(temperature));
    //Serial.println("HUMIDITY: " + String(humidity));
  }
}

