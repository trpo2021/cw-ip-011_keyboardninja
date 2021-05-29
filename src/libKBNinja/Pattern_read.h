#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#pragma once

void Pattern_Read(SDL_Renderer **MainRender, SDL_Texture **MainTexture, TTF_Font **MainFont, int *Screen, FILE* Res, int testing);
