#include <Wire.h>
#include <SoftwareSerial.h>
#include "sensors.h"
#include "comm.h"
#include <string.h>
#include "bluetooth.h"

void setup(){
  Serial.begin(9600);

  Com.Begin();

  Bt.Begin();

  DHTS.Begin();
}

void loop() {
  //Serial.println(Bt.received);
  
  //int x = rand();
  //Bt.log += x;
  //Com.log += x;
  Com.log += Bt.received;

  DHTS.Read();

  /* Bluetooth Receive System */
  Bt.Receive();

  /* Bluetooth Send System */
  Bt.Send();

  /* Communication Send System */
  Com.Send();
}


/*SoftwareSerial bluetooth(6, 7);

void setup() {
  Serial.begin(9600);
  Com.Begin();
  Serial.println("Started");
  bluetooth.begin(9600);
}

char* input;

bool testing = false;
String bluetooth_log = "";
String bluetooth_received = "";


void bluetooth_send_system(){
  bluetooth.println(bluetooth_log);
  link.println(bluetooth_log);
  bluetooth_log = "";
}

void loop(){
  bluetooth_received = "";
  int x = IR.Read();
  bluetooth_log += x;
  bluetooth_log += "|";

  bluetooth_send_system();

  Serial.println(bluetooth_received);

  delay(1000);
}*/