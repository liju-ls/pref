#include <sdl3/SDL.h>

int main()
{
    bool isGameRunning = true;

    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("pref", 800, 600, SDL_WINDOW_BORDERLESS);

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
    }

    SDL_Delay(1000);

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}