#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Prepare(int* Mode, int* Difficulty) // выбираем режим сложности тренировки
{
    system("PAUSE");
    *Mode = 0, *Difficulty = 0;
    while (*Mode == 0) // выбираем что будем печатать
    {
        system("cls");
        printf("\n\n Выбери режим тренировки:\n\t1 - Только буквы\n\t2 - "
               "Только цифры\n\t3 - Буквы и цифры\n");

        scanf("%d", Mode);

        if (*Mode < 1 || *Mode > 3) {
            printf("\nОшибка, введите корректный параметр\n");
            system("PAUSE");
            *Mode = 0;
        }
    }

    while (*Difficulty == 0) // выбираем как будем печатать
    {
        system("cls");
        printf("\nВыберите сложность печати:\n");

        if (*Mode == 1) {
            printf("\Вы выбрали слова\n");
            printf("\n\t1 - Вводить по 1-й букве\n\t2 - Вводить по слову\n\t3 "
                   "- Вводить предложения\n");
        } else if (*Mode == 2) {
            printf("\nВы выбрали цифры");
            printf("\n\t1 - Вводить по 1 цифре\n\t2 - Вводить числа\n\t3 - "
                   "Вводить уравнения\n");
        } else if (*Mode == 3) {
            printf("\n\tТут присутствует только 1 уровень сложности, удачи!\n");
            break;
        }

        scanf("\n%d", Difficulty);

        if (*Difficulty < 1 || *Difficulty > 3) {
            printf("\nОшибка, введите корректный параметр\n");
            system("PAUSE");
            *Difficulty = 0;
        }
    }
}
