#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "action.h"
#include "data.h"
#include "menu_bis.h"





int main () {
	int mode = 0;

	GlobalArray globalarray = NULL;
	choixMode(mode);
	ShowingModeChoice(mode, globalarray);



}
