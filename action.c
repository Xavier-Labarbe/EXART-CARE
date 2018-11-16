#include <stdio.h>
#include <stdlib.h>
#include "action.h"
#include "menu.h"
#include "data.h"


void increasingp(GlobalArray globalArray, int line) {
    int i;
    int max;
    int j;
    //int modif = 1;

   //while(modif !=0 ){
	   //modif = 0;
    for (i=0; i < line  ;i++)
   {
    for (j = i+1 ; j < line ;j++)
       {
        if(globalArray[j].voltage < globalArray[i].voltage)
           {
            max = globalArray[j].voltage ;
            globalArray[j].voltage = globalArray[i].voltage;
            globalArray[i].voltage = max;
            //modif ++;
           }
       }
   }

	for (i=0; i < line ; i++) {
	   printf("%d bpm , %l ms\n", globalArray[i].voltage, globalArray[i].time);

	}
}


void descendingp(GlobalArray globalArray, int line)
{
    int i;
    int max;
    int j;
   for (i=0; i < line  ;i++)
   {
    for (j = i+1 ; j < line ;j++)
       {
        if(globalArray[j].voltage >globalArray[i].voltage)
           {
            max =  globalArray[j].voltage ;
             globalArray[j].voltage =  globalArray[i].voltage;
             globalArray[i].voltage = max;
           }
       }
   }


for (i=0; i<line ; i++)
{
    for (j=0; j<line;j++)
    {
        if ( globalArray[i].voltage== globalArray[j].voltage)
        {
            printf("%ul bpm ; %ul ms\n",  globalArray[i].voltage, globalArray[j].time);
        }
    }
}

}

void increasingm(GlobalArray globalArray, int line)
{
    int i;
    int max;
    int j;
   for (i=0; i < line  ;i++)
   {
    for (j = i+1 ; j < line ;j++)
       {
        if(globalArray[j].time < globalArray[i].time)
           {
            max = globalArray[j].time ;
            globalArray[j].time = globalArray[i].time;
            globalArray[i].time = max;
           }
       }
   }


for (i=0; i<line ; i++)
{
    for (j=0; j<line;j++)
    {
        if (globalArray[i].time==globalArray[j].time)
        {
            printf("%d ms ; %d bpm\n", globalArray[j].time, globalArray[j].voltage);
        }
    }
}


}


void descendingm(GlobalArray globalArray, int line)
{
    int i;
    int max;
    int j;
   for (i=0; i < line  ;i++)
   {
    for (j = i+1 ; j < line ;j++)
       {
        if(globalArray[j].time > globalArray[j].time)
           {
            max = globalArray[j].time  ;
            globalArray[j].time  = globalArray[i].time ;
            globalArray[i].time = max;
           }
       }
   }


for (i=0; i<line ; i++)
{

    for (j=0; j<line;j++)
    {
        if (globalArray[i].time == globalArray[j].time )
        {
            printf("%d ms ; %d bpm\n", globalArray[i].time ,globalArray[j].voltage);
        }
    }
}

}


void intervalp(GlobalArray globalArray, int line)
{
    int i;
    int max;
    int j;
   for (i=0; i < line  ;i++)
   {
    for (j = i+1 ; j < line ;j++)
       {
        if(globalArray[j].voltage < globalArray[i].voltage)
           {
            max =globalArray[j].voltage ;
            globalArray[j].voltage = globalArray[i].voltage;
            globalArray[i].voltage = max;
           }
       }
   }
   for (i=0; i<line;i++)
   {
       if (i==0)
       {
           printf("pulse minimale : %lu BPM  temps : %lu ms\n",globalArray[i].voltage, globalArray[i].time);
       }
       else if (i== (line-1))
       {
           printf("pulse maximale : %d BPM  temps : %d ms\n\n",globalArray[i].voltage, globalArray[i].voltage);
       }
   }
}


void searching(GlobalArray globalArray, int line)
{
int nbrsearching;
int i;
int p;
nbrsearching = choicerech();
printf("\n");


for(i=0; i<line; i++)
        {

        if(globalArray[i].time == nbrsearching)
                {

                p=i;
                i=2*line;
                break;
                }


        }
if(i == (2*line))
{
    printf("Le temps %d ms est bien dans le tableau associe au pulse : %d BPM\n\n", nbrsearching, globalArray[p].voltage);

}
else
{
    printf("Le temps %d ms ne se trouve pas dans le tableau\n\n", nbrsearching);
}

}
void average(GlobalArray globalArray, int line)
{
    int i;
    int somme=0;
    int average;
    int min;
    int max;
    int cmin;
    int cmax;

    min = choicemin();
    max = choicemax();

    while (min > max)
    {
        printf("La valeur minimale ne peut pas etre plus elevee que la valeur maximale, veuillez rentrer des valeurs valables : \n");
        min = choicemin();
        max = choicemax();
    }
    for (i=0; i<line;i++)
    {
        if (globalArray[i].time== min) {
            min = globalArray[i].time;
            cmin=i;
            break;
        }

        else if (globalArray[i].time > min)
        {
            min = globalArray[i].time;
            cmin=i;
            break;
        }
    }

    for (i=0 ; i<line;i++)
    {
        if (globalArray[i].time == max)
        {
            max = globalArray[i].time;
            cmax=i;
            break;
        }

        else if (globalArray[i].time > max)
        {


            max = globalArray[i].time;
            cmax=i;
            break;
        }

        else if (i==(line-1) && globalArray[(line-1)].time < max )
        {
                max = globalArray[(line-1)].time;
                cmax=i;
                break;
        }
    }

    printf("average de temps choisit (en ms): [%d ; %d]\n", min,max);
for(i=cmin; i<cmax+1; i++)
    {

        somme=somme+globalArray[i].time;
    }
    average = somme / ((cmax - cmin)+1);
    printf("average du pulse : %d BPM\n\n", average);
}

int choice(void)
{
    char chaine1[20];
    int test;
    int choix;

    do
    {
    printf("Entrez la valeur correspondante a votre choix\n");
    fgets(chaine1, sizeof chaine1, stdin);

    clean(chaine1);

    test = sscanf(chaine1, "%d", &choix);
    }while (test != 1);

    while (choix < 0 || choix > 9)
    {
        do
    {
    printf("Entrez la valeur correspondante a votre choix\n");
    fgets(chaine1, sizeof chaine1, stdin);

    clean(chaine1);

    test = sscanf(chaine1, "%d", &choix);
    }while (test != 1);

    }

    return choix;

}

void purger(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {}
}

void clean (char *chaine)
{
    char *p = strchr(chaine, '\n');

    if (p)
    {
        *p = 0;
    }

    else
    {
        purger();
    }
}


int choicemin(void)
{
    char chaine1[20];
    int test;
    int choix;

    do
    {
    printf("Rentrez le temps (en ms) minimale de l'average : ");
    fgets(chaine1, sizeof chaine1, stdin);

    clean(chaine1);

    test = sscanf(chaine1, "%d", &choix);
    }while (test != 1);





    return choix;

}

int choicemax(void)
{
    char chaine1[20];
    int test;
    int choix;

    do
    {
    printf("Rentrez le temps maximale de l'average : ");
    fgets(chaine1, sizeof chaine1, stdin);

    clean(chaine1);

    test = sscanf(chaine1, "%d", &choix);
    }while (test != 1);





    return choix;

}

int choicerech(void)
{
    char chaine1[20];
    int test;
    int choix;

    do
    {
    printf("Rentrez le temps (en ms) souhaitez : ");
    fgets(chaine1, sizeof chaine1, stdin);

    clean(chaine1);

    test = sscanf(chaine1, "%d", &choix);
    }while (test != 1);


    return choix;

}

