#include "Game.h"

Game *game = nullptr;

int main(int argc, char *args[]){
    const int FPS = 60;
    const int FrameDelay = 1000 / FPS;

    Uint32 framestart;
    int frametime;

    game = new Game();
    game->init("ShoTvoru", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

    while(game->running()){
        framestart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frametime = SDL_GetTicks() - framestart;

        if(FrameDelay > frametime)
        {
            SDL_Delay(FrameDelay - frametime);
        }
    }

    game->clean();

    return 0;
}