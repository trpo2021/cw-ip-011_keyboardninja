#include "Numbers.h"
#include "Worlds.h"
#include "Worlds_and_Numbers.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Duel(
    SDL_Renderer **MainRender,
    SDL_Texture **MainTexture,
    TTF_Font **MainFont,
    int *Mode,
    int *Difficulty,
    int *Screen,
    int testing) { // запуск текстов на основе выбранного уровня сложности
    if (*Mode == 1) {
        if (*Difficulty == 1) {
            Words_One(MainRender,MainTexture,MainFont,Screen, testing);
        } else if (*Difficulty == 2) {
            char Name[] = {"text/l2.txt"};
            Words_and_Numbers(MainRender,MainTexture,MainFont,Name, Screen, testing);
        } else if (*Difficulty == 3) {
            char Name[] = {"text/l3.txt"};
            Words_and_Numbers(MainRender,MainTexture,MainFont,Name, Screen, testing);
        }
    } else if (*Mode == 2) {
        if (*Difficulty == 1) {
            Numbers_One(MainRender,MainTexture,MainFont,Screen, testing);
        } else if (*Difficulty == 2) {
            char Name[] = {"text/n2.txt"};
            Words_and_Numbers(MainRender,MainTexture,MainFont,Name, Screen, testing);
        } else if (*Difficulty == 3) {
            char Name[] = {"text/n3.txt"};
            Words_and_Numbers(MainRender,MainTexture,MainFont,Name, Screen, testing);
        }
    } else if (*Mode == 3) {
        char Name[] = {"text/lan.txt"};
        Words_and_Numbers(MainRender,MainTexture,MainFont,Name, Screen, testing);
    }
}
