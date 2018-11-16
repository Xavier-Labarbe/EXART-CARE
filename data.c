#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"


void setupReading(FILE* file) {
	file = 0;

	if (file != 0) {
		file = fopen("","r");
	} else {
		printf("ERROR SYNTAX");
		fflush(stdout);
	}
}

long lineCounting() {
	char c = 0;
	FILE* File = 0;
	int i = 0;
	setupReading(File);

	while ((c=fgetc(File)) != EOF){
		if(c == '\n') {
			i++;
		}
	}
	return i;
}


void lineIntoArray(FILE* file, char tab[], GlobalArray globalArray) {
	globalArray = malloc(sizeof(globalArray) * lineCounting());
	setupReading(file);
	for(int i=0; i <= lineCounting(); i++) {
		fgets(tab, 10, file);
		automate(tab, lineCounting(), globalArray);
	}
}


void automate (char tab[], long n, GlobalArray globalArray) {
	int i = 0, j = 0;
	char time_array[MAX] = {0};
	char voltage_array[MAX] = {0};
	while(tab[i] != ";") {
		time_array[i] = tab[i];
		i++;
	}
	i++;
	while(tab[i] != "\n") {
		voltage_array[j] = tab[i];
		j++;
		i++;
	}

	globalArray[n].time = atoi(time_array[i]);
	globalArray[n].voltage = atoi(voltage_array[j]);

}
