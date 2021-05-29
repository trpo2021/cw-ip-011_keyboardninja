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

void Pattern_Read(SDL_Renderer **MainRender, SDL_Texture **MainTexture, TTF_Font **MainFont, int *Screen, FILE* Res, int testing)//шаблон для считывания файлов с текстами
{
    SDL_Event Event;
    SDL_Rect Box, Box_Score;
    int WightElement = SCREEN_WIGHT/10, n_Score = 1;
    bool Quit = false;
    int Score = 0, j = 0;
    int n = 0;
    char Text[35] = {}, Val_One, Val_Two;

    while (Quit != true) {
        rewind(Res);
        fscanf(Res, "%d", &n);

        int sz;
        sz = rand() % n + 1;
        for (int i = 0; i < sz; i++) { // считывается по 35 символов, со случайного места
            fgets(Text, 35, Res);
        }

        for (int k = 0; k < (int)strlen(Text) - 1; k++)
        {
            if(Score >= pow(10,n_Score)) // посчитывает сколько разрядов в десятичном числе счёта
            {
                n_Score++;
            }
            char Mas_Score [n_Score+1];
            int Score_Two = Score; // Создание копии счёта для его разбора на символы
            for(int i = n_Score-1; i > -1; i--) // превращает это число в строку
            {
                Mas_Score[i] = '0'+Score_Two%10;
                Score_Two /= 10;
            }

            Box_Score = Boxing (SCREEN_WIGHT/14+WightElement,SCREEN_HIGH/2-SCREEN_HIGH/5,SCREEN_WIGHT/60*n_Score,SCREEN_HIGH/8);
            SDL_RenderClear(*MainRender);
            LoadScreen(MainRender,MainTexture,MainFont,*Screen);
            Print_Text(MainRender,MainTexture,MainFont,Mas_Score,&Box_Score);

            j = k;

            char Text_Free[(int)strlen(Text)-k+2] = {};

            Val_One = Text[j];
            for (j; j < (int)strlen(Text) - 1; j++) {
                Text_Free[j-k] = Text[j];
            }
            Text_Free[(int)strlen(Text_Free)] = '<';

            Box = Boxing(SCREEN_WIGHT/14+WightElement,SCREEN_HIGH/14,SCREEN_WIGHT/60*((int)strlen(Text_Free)),SCREEN_HIGH/8);
            Print_Text(MainRender,MainTexture,MainFont,Text_Free,&Box);
            SDL_RenderPresent(*MainRender);

            do {
                Val_Two = 0;
                while(SDL_PollEvent(&Event) != NULL)
                {
                    if(Event.type == SDL_QUIT)
                    {
                        Quit = true;
                        break;
                    }
                    else if(Event.key.keysym.sym == ';') {
                        *Screen = 1;
                        Quit = true;
                        break;
                    }
                    else if(Event.type == SDL_KEYDOWN)
                    {
                        Val_Two = Event.key.keysym.sym;
                    }
                }
                if (Quit == true) {
                    break;
                }
                SDL_Delay (50);

            } while (Comparator(&Val_One,&Val_Two, &Quit, testing) != true);
            if (Quit == true) {
                break;
            }
            Score++;
        }
    }
}
