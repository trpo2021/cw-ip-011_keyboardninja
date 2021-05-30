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
#include "../libKBNinja/Words_and_Numbers.h"
// Тесты будут проверять, как открывается файл
CTEST(suite4, PUSTOI)
{
}
 CTEST(suite4, Words_and_Numbers1)
{
    SDL_Renderer **MainRender;
    SDL_Texture **MainTexture;
    TTF_Font **MainFont;
   char Name[] = {"test/test.txt"};
   int test = 1, screen = 1, real = 0, k = 1;
    real=Words_and_Numbers(SDL_Renderer **MainRender, SDL_Texture **MainTexture, TTF_Font **MainFont, &Name, &screen, test);
    ASSERT_EQUAL(k, real);
}
 CTEST(suite4, Words_and_Numbers2)
{
    SDL_Renderer **MainRender;
    SDL_Texture **MainTexture;
    TTF_Font **MainFont;
   char Name[] = {"test/qw.txt"};
   int test = 1, screen = 1, real = 0, k = 1;
    real=Words_and_Numbers(SDL_Renderer **MainRender, SDL_Texture **MainTexture, TTF_Font **MainFont, &Name, &screen, test);
    ASSERT_NOT_EQUAL(k, real);
}
