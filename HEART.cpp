#include <Arduino.h>
#include "HEART.h"
#include "PARAM.h"

int bpm(){
  unsigned long Temp = millis();
  int Potar = analogRead(A0);
  int Poul;
  Poul= map(Potar, 0, 1023, 273, 1200);
  long BPM = map(Poul, 273, 1200, 220, 50);
  String X = String(BPM);
  String T = String(Temp);
  Serial.print(String(X+";"+T+"$\n"));
  return Poul;
}

void allLeds(long w, int n, int i) {
    w = bpm();
    for(n=2; n<=13; n++) {
    	digitalWrite(n, HIGH);
    }
    delay(w);
    for(n=2; n<=13; n++) {
    	digitalWrite(n, LOW);
    }
    delay(w);
}

void chenilleArt(long w, int n, int i) {
	  w = bpm();
	  for (int n=2; n <=13 ;n++) {
	    digitalWrite(n, HIGH);
	    delay(w);
	    digitalWrite(n, LOW);
	    delay(w);
	  }
}


void one_on_Two(long w, int j, int i) {
	  w = bpm();
	  for(j=2; j <= 13; j+2) {
	  digitalWrite(j, HIGH);
	  delay(w);
	  digitalWrite(j, LOW);
	  delay(w);
	  }
}

void one_on_three(long w, int n, int i) {
	  w= bpm();
	  for(n=2; n<=13; (2*n)+1) {
		  digitalWrite(n,HIGH);
		  delay(w);
		  digitalWrite(n, LOW);
		  delay(w);
	  }
}

void whatever_yall_want(long w, int l, int i) {
	  w= bpm();
	  digitalWrite(l, HIGH);
	  delay(w);
	  digitalWrite(l, LOW);
	  delay(w);
}





