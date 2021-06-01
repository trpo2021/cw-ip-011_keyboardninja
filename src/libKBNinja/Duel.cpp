#include <libKBNinja/Numbers.h>
#include <libKBNinja/Worlds.h>
#include <libKBNinja/Worlds_and_Numbers.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Duel(int Mode, int Difficulty)
{
    if (Mode == 1) {
        if (Difficulty == 1) {
            Words_One();
        } else if (Difficulty == 2) {
            Words_Two();
        } else if (Difficulty == 3) {
            Words_Three();
        }
    } else if (Mode == 2) {
        if (Difficulty == 1) {
            Numbers_One();
        } else if (Difficulty == 2) {
            Numbers_Two();
        } else if (Difficulty == 3) {
            Numbers_Three();
        }
    } else if (Mode == 3) {
        Words_and_Numbers();
    }
}
