#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <libKBNinja/Comparator.h>
#include <libKBNinja/Pattern_read.h>


void Numbers_One(int testing)
{
    char Val_One;
    bool Quit = false;
    long int Score = -1;
    do
    {
        Val_One = '0' + rand()%10;
        Score++;
        do
        {
            system("cls");
            printf("ƒл€ выхода введите - !\n\t\t\t —чЄт: %d", Score);
            printf("\n|||||||: %c\n", Val_One);
        }while(Comparator(&Val_One, &Quit, testing) != true);

    }while (Quit == false);
}
void Numbers_Two(int testing)
{
    FILE *Res;
    Res = fopen("text/n2.txt","r");

    Pattern_Read(Res);

    fclose(Res);
}
void Numbers_Three(int testing)
{
    FILE *Res;
    Res = fopen("text/n3.txt","r");

    Pattern_Read(Res);

    fclose(Res);
}
