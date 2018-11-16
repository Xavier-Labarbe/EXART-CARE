#include <stdio.h>
#include <stdlib.h>

#ifndef ACTION_H_INCLUDED
#define ACTION_H_INCLUDED

#include "data.h"


void increasingp(GlobalArray globalArray, int line);
void descendingp(GlobalArray globalArray, int line);
void increasingm(GlobalArray globalArray, int line);
void descendingm(GlobalArray globalArray, int line);
void intervalp(GlobalArray globalArray, int line);
void searching(GlobalArray globalArray, int line);
void average(GlobalArray globalArray, int line);
int choice(void);
void purger(void);
void clean (char *chaine);
int choicemin(void);
int choicemax(void);
int choice(void);
#endif
