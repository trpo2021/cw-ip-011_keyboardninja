#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <string.h>

bool Comparator(char *Val_One, bool *Quit) // Закончить игру
{
    char Val_Two;
    printf("\n |\\\\\\| ");
    Val_Two = getchar();
    if(Val_Two == '!')
    {
        *Quit = true;
        return true;
    }
    if(*Val_One == Val_Two)
    {
        return true;
    }
    return false;
}
