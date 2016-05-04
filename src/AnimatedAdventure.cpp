#include <iostream>
#include "Survival.h"
#include "Options.h"
#include "About.h"
#include "ToDo.h"
#include "Font.h"
#include "SDL.h"
#include "AnimatedAdventure.h"
#include "SDL.h"
#include "Textures.h"


using namespace std;

#define MAPW 100
#define MAPH 100

#define SCREENW MAPW + 200
#define SCREENH MAPH

AnimatedAdventure::AnimatedAdventure()
{
    StartAdventure();



}

void AnimatedAdventure::StartAdventure()
{
    HandlePaintEvent();
}

void AnimatedAdventure::HandlePaintEvent()
{
    SDL_Window* window = NULL;
    SDL_Renderer* rend = NULL;
    SDL_CreateWindowAndRenderer(SCREENW, SCREENH, SDL_WINDOW_SHOWN, &window, &rend);

    Textures texture;

    SDL_Event event;
    SDL_RenderClear(rend);
    do
    {
        SDL_WaitEvent(&event);
        SDL_SetRenderDrawColor(rend, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(rend);

        //Textures.h is broken
        //texture.paintWater();

        SDL_RenderPresent(rend);
    }while(event.type != SDL_QUIT);

    //SDL_SetWindowTitle(window, WINDOWTITLE);
    //FNT_DestroyFont(font);

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(rend);
    SDL_Quit();

}


AnimatedAdventure::~AnimatedAdventure()
{}
