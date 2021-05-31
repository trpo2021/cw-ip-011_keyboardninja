#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "../SDL/include/SDL2/SDL.h"
#include "../SDL/include/SDL2/SDL_image.h"
#include "../SDL/include/SDL2/SDL_ttf.h"


int Pattern_Read(SDL_Renderer **MainRender, SDL_Texture **MainTexture, TTF_Font **MainFont, int *Screen, FILE* Res, int testing);

