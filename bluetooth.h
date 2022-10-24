#pragma once
#include <string.h>
#include <SoftwareSerial.h>

#define BT_PIN1 4
#define BT_PIN2 5

SoftwareSerial bt(BT_PIN1, BT_PIN2);

struct BLUETOOTH {
    void Begin();
    void Receive();
    void Send();
    String log = "";
    String received = "";
};
BLUETOOTH Bt;

void BLUETOOTH::Begin() {
    bt.begin(9600);
}

void BLUETOOTH::Receive(){
    received = "";
    if(bt.available()){
        char c = bt.read();
        received += c;
        Serial.println(c);
    }
}

void BLUETOOTH::Send(){
    if(log != ""){
        bt.println(log);
        log = "";
    }
}