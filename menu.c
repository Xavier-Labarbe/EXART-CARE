#include "menu.h"
#include "generateCode.h"



int choixMode(int a) {
	FILE* file = 0;

	printf("---------MENU---------\n\n");
	printf("Please can you choose the type of lightning.\n\n");
	printf("Mode 1 : All LEDs\n");
	printf("Mode 2 : The Chenillard Art type\n");
	printf("Mode 3 : One LED over two\n");
	printf("Mode 4 : One LED over three\n");
	printf("Mode 5 : Any LED you want it to be lighted\n");
	fflush(stdout);
	scanf("%d", &a);


	setup (file, a);
	return a;
}




