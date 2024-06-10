#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

class player
{
    public:
        SDL_Rect posRect;
        SDL_Rect playerRect;
        int speed;

        player(int x, int y, int width, int height);
        draw(SDL_Renderer* renderer);
        move(const Uint8* state, int windowWidth, int windowHeight, double deltaTime);
};

#endif // PLAYER_H