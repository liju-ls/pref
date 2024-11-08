#include <sdl3/SDL.h>
#include <iostream>

int main()
{
    bool isGameRunning = true;

    SDL_Window *window;
    SDL_Renderer *renderer;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("pref", 800, 600, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, NULL);

    if (window == NULL)
    {
        return 1;
    }

    while (isGameRunning)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_EVENT_QUIT:
                isGameRunning = false;
                break;

            default:
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_Delay(1000);

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}