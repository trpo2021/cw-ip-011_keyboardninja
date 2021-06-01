#include "../src/SDL/include/SDL2/SDL.h"
#include "../src/SDL/include/SDL2/SDL_image.h"
#include "../src/SDL/include/SDL2/SDL_ttf.h"
#include "../src/libKBNinja/Trpo_SDL.h"
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SCREEN_WIGHT 1280
#define SCREEN_HIGH 720
#include "../src/libKBNinja/Pattern_read.h"
#include <ctest.h>
// Тесты будут проверять, как открывается файл
CTEST(suite4, PUSTOI)
{
}
CTEST(suite4, Pattern_read1)
{
    SDL_Renderer** MainRender = NULL;
    SDL_Texture** MainTexture = NULL;
    TTF_Font** MainFont = NULL;
    FILE* Name;
    Name = fopen("test/test.txt", "r");
    int test = 1, screen = 1, real = 0, k = 1;
    real = Pattern_Read(MainRender, MainTexture, MainFont, &screen, Name, test);
    ASSERT_EQUAL(k, real);
}
CTEST(suite4, Pattern_read2)
{
    SDL_Renderer** MainRender = NULL;
    SDL_Texture** MainTexture = NULL;
    TTF_Font** MainFont = NULL;
    FILE* Name;
    Name = fopen("qw/test.txt", "r");
    int test = 1, screen = 1, real = 0, k = 1;
    real = Pattern_Read(MainRender, MainTexture, MainFont, &screen, Name, test);
    ASSERT_NOT_EQUAL(k, real);
}
