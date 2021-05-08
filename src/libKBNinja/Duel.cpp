#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <libKBNinja/Worlds.h>
#include <libKBNinja/Numbers.h>
#include <libKBNinja/Worlds_and_Numbers.h>

void Duel(int Mode, int Difficulty, int testing)
{
    if(Mode == 1)
    {
        if(Difficulty == 1)
        {
            Words_One(testing);
        }
        else if(Difficulty == 2)
        {
            Words_Two(testing);
        }
        else if(Difficulty == 3)
        {
            Words_Three(testing);
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
            Numbers_Two(testing);
        }
        else if(Difficulty == 3)
        {
            Numbers_Three(testing);
        }
    }
    else if(Mode == 3)
    {
        Words_and_Numbers(testing);
    }
}

