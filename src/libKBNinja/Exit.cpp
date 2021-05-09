#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

bool Exit(bool exit, int testing) // Проверяем хочет ли пользователь закончить игру
    system("cls");
    char key;
	if (!testing)
	{
		printf("\Закончить игру:? Y/N\n");
    	scanf("\n%c",&key);
	}
	else
		key = 'y';
    
    if (key == 'y' || key == 'Y')
    {
        exit = false;
    }
    return exit;
}
