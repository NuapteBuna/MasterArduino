#pragma once

#define IR_PIN 4

struct IR_SENSOR {
  const int Pin = IR_PIN;
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