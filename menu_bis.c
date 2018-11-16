#include <stdio.h>
#include <stdlib.h>
#include "menu_bis.h"
#include "action.h"
#include "data.h"




void ShowingModeChoice (int mode1, GlobalArray globalArray) {
		mode1 = 0;
		FILE* file = 0;
		int i = 0, line = 0;
		char c = 0;
		printf("---------MENU---------\n\n");
		printf("\n\n");
		printf("Mode 1 : From the smallest pulse to the biggest pulse \n");
		printf("Mode 2 : From the biggest pulse to the smallest pulse \n");
		printf("Mode 3 : For one particular data\n");
		printf("Mode 4 : Getting the biggest pulse and the smallest pulse\n");
		printf("Mode 5 : Just reading the file");
		printf("Mode 6 : Getting the pulse average");
		printf("Mode 7 : Getting the number of line in the file");
		fflush(stdout);
		scanf("%d", &mode1);

		switch(mode1) {
		case 1:
			increasingp(globalArray, line);
			break;
		case 2:
			descendingp(globalArray, line);
			break;
		case 3:
			searching(globalArray, line);
			break;
		case 4:
			intervalp(globalArray, line);
			break;
		case 5:
			setupReading(file);
			break;
		case 6:
			average(globalArray, line);
			break;
		case 7:
			lineCounting(c, file, i);
			break;

		}
}




