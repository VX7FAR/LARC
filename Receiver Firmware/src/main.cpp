#include <Arduino.h>

#define LED_PIN PC13

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    pinMode(A1, OUTPUT);
    digitalWrite(A1, HIGH);
}

void loop()
{
    digitalWrite(LED_PIN, LOW);  // LED ON
    delay(1000);

    digitalWrite(LED_PIN, HIGH); // LED OFF
    delay(1000);
}