#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int Prepare(
    int* Mode,
    int* Difficulty,
    int testing) { // выбираем режим сложности тренировки
    system("PAUSE");
    *Mode = 0, *Difficulty = 0;
    while (*Mode == 0) { // выбираем что будем печатать
        system("cls");
        if (!testing) {
            printf("\n\n Выбери режим тренировки:\n\t1 - Только буквы\n\t2 - "
                   "Только цифры\n\t3 - Буквы и цифры\n");
            scanf("%d", Mode);
        }
        if (*Mode < 1 || *Mode > 3) {
            if (!testing) {
                printf("\nОшибочка, введите корректный параметр\n");
                system("PAUSE");
                *Mode = 0;
            }
            else{
                return 0;
                }
        }
    }

    while (*Difficulty == 0) { // выбираем как будем печатать
        if (!testing) {
            system("cls");
            printf("\nВыберите сложность печати:\n");
        }

        if (*Mode == 1) {
            if (!testing) {
                printf("\nВы выбрали слова\n");
                printf("\n\t1 - Вводить по 1-й букве\n\t2 - Вводить по "
                       "слову\n\t3 - Вводить предложения\n");
            }

        } else if (*Mode == 2) {
            if (!testing) {
                printf("\nВы выбрали цифры");
                printf("\n\t1 - Вводить по 1 цифре\n\t2 - Вводить числа\n\t3 - "
                       "Вводить уравнения\n");
            }

        } else if (*Mode == 3) {
            if (!testing) {
                printf("\n\tТут присутствует только 1 уровень сложности, "
                       "Да прибудет с вами сила!\n");
            }

            break;
        }
        if (!testing)
            scanf("\n%d", Difficulty);

        if (*Difficulty < 1 || *Difficulty > 3) {
            if (!testing){
                printf("\nОшибка, введите корректный параметр\n");
                system("PAUSE");
                *Difficulty = 0;
                }
            else{
                return 0;
                }
        }
    }
}
