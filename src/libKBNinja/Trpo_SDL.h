#include "../SDL/include/SDL2/SDL.h"
#include "../SDL/include/SDL2/SDL_image.h"
#include "../SDL/include/SDL2/SDL_ttf.h"
#pragma once

void Load (SDL_Window **MainWindow,  SDL_Renderer **MainRender, SDL_Surface **MainSurface, TTF_Font **MainFont);
void Close (SDL_Window **MainWindow, SDL_Renderer **MainRender, SDL_Texture **MainTexture, SDL_Surface **MainSurface, TTF_Font **MainFont);
SDL_Rect Boxing(int x, int y, int Wight, int Hight);
void Copy_Render(SDL_Texture **MainTexture,SDL_Surface **Background, SDL_Renderer **MainRender, SDL_Rect *Box);
void Print_Text(SDL_Renderer **MainRender, SDL_Texture **MainTexture, TTF_Font **MainFont, char *Text, SDL_Rect *Box);
void Moving_Coursor(SDL_Renderer **MainRender, SDL_Texture **MainTexture, TTF_Font **MainFont, SDL_Event *Event, int Screen, int *Position, int Mode);
void LoadScreen (SDL_Renderer **MainRender, SDL_Texture **MainTexture, TTF_Font **MainFont,int Screen);
bool Analysis_Event(SDL_Event Event);
