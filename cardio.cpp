#include <stdio.h>
#include <stdlib.h>
#include "cardio.h"
#include <Arduino.h>




void capteur_et_calcul (int max_v) {

float a = analogRead(A0);
long b = millis();

while (a >= max_v) {

    Serial.print("temps:");
    Serial.print(millis());
    Serial.psrintln("tension:");
    Serial.print(a);
    delay(500);
    }
}



