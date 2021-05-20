#include <libKBNinja/Comparator.h>
#include <libKBNinja/Duel.h>
#include <libKBNinja/Exit.h>
#include <libKBNinja/Numbers.h>
#include <libKBNinja/Pattern_read.h>
#include <libKBNinja/Prepare.h>
#include <libKBNinja/Worlds.h>
#include <libKBNinja/Worlds_and_Numbers.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    setlocale(0, "Russian");
    srand(time(NULL));

    int Mode = 0, Difficulty = 0, testing = 0;
    bool Game = true;

    while (Game) // Вся логика программы
    {
        system("cls");                                         //
        printf("\tПривет, хочешь преисполниться в печати?\n"); //
        Prepare(&Mode,
                &Difficulty,
                testing); //  выбираем режим игры и уровень сложности
        // printf("\n%d %d\n", Mode, Difficulty);                  // выводим
        // значения, которые выбрал пользователь
        Duel(Mode, Difficulty, testing);

        system("PAUSE");      //
        Game = Exit(testing); // Проверяем хочет ли пользователь потренироваться
                              // ещё раз или нет
    }
    system("cls");
    printf("Спасибо за игру, возвращайтесь!\n");

    system("PAUSE");
    return 0;
}
