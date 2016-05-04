#include <iostream>
#include "Survival.h"
#include "Options.h"
#include "About.h"
#include "ToDo.h"
#include "Font.h"
#include "SDL.h"
#include "AnimatedAdventure.h"
#include "Sound.h"
#include "Textures.h"

#include "Minion.h"

#define MAPW 400
#define MAPH 400

#define SCREENW ( (MAPW + 200))
#define SCREENH MAPH


using namespace std;


char* WINDOWTITLE = "Gloryave v. 0.30";


void handleTextureEvent(SDL_Texture* Tex, SDL_Renderer* rend, double stepw, double steph)
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
}



// The Width and height of the box (matched up with text size)
// THIS IS PROPORTIONAL 3 TO 2 (rectWidth, rectHeight respectively)
#define rectWidthDefault 30
#define rectHeightDefault 20
#define rectWidth rectWidthDefault
#define rectHeight rectHeightDefault
// The x bounds for the selection box
// THIS IS A DIFFERENCE OF 30 (xboxRight - xBoxLeft = 30) SHOULD REMAAIN SUCH
#define xBoxLeftDefault 10
#define xBoxRightDefault 40
#define xBoxLeft xBoxStart
#define xBoxRight xBoxStart + 30
// The starting point for both the box and the text
// Change this to adjust location of menu settings or display objects on screen
// THIS IS PROPORTIONAL 1 TO 1 (x, y respectively)
#define BoxStartDefault 10
#define xBoxStart 100
#define yBoxStart 150

// DO NOT AJUST (IS SCALLED CORRECTLY FOR THE CURRENT FORMAT)
#define maxY yBoxStart + 200

int handleBoxAndClickEvent(SDL_Renderer* rend, SDL_Event event)
{
    // for(int y = 10; y <= 210; y += 40)
    for(int y = yBoxStart; y <= maxY; y += 40)
    {
        SDL_Rect rect;
        rect.x = xBoxStart;
        rect.y = y;
        rect.w = rectWidth;
        rect.h = rectHeight;
        SDL_RenderFillRect(rend, &rect);
    }

    if(event.type == SDL_MOUSEBUTTONUP)
    {
        if(event.button.button == SDL_BUTTON_LEFT)
        {
            int xPos = event.button.x;
            int yPos = event.button.y;
            if( xPos < xBoxRight && xPos > xBoxLeft && yPos < yBoxStart + rectHeight && yPos > yBoxStart)
            {
                //cout << "BUTTON 1 PRESSED" << endl;
                return 1;
            }
            else if( xPos < xBoxRight && xPos > xBoxLeft && yPos < yBoxStart + 40 + rectHeight && yPos > yBoxStart + 40)
            {
                //Survival();
                return 2;
            }
            else if( xPos < xBoxRight && xPos > xBoxLeft && yPos < yBoxStart + 80 + rectHeight && yPos > yBoxStart + 80)
            {
                //cout << "BUTTON 3 PRESSED" << endl;
                return 3;
            }
            else if( xPos < xBoxRight && xPos > xBoxLeft && yPos < yBoxStart + 120 + rectHeight && yPos > yBoxStart + 120)
            {
                //Options();
                return 4;
            }
            else if( xPos < xBoxRight && xPos > xBoxLeft && yPos < yBoxStart + 160 + rectHeight && yPos > yBoxStart + 160)
            {
                //About();
                return 5;
            }
            else if( xPos < xBoxRight && xPos > xBoxLeft && yPos < yBoxStart + 200 + rectHeight && yPos > yBoxStart + 200)
            {
                //ToDo();
                return 6;
            }
        }
    }
    return -1;
}

int main(int argv, char** args)
{

    Enemy enemy;
    Minion minion;

    Enemy *enem;
    enem = &minion;

    // enem->Test();

    cout << WINDOWTITLE << endl << endl;

    SDL_Window* window = NULL;
    SDL_Renderer* rend = NULL;
    SDL_CreateWindowAndRenderer(SCREENW, SCREENH, SDL_WINDOW_SHOWN, &window, &rend);

    SDL_SetWindowTitle(window, WINDOWTITLE);

    //AUDIO = BROKEN, check out Sound.cpp for comment on top of file
    //AUD_Sound* music = AUD_LoadWAV("Hyoshiaction2.wav", 1);
    //AUD_Play(music);

    SDL_Surface* GRASS = SDL_LoadBMP("GRASS.bmp");
    if(!GRASS)
    {
        cout << "ERROR-> GRASS NOT LOADED" << endl;
        return 1;
    }
    SDL_Texture* GrassTex = SDL_CreateTextureFromSurface(rend, GRASS);
    SDL_FreeSurface(GRASS);

    SDL_Surface* Water = SDL_LoadBMP("Water.bmp");
    if(!Water)
    {
        cout << "ERROR-> Water NOT LOADED" << endl;
        return 1;
    }
    SDL_Texture* WaterTex = SDL_CreateTextureFromSurface(rend, Water);
    SDL_FreeSurface(Water);


    SDL_Color color;
        color.r = 0;
        color.g = 40;
        color.b = 70;

    FNT_Font* font = FNT_InitFont(rend, "540x20Font.bmp", "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", 3, 4, color);

    SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(rend);

    double stepw = MAPW / 40;
    double steph = MAPH / 40;

    SDL_Event event;

    int optionChosen;
    do {
        SDL_WaitEvent(&event);

        SDL_SetRenderDrawColor(rend, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(rend);


        handleTextureEvent(GrassTex, rend, stepw, steph);


        optionChosen = handleBoxAndClickEvent(rend, event);

        FNT_DrawText(rend, font, "MAIN MENU" , xBoxStart + 100, yBoxStart - 100, 20, 0);
        FNT_DrawText(rend, font, "WELCOME TO A LAND OF ADVENTURE" , xBoxStart - 75, yBoxStart - 50, 20, 0);
        FNT_DrawText(rend, font, "CHOOSE AN OPTION NUMBER BELOW" , xBoxStart - 75, yBoxStart - 30, 20, 0);
        FNT_DrawText(rend, font, "1 START ADVENTURE" , xBoxStart, yBoxStart, 20, 0);
        FNT_DrawText(rend, font, "2 SURVIVAL" , xBoxStart, yBoxStart + 40, 20, 0);
        FNT_DrawText(rend, font, "3 PLAYER STATS", xBoxStart, yBoxStart + 80, 20, 0);
        FNT_DrawText(rend, font, "4 OPTIONS" , xBoxStart, yBoxStart + 120, 20, 0);
        FNT_DrawText(rend, font, "5 ABOUT" , xBoxStart, yBoxStart + 160, 20, 0);
        FNT_DrawText(rend, font, "6 TODO" , xBoxStart, yBoxStart + 200, 20, 0);

        SDL_RenderPresent(rend);

    } while (optionChosen == -1 && event.type != SDL_QUIT);

    FNT_DestroyFont(font);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(rend);
    SDL_Quit();

    switch(optionChosen)
    {
        case 1:
            AnimatedAdventure();
            break;
        case 2:
            Survival();
            break;
        case 3:
            break;
        case 4:
            Options();
            break;
        case 5:
            About();
            break;
        case 6:
            ToDo();
    }


    FNT_DestroyFont(font);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(rend);
    SDL_Quit();


    /*
    int choice;

    while(true)
    {
        cout << "Welcome to a land of adventure" << endl;
        cout << "Choose an option below" << endl;

        cout << "1. Start Adventure" << endl;
        cout << "2. Survival" << endl;
        cout << "3. Player Stats" << endl;
        cout << "4. Options" << endl;
        cout << "5. About" << endl;
        cout << "6. ToDo's (Future game ideas) (Developer)" << endl;
        cin >> choice;

        switch(choice)
        {
        case 1:
            break;
        case 2:
            Survival();
            break;
        case 3:
            break;
        case 4:
            Options();
            break;
        case 5:
            About();
            break;
        case 6:
            ToDo();
        }
    }
    */

    return 0;
}


