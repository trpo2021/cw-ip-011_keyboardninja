#include "../libKBNinja/Trpo_SDL.h"
#include "Comparator.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <math.h>
#define SCREEN_WIGHT 1280
#define SCREEN_HIGH 720
#include <ctest.h>
#include "../libKBNinja/Pattern_read.h"
// Тесты будут проверять, как открывается файл
CTEST(suite4, PUSTOI)
{
}
 CTEST(suite4, Pattern_read1)
{
    SDL_Renderer **MainRender;
    SDL_Texture **MainTexture;
    TTF_Font **MainFont;
   FILE* Name;
   Name = fopen("test/test.txt");
   int test = 1, screen = 1, real = 0, k = 1;
    real=Pattern_read(SDL_Renderer **MainRender, SDL_Texture **MainTexture, TTF_Font **MainFont, &screen, &Name, test);
    ASSERT_EQUAL(k, real);
}
 CTEST(suite4, Pattern_read2)
{
    SDL_Renderer **MainRender;
    SDL_Texture **MainTexture;
    TTF_Font **MainFont;
    FILE* Name;
   Name = fopen("qw/test.txt");
   int test = 1, screen = 1, real = 0, k = 1;
    real=Pattern_read(SDL_Renderer **MainRender, SDL_Texture **MainTexture, TTF_Font **MainFont, &screen, &Name, test);
    ASSERT_NOT_EQUAL(k, real);
}
