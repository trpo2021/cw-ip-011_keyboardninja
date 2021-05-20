#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

bool Comparator(char* Val_One, bool* Quit, int testing) // сравнивает значения
{
    char Val_Two;
    if (!testing) {
        printf("\n |\\\\\\| ");
        Val_Two = getchar();
    } else
        Val_Two = '!';
    if (Val_Two == '!') {
        *Quit = true;
        return true;
    }
    if (*Val_One == Val_Two) {
        return true;
    }
    return false;
}
