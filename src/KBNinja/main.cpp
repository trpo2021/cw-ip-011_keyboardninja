#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Prepare (int *Mode, int *Difficulty)
{
    system("PAUSE");
    *Mode = 0, *Difficulty = 0;
    while (*Mode == 0)
    {
        system("cls");
        printf("\n\n Выбери режим тренировки:\n\t1 - Только буквы\n\t2 - Только цифры\n\t3 - Буквы и цифры\n");

        scanf("%d",Mode);

        if (*Mode < 1 || *Mode > 3)
        {
            printf("\nОшибка, введите корректный параметр\n");
            system("PAUSE");
            *Mode = 0;
        }
    }

    while (*Difficulty == 0)
    {
        system("cls");
        printf("\nВыдерете сложность печати:\n");

        if(*Mode == 1)
        {
            printf("\nВы выбрали слова\n");
            printf("\n\t1 - Вводить по 1-й букве\n\t2 - Вводить по слову\n\t3 - Вводить предложения\n");
        }
        else if (*Mode == 2)
        {
            printf("\nВы выбрали цифры");
            printf("\n\t1 - Вводить по 1 цифре\n\t2 - Вводить числа\n\t3 - Вводить уравнения\n");
        }
        else if (*Mode == 3)
        {
            printf("\n\tТут присутвсвует только 1 уровень сложности, удачи\n");
            break;
        }

        scanf("\n%d",Difficulty);

        if(*Difficulty < 1 || *Difficulty > 3)
        {
            printf("\nОшибка введите корректный параметр\n");
            system("PAUSE");
            *Difficulty = 0;
        }
    }
}

bool Exit(bool exit)
{
    system("cls");
    char key;

    printf("\nЗакончить игру:? Y/N\n");
    scanf("\n%c",&key);

    if (key == 'y' || key == 'Y')
    {
        exit = false;
    }
    return exit;
}

int main ()
{
    setlocale(0,"Russian");

    int Mode = 0, Difficulty = 0;
    bool Game = true;

    while(Game)
    {
        system("cls");
        printf("\tПривет, хочешь преисполниться в печати?\n");
        Prepare(&Mode, &Difficulty);
        printf("\n%d %d\n", Mode, Difficulty);
        system("PAUSE");
        Game = Exit(&Game);
    }
    system("cls");
    printf("Спасибо за игру, возвращяйтесь\n");


    system("PAUSE");
    return 0;
}
