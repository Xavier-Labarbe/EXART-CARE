#include "generateCode.h"



void setup (FILE* file, int mode_data) {
	file = fopen("C:\\Users\\Léo\\Desktop\\PROJET ELECTROCARDIOGRAMME\\PROJET1_UNO\\PARAM.h","w+");

	if(file != 0) {
		write(file, mode_data);
	} else {
		printf("ERROR 404");
		fflush(stdout);
	}
}


void write (FILE* a, int mode_data) {
	fprintf(a,"#include <stido.h>\n#include <stdlib.h>\n#include <Arduino.h>\n\n#ifndef PARAM_H_\n#define PARAM_H_\n#define MODE %d\n#endif", mode_data);
}



