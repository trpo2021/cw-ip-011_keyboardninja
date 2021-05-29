#include "../libKBNinja/Trpo_SDL.h"
#include "Comparator.h"
#include "Pattern_read.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define SCREEN_WIGHT 1280
#define SCREEN_HIGH 720

void Words_One(SDL_Renderer **MainRender, SDL_Texture **MainTexture, TTF_Font **MainFont, int *Screen, int testing) {
    srand(time(NULL));
    SDL_Event Event;
    SDL_Rect Box, Box_Score;
    int WightElement = SCREEN_WIGHT/10, n_Score = 1;
    Box = Boxing(SCREEN_WIGHT/14+WightElement,SCREEN_HIGH/14,SCREEN_WIGHT/50,SCREEN_HIGH/8);
    char Val_One[2], Val_Two;
    int Score = -1;
    bool Quit = false;
    do {
        Val_One[0] = 'a' + rand() % 25;
        Score++;
        if(Score >= pow(10,n_Score)) { // посчитывает сколько разрядов в десятичном числе счёта
            n_Score++;
        }
        char Mas_Score [n_Score+1];
        int Score_Two = Score; // Создание копии счёта для его разбора на символы
        for(int i = n_Score-1; i > -1; i--) { // превращает это число в строку
            Mas_Score[i] = '0'+Score_Two%10;
            Score_Two /= 10;
        }
        Box_Score = Boxing (SCREEN_WIGHT/14+WightElement,SCREEN_HIGH/2-SCREEN_HIGH/5,SCREEN_WIGHT/60*n_Score,SCREEN_HIGH/8);
        SDL_RenderClear(*MainRender);
        LoadScreen(MainRender,MainTexture,MainFont,*Screen);
        Print_Text(MainRender,MainTexture,MainFont,Mas_Score,&Box_Score);
        Print_Text(MainRender,MainTexture,MainFont,Val_One,&Box);

        SDL_RenderPresent(*MainRender);
        do {
            Val_Two = 0;
            while(SDL_PollEvent(&Event) != NULL) {
                if(Event.type == SDL_QUIT) {
                    Quit = true;
                } else if(Event.key.keysym.sym == ';') {
                    *Screen = 1;
                    Quit = true;
                    break;
                } else if(Event.type == SDL_KEYDOWN) {
                    Val_Two = Event.key.keysym.sym;
                }
            }
            SDL_Delay (50);
            if(Quit == true) {
                break;
            }
            if(Val_Two == 0) {
                continue;
            }
        } while (Comparator(&Val_One[0], &Val_Two, &Quit, testing) != true);

    } while (Quit == false);
}
