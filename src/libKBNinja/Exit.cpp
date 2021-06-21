#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

bool Exit(int testing) { // Проверяем хочет ли пользователь закончить игру
    system("cls");
    char key;
    bool exit = true;
    if (!testing) {
        printf("\nЗакончить игру:? Y/N\n");
        scanf("\n%c", &key);
    } else {
        key = (char)testing;
    }

    if (key == 'y' || key == 'Y') {
        exit = false;
    }
    else if (key == 'n' || key == 'N'){
        exit = true;
    }
    return exit;
}
