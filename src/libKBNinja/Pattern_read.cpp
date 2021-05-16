#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <libKBNinja/Comparator.h>



void Pattern_Read(FILE *Res, int testing)
{
    bool Quit = false;
    int Score = 0, j = 0;
    int n = 0;
    char Text[60] = {}, Val_One;


    while(Quit != true)
    {
        rewind(Res);
        fscanf(Res,"%d",&n);

        //fgetc(Res);
        int sz;
        sz = rand()%n+1;
        for(int i = 0; i < sz; i++)
        {
            fgets(Text,60,Res);
        }

        for (int k = 0; k < (int)strlen(Text)-1; k++)
        {
            do
            {
                system("cls");
                printf("Для выхода введите - !\n\t\t\tСчёт: %d", Score);
                printf("\n|||||||: ");
                Val_One = Text[j];
                for(j = k; j < (int)strlen(Text)-1;j++)
                {
                    printf("%c", Text[j]);
                }
            }while(Comparator(&Val_One, &Quit, testing) != true);
            if(Quit == true)
            {
                break;
            }
            Score++;
        }
    }
}
