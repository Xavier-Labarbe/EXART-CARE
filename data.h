#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef DATA_H_
#define DATA_H_
#define MAX 1000

typedef struct {
	unsigned long time;
	int voltage;
}donnee;

typedef donnee *GlobalArray;

void setupReading(FILE* file);
long lineCounting();
void lineIntoArray(FILE* file, char tab[], GlobalArray globalArray);
void automate (char tab[], long n, GlobalArray globalArray);



#endif
