#include "Comparator.h"
#include "Pattern_read.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Numbers_One(int testing)
{
    char Val_One;
    bool Quit = false;
    int Score = -1;
    do {
        Val_One = '0' + rand() % 10;
        Score++;
        do {
            system("cls");
            printf("Для выхода введите - !\n\t\t\tСчёт: %d", Score);
            printf("\n|||||||: %c\n", Val_One);
        } while (Comparator(&Val_One, &Quit, testing) != true);

    } while (Quit == false);
}
