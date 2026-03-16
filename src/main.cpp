#include <SDL.h>
#include <iostream>
#include "include/window.hpp"
#include "include/snake.hpp"


int main() {
    Window window;

    window.createWindow("Snake Game", 800, 600);
    Snake snake;
    snake.start();
    bool running = true;
    SDL_Event event;
    int lastTime = SDL_GetTicks();
    int frameDelay = 0;

    while(running) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        if (snake.dir != Snake::LEFT) snake.dir = Snake::LEFT;
                        break;
                    case SDLK_RIGHT:
                        if (snake.dir != Snake::RIGHT) snake.dir = Snake::RIGHT;
                        break;
                    case SDLK_UP:
                        if (snake.dir != Snake::UP) snake.dir = Snake::UP;
                        break;
                    case SDLK_DOWN:
                        if (snake.dir != Snake::DOWN) snake.dir = Snake::DOWN;
                        break;
                    default:
                        break;
                }
            }
        }
        int currentTime = SDL_GetTicks();
        frameDelay += (currentTime - lastTime);
        lastTime = currentTime;

        if (frameDelay >= snake.vitesse) {
            snake.Update();
            frameDelay = 0;
            std::string scoreTitle = "Snake Game | Score: " + std::to_string(snake.score);
            SDL_SetWindowTitle(window.window, scoreTitle.c_str());
        }
        if (snake.gameOver) {
            snake.render(window);
            SDL_RenderPresent(window.renderer);
            SDL_Delay(1000);
            snake.start();

        }
        SDL_SetRenderDrawColor(window.renderer, 0, 0, 0, 255);
        SDL_RenderClear(window.renderer);
        snake.render(window); 
        SDL_RenderPresent(window.renderer);
    }
    window.destroyWindow();
    return 0;
}