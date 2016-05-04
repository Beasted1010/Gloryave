

#include "iostream"
#include "SDL.h"
using namespace std;

#define MAPW 400
#define MAPH 400

//THIS IS A DEAD FILE...
// PLAY WITH IT>.. TRY TO MAKE IT WORK

class Textures
{
    SDL_Renderer* rend = NULL;

    SDL_Surface* Water = SDL_LoadBMP("Water.bmp");
    SDL_Texture* WaterTex = SDL_CreateTextureFromSurface(rend, Water);
    //SDL_FreeSurface(Water);

    SDL_Surface* GRASS = SDL_LoadBMP("GRASS.bmp");
    SDL_Texture* GrassTex = SDL_CreateTextureFromSurface(rend, GRASS);
    //SDL_FreeSurface(GRASS);

    double stepw = MAPW / 40;
    double steph = MAPH / 40;

public:
    SDL_Texture* getWaterTex()
    {
        SDL_Surface* Water = SDL_LoadBMP("Water.bmp");
        if(!Water)
        {
            cout << "ERROR-> Water NOT LOADED" << endl;
            return NULL;
        }
        SDL_Texture* WaterTex = SDL_CreateTextureFromSurface(rend, Water);
        SDL_FreeSurface(Water);

        return WaterTex;
    }
    SDL_Texture* getGrassTex()
    {
        SDL_Surface* GRASS = SDL_LoadBMP("GRASS.bmp");
        if(!GRASS)
        {
            cout << "ERROR-> GRASS NOT LOADED" << endl;
            return NULL;
        }
        SDL_Texture* GrassTex = SDL_CreateTextureFromSurface(rend, GRASS);
        SDL_FreeSurface(GRASS);
        return GrassTex;
    }
    void paintWater()
    {
        SDL_FreeSurface(Water);
        int i;
        int j;
        for(i = 0; i < MAPW; i++)
        {
            for(j = 0; j < MAPH; j++)
            {
                SDL_Rect sdlr;
                sdlr.x = i * stepw;
                sdlr.y = j * steph;
                sdlr.w = stepw;
                sdlr.h = steph;
                SDL_RenderCopy(rend, WaterTex, NULL, &sdlr);
                cout << "PRINTING" << endl;
            }
        }

    }

    /*void handleTextureEvent(SDL_Texture* Tex, SDL_Renderer* rend, double stepw, double steph)
    {
        int i;
        int j;
        for(i = 0; i < MAPW; i++)
        {
            for(j = 0; j < MAPH; j++)
            {
                SDL_Rect sdlr;
                sdlr.x = i * stepw;
                sdlr.y = j * steph;
                sdlr.w = stepw;
                sdlr.h = steph;
                SDL_RenderCopy(rend, Tex, NULL, &sdlr);
            }
        }
    }*/

};
