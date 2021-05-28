#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

bool Comparator(char* Val_One, bool* Quit, int testing) // Сравнивает вводимые значения со значениями из файла
{
    char Val_Two;
    if (!testing) {
        printf("\n |\\\\\\| ");
        Val_Two = getch();
    } else{
        Val_Two = (char)testing;
        }
    if (Val_Two == '!') {
        *Quit = true;
        return true;
    }
    if (*Val_One == Val_Two) {
        return true;
    }
    return false;
}
