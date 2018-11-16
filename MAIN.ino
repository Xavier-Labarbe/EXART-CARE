#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>
#include "HEART.h"
#include "PARAM.h"

void setup() {
	long w = 0;
	int n, i, j, l;
	for(int n=0; n<= 13; n++) {
		pinMode(n, OUTPUT);
	}

	switch (MODE) {
		case 1:
			allLeds(w, n, i);
			break;
		case 2:
			chenilleArt(w, n, i);
			break;
		case 3:
			one_on_Two(w, j, i);
			break;
		case 4:
			one_on_three(w, n, i);
			break;
		case 5:
			int l = Serial.read();
			whatever_yall_want(w, l, i);
			break;
		}
}


void loop() {

}




