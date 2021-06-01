#include <libKBNinja/Comparator.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Pattern_Read(FILE* Res)
{
    bool Quit = false;
    long int Score = 0;
    int n = 0, j = 0;
    char Text[60] = {}, Val_One;

    while (Quit != true) {
        rewind(Res);
        fscanf(Res, "%d", &n);

        // fgetc(Res);
        int sz;
        sz = rand() % n + 1;
        for (int i = 0; i < sz; i++) {
            fgets(Text, 60, Res);
        }

        for (int k = 0; k < strlen(Text) - 1; k++) {
            do {
                j = k;
                system("cls");
                printf("Для выхода введите - !\n\t\t\tСчёт: %d", Score);
                printf("\n|||||||: ");
                Val_One = Text[j];
                for (j; j < strlen(Text) - 1; j++) {
                    printf("%c", Text[j]);
                }
            } while (Comparator(&Val_One, &Quit) != true);
            if (Quit == true) {
                break;
            }
            Score++;
        }
    }
}
