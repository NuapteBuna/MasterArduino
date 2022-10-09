#pragma once
#include <string.h>
#include <SoftwareSerial.h>

#define COM_PIN1 2
#define COM_PIN2 3

SoftwareSerial link(COM_PIN1, COM_PIN2);

struct COMMUNICATION{
    void Begin(int baud_rate = 9600);
    void Send();
    void WriteBytes(char* buffer, int size);
    void WriteString(String buffer);
    void WriteBytesFromString(String buffer);
    char* CurrentValue = {""};
    String log = "";
};
COMMUNICATION Com;

void COMMUNICATION::Begin(int baud_rate = 9600){
    link.begin(baud_rate);
}

void COMMUNICATION::Send(){
    link.println(log);
    log = "";
}

void COMMUNICATION::WriteBytes(char* buffer, int size){
    link.write(buffer, size);
}

void COMMUNICATION::WriteString(String buffer){
    link.write(buffer.c_str());
}

void COMMUNICATION::WriteBytesFromString(String buffer){
    char* cbuffer;
    buffer.toCharArray(cbuffer, buffer.length());
    link.write(cbuffer, buffer.length());
}