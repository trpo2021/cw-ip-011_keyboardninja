#include "../SDL/include/SDL2/SDL.h"
#include "../SDL/include/SDL2/SDL_image.h"
#include "../SDL/include/SDL2/SDL_ttf.h"
#include "Trpo_SDL.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "conio.h"
#define SCREEN_WIGHT 1280
#define SCREEN_HIGH 720

void Load (SDL_Window **MainWindow,  SDL_Renderer **MainRender, SDL_Surface **MainSurface, TTF_Font **MainFont) { // Инициализация всех нужных модулей
    SDL_Init(SDL_INIT_VIDEO);
    //IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    *MainFont = TTF_OpenFont("src/Resources/Font/Pixel.ttf",30);
    *MainWindow = SDL_CreateWindow("KeyBoard Ninja", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREEN_WIGHT,SCREEN_HIGH,SDL_WINDOW_SHOWN);
    *MainSurface = SDL_GetWindowSurface(*MainWindow);
    *MainRender = SDL_CreateRenderer(*MainWindow,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Close (SDL_Window **MainWindow, SDL_Renderer **MainRender, SDL_Texture **MainTexture, SDL_Surface **MainSurface, TTF_Font **MainFont) { // Закрытие инициализированных модулей
    TTF_CloseFont(*MainFont);
    SDL_FreeSurface(*MainSurface);
    SDL_DestroyRenderer(*MainRender);
    SDL_DestroyWindow(*MainWindow);
    SDL_DestroyTexture(*MainTexture);

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
SDL_Rect Boxing(int x, int y, int Wight, int Hight) { //Возвращяет примитив - прямоугольник
    SDL_Rect Box;
    Box.x = x;
    Box.y = y;
    Box.w = Wight;
    Box.h = Hight;
    return Box;
}
void Copy_Render(SDL_Texture **MainTexture,SDL_Surface **Background, SDL_Renderer **MainRender, SDL_Rect *Box) { // Помещение изображения в очередь для рендеринга
    *MainTexture = SDL_CreateTextureFromSurface(*MainRender,*Background);
    SDL_RenderCopy(*MainRender,*MainTexture,NULL,Box);
}
void Print_Text(SDL_Renderer **MainRender, SDL_Texture **MainTexture, TTF_Font **MainFont, char *Text, SDL_Rect *Box) { //Вывод теста
    SDL_Surface *TextSurface;
    SDL_Color Color;
    Color.a = 255;
    Color.r = 254;
    Color.g = 254;
    Color.b = 254;
    TextSurface = TTF_RenderText_Solid(*MainFont,Text,Color);
    Copy_Render(MainTexture,&TextSurface,MainRender,Box);
}
void Moving_Coursor(SDL_Renderer **MainRender, SDL_Texture **MainTexture, TTF_Font **MainFont, SDL_Event *Event, int Screen, int *Position, int Mode) { // Отслеживание курсора
    SDL_Rect Box;
    SDL_Surface *Background;
    int x = SCREEN_WIGHT/2-(SCREEN_WIGHT/4+SCREEN_WIGHT/8)/3, Pos_Min = 1, Pos_Max = 0;
    char Key_Up = 'w', Key_Down = 's';
    static int y = 4*SCREEN_HIGH/16+3*SCREEN_HIGH/12, Pos = 1;
    if(Screen == 4) {
        Pos = 1;
    }
    if(Screen == 1) {
        Pos_Max = 2;
    } else if (Screen != 4) {
        Pos_Max = 3;
    }

    if(Event->type == SDL_KEYDOWN) {
        if(Event->key.keysym.sym == Key_Up) { //Стрелка вниз
            if(Pos != Pos_Min) {
                Pos--;
            }
        }
        if (Event->key.keysym.sym == Key_Down) { //Стрелка вверх
            if(Pos != Pos_Max) {
                Pos++;
            }
        }
        *Position = Pos;
        y = 4*SCREEN_HIGH/16+((Pos-1)*2+3)*SCREEN_HIGH/12;
    }
    if(Screen != 4) {
        Background = IMG_Load("src/Resources/Images/Cursor.png");
        SDL_SetColorKey(Background,SDL_TRUE,SDL_MapRGB( Background->format, 255, 255, 255 ));
        Box = Boxing(x,y,SCREEN_WIGHT/20,SCREEN_WIGHT/20);
        Copy_Render(MainTexture,&Background,MainRender,&Box);
    }
    if(Screen == 1) {
        Box = Boxing(x+SCREEN_WIGHT/15,4*SCREEN_HIGH/16+3*SCREEN_HIGH/12-SCREEN_WIGHT/60,SCREEN_WIGHT/10,SCREEN_WIGHT/15);
        Print_Text(MainRender,MainTexture,MainFont,"Start",&Box);
        Box = Boxing(x+SCREEN_WIGHT/15,4*SCREEN_HIGH/16+5*SCREEN_HIGH/12-SCREEN_WIGHT/60,SCREEN_WIGHT/12,SCREEN_WIGHT/15);
        Print_Text(MainRender,MainTexture,MainFont,"Exit",&Box);
    }
    if(Screen == 2) {
        Box = Boxing(x+SCREEN_WIGHT/15,4*SCREEN_HIGH/16+3*SCREEN_HIGH/12-SCREEN_WIGHT/60,SCREEN_WIGHT/8,SCREEN_WIGHT/15);
        Print_Text(MainRender,MainTexture,MainFont,"Only words",&Box);
        Box = Boxing(x+SCREEN_WIGHT/15,4*SCREEN_HIGH/16+5*SCREEN_HIGH/12-SCREEN_WIGHT/60,SCREEN_WIGHT/8,SCREEN_WIGHT/15);
        Print_Text(MainRender,MainTexture,MainFont,"Only numbers",&Box);
        Box = Boxing(x+SCREEN_WIGHT/15,4*SCREEN_HIGH/16+7*SCREEN_HIGH/12-SCREEN_WIGHT/60,SCREEN_WIGHT/6,SCREEN_WIGHT/15);
        Print_Text(MainRender,MainTexture,MainFont,"Words and numbers",&Box);
    }
    if(Screen == 3) {
        if(Mode == 1) {
            Box = Boxing(x+SCREEN_WIGHT/15,4*SCREEN_HIGH/16+3*SCREEN_HIGH/12-SCREEN_WIGHT/60,SCREEN_WIGHT/6,SCREEN_WIGHT/15);
            Print_Text(MainRender,MainTexture,MainFont,"Enter a letters",&Box);
            Box = Boxing(x+SCREEN_WIGHT/15,4*SCREEN_HIGH/16+5*SCREEN_HIGH/12-SCREEN_WIGHT/60,SCREEN_WIGHT/6,SCREEN_WIGHT/15);
            Print_Text(MainRender,MainTexture,MainFont,"Enter a words",&Box);
            Box = Boxing(x+SCREEN_WIGHT/15,4*SCREEN_HIGH/16+7*SCREEN_HIGH/12-SCREEN_WIGHT/60,SCREEN_WIGHT/6,SCREEN_WIGHT/15);
            Print_Text(MainRender,MainTexture,MainFont,"Enter a suggestions",&Box);
        }
        if(Mode == 2) {
            Box = Boxing(x+SCREEN_WIGHT/15,4*SCREEN_HIGH/16+3*SCREEN_HIGH/12-SCREEN_WIGHT/60,SCREEN_WIGHT/6,SCREEN_WIGHT/15);
            Print_Text(MainRender,MainTexture,MainFont,"Enter a number",&Box);
            Box = Boxing(x+SCREEN_WIGHT/15,4*SCREEN_HIGH/16+5*SCREEN_HIGH/12-SCREEN_WIGHT/60,SCREEN_WIGHT/6,SCREEN_WIGHT/15);
            Print_Text(MainRender,MainTexture,MainFont,"Enter a numbers",&Box);
            Box = Boxing(x+SCREEN_WIGHT/15,4*SCREEN_HIGH/16+7*SCREEN_HIGH/12-SCREEN_WIGHT/60,SCREEN_WIGHT/6,SCREEN_WIGHT/15);
            Print_Text(MainRender,MainTexture,MainFont,"Enter an equations",&Box);
        }
    }

}
void LoadScreen (SDL_Renderer **MainRender, SDL_Texture **MainTexture, TTF_Font **MainFont, int Screen) { // Загрузка рабочих экранов
    SDL_Rect Box;
    SDL_Surface *Background;

    Box = Boxing(0,0,SCREEN_WIGHT/2,SCREEN_HIGH);
    Background = IMG_Load("src/Resources/Images/Background.png");
    Copy_Render(MainTexture,&Background,MainRender,&Box);
    Box.x = SCREEN_WIGHT/2;
    SDL_RenderCopy(*MainRender,*MainTexture,NULL,&Box);

    if (Screen != 4) {

        Box = Boxing(SCREEN_WIGHT/2-(SCREEN_WIGHT/4+SCREEN_WIGHT/8)/2,SCREEN_HIGH/16,SCREEN_WIGHT/4+SCREEN_WIGHT/8,SCREEN_HIGH/2+SCREEN_HIGH/4+SCREEN_HIGH/6);
        Background = IMG_Load("src/Resources/Images/Menu.png");
        Copy_Render(MainTexture,&Background,MainRender,&Box);

        Box = Boxing(Box.x+SCREEN_WIGHT/12,Box.y+SCREEN_HIGH/12,SCREEN_WIGHT/6+SCREEN_WIGHT/16,SCREEN_HIGH/8);
        Print_Text(MainRender, MainTexture, MainFont, "KeyBoard", &Box);

        Box = Boxing(Box.x+(Box.w-SCREEN_WIGHT/11)/3,Box.y+Box.h,Box.w-SCREEN_WIGHT/10,Box.h-Box.h/6);
        Print_Text(MainRender, MainTexture, MainFont, "Ninja", &Box);

        Box = Boxing(SCREEN_WIGHT/14,SCREEN_HIGH-SCREEN_HIGH/6,SCREEN_WIGHT/20,SCREEN_WIGHT/20);
        Background = IMG_Load("src/Resources/Images/S.png");
        Copy_Render(MainTexture,&Background,MainRender,&Box);

        Box = Boxing(SCREEN_WIGHT/14,SCREEN_HIGH-SCREEN_HIGH/6-SCREEN_WIGHT/20,SCREEN_WIGHT/20,SCREEN_WIGHT/20);
        Background = IMG_Load("src/Resources/Images/W.png");
        Copy_Render(MainTexture,&Background,MainRender,&Box);
    } else {
        Box = Boxing(0,0,SCREEN_WIGHT,SCREEN_HIGH/2);
        Background = IMG_Load("src/Resources/Images/Game_Screen.png");
        Copy_Render(MainTexture,&Background,MainRender,&Box);

        Box = Boxing(SCREEN_WIGHT/14,SCREEN_HIGH/14,SCREEN_WIGHT/10,SCREEN_HIGH/8);
        Print_Text(MainRender,MainTexture,MainFont,"Text:",&Box);

        Box = Boxing(SCREEN_WIGHT/14,SCREEN_HIGH/2-SCREEN_HIGH/5,SCREEN_WIGHT/10,SCREEN_HIGH/8);
        Print_Text(MainRender,MainTexture,MainFont,"Score:",&Box);

        Box = Boxing(SCREEN_WIGHT/14,SCREEN_HIGH-SCREEN_HIGH/6-SCREEN_WIGHT/20,SCREEN_WIGHT/20,SCREEN_WIGHT/20);
        Background = IMG_Load("src/Resources/Images/Exit.png");
        Copy_Render(MainTexture,&Background,MainRender,&Box);
    }
}
bool Analysis_Event(SDL_Event Event) {
    if(Event.type == SDL_KEYDOWN) {
        if(Event.key.keysym.sym == 13) {
            return true;
        }
    }
    return false;
}
