#include <iostream>
#include <SDL2/SDL.h>
#include "player.hpp"

const int WIDTH = 600;
const int HEIGHT = 600;

void drawScreen(SDL_Renderer* renderer, player& p);
void clearScreen(SDL_Renderer* renderer, SDL_Event event);

int main(int argc, char* argv[]) 
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("hello world", 100, 100, WIDTH, HEIGHT, 0);
    if(window == NULL) 
    {
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    
    int playerWidth = WIDTH / 30;
    int playerHeight = HEIGHT / 30; 
    player p(WIDTH / 2 - playerWidth / 2, HEIGHT / 2 - playerHeight / 2, playerWidth, playerHeight);


    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderClear(renderer);
    bool running = true;
    SDL_Event event;
    const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
    Uint64 nowTicks = SDL_GetPerformanceCounter();
    Uint64 lastTicks = 0;
    double deltaTime = 0; 
    while(running)
    {
        lastTicks = nowTicks;
        nowTicks = SDL_GetPerformanceCounter();
        deltaTime = (double)((nowTicks - lastTicks)*1000 / (double)SDL_GetPerformanceFrequency());
        //std::cout << nowTicks - lastTicks << std::endl;
        //std::cout << (nowTicks - lastTicks) / SDL_GetPerformanceFrequency() << std::endl;
        keyboardState = SDL_GetKeyboardState(NULL);
        p.move(keyboardState, WIDTH, HEIGHT, deltaTime);
        //std::cout << deltaTime << std::endl;

        drawScreen(renderer, p);
        if(SDL_PollEvent(&event)) 
        {
            if(event.type == SDL_QUIT)
            {
                running = false;
            }
            clearScreen(renderer, event);
        }
        
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void drawScreen(SDL_Renderer* renderer, player& p)
{
    //SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    //SDL_RenderClear(renderer);
    p.draw(renderer);
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    SDL_RenderPresent(renderer);
    SDL_Delay(1);
}

void clearScreen(SDL_Renderer* renderer, SDL_Event event)
{
    if(event.type == SDL_KEYDOWN)
    {
        if(event.key.keysym.sym == SDLK_SPACE)
        {
            SDL_SetRenderDrawColor(renderer, 0,0,0,255);
            SDL_RenderClear(renderer);
        }
    }
    
}