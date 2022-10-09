#pragma once
#include <string.h>
#include <SoftwareSerial.h>

#define BT_PIN1 6
#define BT_PIN2 7

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
        received = bt.readString();
    }
}

void BLUETOOTH::Send(){
    bt.println(log);
    log = "";
}