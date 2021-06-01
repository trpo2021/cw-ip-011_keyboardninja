#include "../src/SDL/include/SDL2/SDL.h"
#include "../src/SDL/include/SDL2/SDL_image.h"
#include "../src/SDL/include/SDL2/SDL_ttf.h"
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SCREEN_WIGHT 1280
#define SCREEN_HIGH 720
#include "../src/libKBNinja/Worlds_and_Numbers.h"
#include <ctest.h>
// Тесты будут проверять, как открывается файл
CTEST(suite4, PUSTOI)
{
}
CTEST(suite4, Words_and_Numbers1)
{
    SDL_Renderer** MainRender = NULL;
    SDL_Texture** MainTexture = NULL;
    TTF_Font** MainFont = NULL;
    char Name[] = {"test/test.txt"};
    int test = 1, screen = 1, real = 0, k = 1;
    real = Words_and_Numbers(
            MainRender, MainTexture, MainFont, Name, &screen, test);
    ASSERT_EQUAL(k, real);
}
CTEST(suite4, Words_and_Numbers2)
{
    SDL_Renderer** MainRender = NULL;
    SDL_Texture** MainTexture = NULL;
    TTF_Font** MainFont = NULL;
    char Name[] = {"test/qw.txt"};
    int test = 1, screen = 1, real = 0, k = 1;
    real = Words_and_Numbers(
            MainRender, MainTexture, MainFont, Name, &screen, test);
    ASSERT_NOT_EQUAL(k, real);
}
