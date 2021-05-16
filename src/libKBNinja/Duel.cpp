#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <libKBNinja/Worlds.h>
#include <libKBNinja/Numbers.h>
#include <libKBNinja/Worlds_and_Numbers.h>

void Duel(int Mode, int Difficulty, int testing) // запуск текстов на основе выбранного уровня сложности
{
    if(Mode == 1)
    {
        if(Difficulty == 1)
        {
            Words_One(testing);
        }
        else if(Difficulty == 2)
        {
            char Name [] = {"text/l2.txt"};
            Words_and_Numbers(Name,testing);
        }
        else if(Difficulty == 3)
        {
            char Name [] = {"text/l3.txt"};
            Words_and_Numbers(Name,testing);
        }
    }
    else if(Mode == 2)
    {
        if(Difficulty == 1)
        {
            Numbers_One(testing);
        }
        else if(Difficulty == 2)
        {
            char Name [] = {"text/n2.txt"};
            Words_and_Numbers(Name,testing);
        }
        else if(Difficulty == 3)
        {
            char Name [] = {"text/n3.txt"};
            Words_and_Numbers(Name,testing);
        }
    }
    else if(Mode == 3)
    {
        char Name [] = {"text/lan.txt"};
        Words_and_Numbers(Name,testing);
    }
}
