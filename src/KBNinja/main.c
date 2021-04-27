#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <libKBNinja/Prepare.h>
#include <libKBNinja/Exit.h>
#include <libKBNinja/Comparator.h>
#include <libKBNinja/Pattern_read.h>
#include <libKBNinja/Worlds.h>
#include <libKBNinja/Numbers.h>
#include <libKBNinja/Worlds_and_Numbers.h>
#include <libKBNinja/Duel.h>


int main ()
{
    setlocale(0,"Russian");
    srand(time(NULL));

    int Mode = 0, Difficulty = 0;
    bool Game = true;

    while(Game) // Вся логика программы
    {
        system("cls");                                          //
        printf("\tПривет, хочешь преисполниться в печати?\n");  //
        Prepare(&Mode, &Difficulty);                            // выбираем режим игры и уровень сложности
        //printf("\n%d %d\n", Mode, Difficulty);                  // выводим значения, которые выбрал пользователь
        Duel(Mode, Difficulty);

        system("PAUSE");                                        //
        Game = Exit(&Game);                                     // Проверяем хочет ли пользователь потренироваться ещщё раз или нет
    }
    system("cls");
    printf("Спасибо за игру, возвращяйтесь\n");

    system("PAUSE");
    return 0;
}
