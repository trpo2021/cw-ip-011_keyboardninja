#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <string.h>

void Prepare (int *Mode, int *Difficulty) // выбираем режим сложности тренировки
{
    system("PAUSE");
    *Mode = 0, *Difficulty = 0;
    while (*Mode == 0) // выбираем что будем печатать
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

    while (*Difficulty == 0) // выбираем как будем печатать
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
}//

bool Exit(bool exit) // Проверяем хочет ли пользователь закончить игру
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
} //

bool Comparator(char *Val_One, bool *Quit) // сравнивает значения
{
    char Val_Two;
    printf("\n |\\\\\\| ");
    Val_Two = getch();
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

void Pattern_Read(FILE *Res)
{
    bool Quit = false;
    long int Score = 0;
    int n = 0, j = 0;
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

        for (int k = 0; k < strlen(Text)-1; k++)
        {
            do
            {
                j = k;
                system("cls");
                printf("Для выхода введите - !\n\t\t\tСчёт: %d", Score);
                printf("\n|||||||: ");
                Val_One = Text[j];
                for(j; j < strlen(Text)-1;j++)
                {
                    printf("%c", Text[j]);
                }
            }while(Comparator(&Val_One, &Quit) != true);
            if(Quit == true)
            {
                break;
            }
            Score++;
        }
    }
}

void Words_One()
{
    char Val_One;
    int Option;
    long int Score = -1;
    bool Quit = false;
    do
    {
        Option = rand()%2;
        if(Option == 0)
        {
            Val_One = 'a' + rand()%26;
        }
        if(Option == 1)
        {
            Val_One = 'A' + rand()%26;
        }
        Score++;
        do
        {
            system("cls");
            printf("Для выхода введите - !\n\t\t\tСчёт: %d", Score);
            printf("\n|||||||: %c\n", Val_One);
        }while(Comparator(&Val_One, &Quit) != true);

    }while (Quit == false);
}
void Words_Two()
{

    FILE *Res;
    Res = fopen("text/l2.txt","r");

    Pattern_Read(Res);

    fclose(Res);
}
void Words_Three()
{
    FILE *Res;
    Res = fopen("text/l3.txt","r");

    Pattern_Read(Res);

    fclose(Res);
}
void Numbers_One()
{
    char Val_One;
    bool Quit = false;
    long int Score = -1;
    do
    {
        Val_One = '0' + rand()%10;
        Score++;
        do
        {
            system("cls");
            printf("Для выхода введите - !\n\t\t\t Счёт: %d", Score);
            printf("\n|||||||: %c\n", Val_One);
        }while(Comparator(&Val_One, &Quit) != true);

    }while (Quit == false);
}
void Numbers_Two()
{
    FILE *Res;
    Res = fopen("text/n2.txt","r");

    Pattern_Read(Res);

    fclose(Res);
}
void Numbers_Three()
{
    FILE *Res;
    Res = fopen("text/n3.txt","r");

    Pattern_Read(Res);

    fclose(Res);
}
void Words_and_Numbers()
{
    FILE *Res;
    Res = fopen("text/lan.txt","r");

    Pattern_Read(Res);

    fclose(Res);
}
void Duel(int Mode, int Difficulty)
{
    if(Mode == 1)
    {
        if(Difficulty == 1)
        {
            Words_One();
        }
        else if(Difficulty == 2)
        {
            Words_Two();
        }
        else if(Difficulty == 3)
        {
            Words_Three();
        }
    }
    else if(Mode == 2)
    {
        if(Difficulty == 1)
        {
            Numbers_One();
        }
        else if(Difficulty == 2)
        {
            Numbers_Two();
        }
        else if(Difficulty == 3)
        {
            Numbers_Three();
        }
    }
    else if(Mode == 3)
    {
        Words_and_Numbers();
    }
}

int main ()
{
    setlocale(0,"Russian");
    srand(time(NULL));

    int Mode = 0, Difficulty = 0;
    bool Game = true;

    while(Game) // Вся логика программы
    {
        system("cls");                                          //
        printf("\tПривет, хочешь преисполниться в печати?\n");  //
        Prepare(&Mode, &Difficulty);                            // выбираем режим игры и уровень сложности
        //printf("\n%d %d\n", Mode, Difficulty);                  // выводим значения, которые выбрал пользователь
        Duel(Mode, Difficulty);

        system("PAUSE");                                        //
        Game = Exit(&Game);                                     // Проверяем хочет ли пользователь потренироваться ещщё раз или нет
    }
    system("cls");
    printf("Спасибо за игру, возвращяйтесь\n");

    system("PAUSE");
    return 0;
}
