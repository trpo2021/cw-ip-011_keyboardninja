#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

bool Comparator(char *Val_One, bool *Quit, int testing) // Закончить игру
{
    char Val_Two;
	if (!testing)
	{
		printf("\n |\\\\\\| ");
    	Val_Two = getch();
	}
    else
    	Val_Two = '!';
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
