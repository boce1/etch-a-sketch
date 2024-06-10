#include "player.hpp"
#include <SDL2/SDL.h>
#include <iostream>

player::player(int x, int y, int width, int height) 
{
    playerRect.x = x;
    playerRect.y = y;
    playerRect.w = width;
    playerRect.h = height;

    posRect.w = width / 4;
    posRect.h = height / 4;
    posRect.x = playerRect.x + playerRect.w / 2 - posRect.w / 2;
    posRect.y = playerRect.y + playerRect.h / 2 - posRect.h / 2;

    speed = 1;
}

player::draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    SDL_RenderFillRect(renderer, &playerRect);
    SDL_SetRenderDrawColor(renderer, 255,0,0,50);
    SDL_RenderDrawRect(renderer, &posRect);
}

player::move(const Uint8* state, int windowWidth, int windowHeight, double deltaTime)
{
    if (state[SDL_SCANCODE_W] && playerRect.y > 0) 
    {
        playerRect.y -= (int)(speed * deltaTime);
        posRect.y -= (int)(speed * deltaTime);
    }
    if (state[SDL_SCANCODE_S] && playerRect.y + playerRect.h < windowHeight) 
    {
        playerRect.y += (int)(speed * deltaTime);
        posRect.y += (int)(speed * deltaTime);
    }
    if (state[SDL_SCANCODE_A] && playerRect.x > 0) 
    {
        playerRect.x -= (int)(speed * deltaTime);
        posRect.x -= (int)(speed * deltaTime);
    }
    if (state[SDL_SCANCODE_D] && playerRect.x + playerRect.w < windowWidth) 
    {
        playerRect.x += (int)(speed * deltaTime);
        posRect.x += (int)(speed * deltaTime);
    }
}