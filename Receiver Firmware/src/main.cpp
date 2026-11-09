#include <Arduino.h>
#include <SPI.h>
#include<nRF24L01.h>
#include<RF24.h>

#define CE PA3
#define CSN PA4

RF24 radio(CE, CSN);
const byte address[6] = "00001";
String payload;

unsigned long unavailablefor;

void setup(){
  Serial.begin(115200);
  radio.begin();

  radio.setAutoAck(false);       //Acknowledgement packet

  radio.setDataRate(RF24_250KBPS);

  radio.setPALevel(RF24_PA_MAX);

  radio.setPayloadSize(sizeof(payload));
  radio.openReadingPipe(0, address);
  radio.startListening();
}

void loop(){
    if(radio.available() > 0){
        radio.read(&payload, sizeof(payload));
        Serial.println("Received: " + payload);
        unavailablefor = 0;
    }
    else{
        Serial.println("NOT CONNECTED!");
    }
    delay(1000);
}