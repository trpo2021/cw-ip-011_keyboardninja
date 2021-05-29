#include "../libKBNinja/Comparator.h"
#include "../libKBNinja/Duel.h"
#include "../libKBNinja/Exit.h"
#include "../libKBNinja/Numbers.h"
#include "../libKBNinja/Pattern_read.h"
#include "../libKBNinja/Prepare.h"
#include "../libKBNinja/Worlds.h"
#include "../libKBNinja/Worlds_and_Numbers.h"
/*#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>*/
#include "../libKBNinja/Trpo_SDL.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

/*int main()
{
    SetConsoleOutputCP( 65001 );
    setlocale(LC_ALL, NULL);
    srand(time(NULL));

    int Mode = 0, Difficulty = 0, testing = 0;
    bool Game = true;

    while (Game) // Вся логика программы
    {
        system("cls");                                         //
        printf("\tПривет, хочешь преисполниться в печати?\n"); //
        Prepare(&Mode,
                &Difficulty,
                testing); //  выбираем режим игры и уровень сложности
        // printf("\n%d %d\n", Mode, Difficulty);                  // выводим
        // значения, которые выбрал пользователь
        Duel(Mode, Difficulty, testing);

        system("PAUSE");      //
        Game = Exit(testing); // Проверяем хочет ли пользователь потренироваться
                              // ещё раз или нет
    }
    system("cls");
    printf("Спасибо за игру, возвращайтесь!\n");

    system("PAUSE");
    return 0;
}*/

int main (int argc, char *args[]) {
    SetConsoleOutputCP( 65001 );
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    SDL_Window *MainWindow = NULL;
    SDL_Surface *MainSurface = NULL;
    SDL_Renderer *MainRender = NULL;
    SDL_Texture *MainTexture = NULL;
    int Screen = 1, Position = 1, Mode = 0, Difficulty = 0, testing = 0;
    bool Quit = false;
    SDL_Event Event;
    TTF_Font *MainFont;


    Load(&MainWindow,&MainRender,&MainSurface,&MainFont);

    while(Quit == false) {
        printf("%s ", SDL_GetError());
        SDL_SetRenderDrawColor(MainRender,255,255,255,255);
        SDL_RenderClear(MainRender);

        LoadScreen(&MainRender,&MainTexture,&MainFont,Screen);

        while(SDL_PollEvent(&Event)) {
            if(Screen != 4) {
                Moving_Coursor(&MainRender,&MainTexture,&MainFont,&Event,Screen,&Position, Mode);
            }
            if(Screen == 1) {
                if(Position == 1) {
                    if(Analysis_Event(Event) == true) {
                        Screen = 2;
                    }
                } else if(Position == 2) {
                    if(Analysis_Event(Event) == true) {
                        Event.type = SDL_QUIT;
                    }
                }
            } else if(Screen == 2) {
                if(Position == 1) {
                    if(Analysis_Event(Event) == true) {
                        Screen = 3;
                        Mode = 1;
                    }
                }
                if(Position == 2) {
                    if(Analysis_Event(Event) == true) {
                        Screen = 3;
                        Mode = 2;
                    }
                }
                if(Position == 3) {
                    if(Analysis_Event(Event) == true) {
                        Screen = 4;
                        Mode = 3;
                        Moving_Coursor(&MainRender,&MainTexture,&MainFont,&Event,Screen,&Position, Mode);
                        Duel(&MainRender,&MainTexture,&MainFont,&Mode, &Difficulty,&Screen, testing);
                        Difficulty = 0;
                        Mode = 0;
                        Position = 1;
                        SDL_RenderClear(MainRender);
                        LoadScreen(&MainRender,&MainTexture,&MainFont,Screen);
                    }
                }
            } else if(Screen == 3) {
                if(Position == 1) {
                    if(Analysis_Event(Event) == true) {
                        Screen = 4;
                        Difficulty = 1;
                    }
                }
                if(Position == 2) {
                    if(Analysis_Event(Event) == true) {
                        Screen = 4;
                        Difficulty = 2;
                    }
                }
                if(Position == 3) {
                    if(Analysis_Event(Event) == true) {
                        Screen = 4;
                        Difficulty = 3;
                    }
                }
                if(Difficulty != 0) {
                    Moving_Coursor(&MainRender,&MainTexture,&MainFont,&Event,Screen,&Position, Mode);
                    Duel(&MainRender,&MainTexture,&MainFont,&Mode, &Difficulty,&Screen, testing);
                    Difficulty = 0;
                    Mode = 0;
                    Position = 1;
                    SDL_RenderClear(MainRender);
                    LoadScreen(&MainRender,&MainTexture,&MainFont,Screen);
                }
            }
            if(Event.type == SDL_QUIT) {
                Quit = true;
            }
        }
        Moving_Coursor(&MainRender,&MainTexture,&MainFont,&Event,Screen,&Position, Mode);

        SDL_RenderPresent(MainRender);

        SDL_Delay(100);
    }

    Close(&MainWindow,&MainRender,&MainTexture,&MainSurface,&MainFont);


    return 0;
}
