#ifndef WINDOW_H
#define WINDOW_H
#include <SDL.h>

class Window {
    public:
        SDL_Window *window = nullptr;
        SDL_Renderer *renderer = nullptr;
        SDL_Surface *surface = nullptr;

        void createWindow(const char *title, int width, int height) {
            SDL_Init(SDL_INIT_VIDEO);
            
            window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            surface = SDL_GetWindowSurface(window);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        }
        void destroyWindow() {
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
        }


};
#endif // WINDOW_H
