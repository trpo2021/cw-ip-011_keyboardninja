#include "Pattern_read.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void Words_and_Numbers(SDL_Renderer **MainRender, SDL_Texture **MainTexture, TTF_Font **MainFont, char* Name, int *Screen, int testing) {
    FILE* Res;
    Res = fopen(Name, "r");

    Pattern_Read(MainRender, MainTexture, MainFont, Screen, Res, testing);

    fclose(Res);
}
