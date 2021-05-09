#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <libKBNinja/Comparator.h>
#include <libKBNinja/Pattern_read.h>

void Words_One(int testing)
{
    char Val_One;
    int Option;
    long int Score = -1;
    bool Quit = false;
    do
    {
        Option = rand()%2;
        if(Option == 0)
        {
            Val_One = 'a' + rand()%26;
        }
        if(Option == 1)
        {
            Val_One = 'A' + rand()%26;
        }
        Score++;
        do
        {
            system("cls");
            printf("ƒл€ выхода введите - !\n\t\t\t—чЄт: %d", Score);
            printf("\n|||||||: %c\n", Val_One);
        }while(Comparator(&Val_One, &Quit, testing) != true);

    }while (Quit == false);
}
void Words_Two(int testing)
{
    FILE *Res;
    Res = fopen("text/l2.txt","r");

    Pattern_Read(Res, testing);

    fclose(Res);
}
void Words_Three(int testing)
{
    FILE *Res;
    Res = fopen("text/l3.txt","r");

    Pattern_Read(Res, testing);

    fclose(Res);
}
