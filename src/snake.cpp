#include <iostream>
#include "include/window.hpp"
#include "include/snake.hpp"
#include <SDL.h>

void Snake::start() {
    std::cout << "Game Started!" << std::endl;
    gameOver = false;
    dir = STOP;
    x = largeur_grille / 2;
    y = hauteur_grille / 2;
    fruitX = rand() % largeur_grille;
    fruitY = rand() % hauteur_grille;
    score = 0;
    nTail = 0;
    vitesse = 150;

}
void Snake::Update() {
    if (gameOver) {
        return;
    }
    int prevX = x;
    int prevY = y;
    
    switch (dir) {
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case UP: y--; break;
        case DOWN: y++; break;
        default: break;
    }
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            gameOver = true;
            std::cout << "GAME OVER! Score: " << score << std::endl;
            return;
        }
    }
    if (x == fruitX && y == fruitY) {
        score += 10;
        nTail++;
        if (vitesse > 50) {
            vitesse -= 5; 
        }
        fruitX = rand() % largeur_grille;
        fruitY = rand() % hauteur_grille;
    }
    if (nTail > 0) {
        for (int i = nTail - 1; i > 0; i--) {
            tailX[0] = prevX;
            tailY[0] = prevY;
            tailX[i] = tailX[i - 1];
            tailY[i] = tailY[i - 1];
        }
        tailX[0] = prevX;
        tailY[0] = prevY;
    }
    if (x >= largeur_grille || x < 0 || y >= hauteur_grille || y < 0) {
        gameOver = true;
        std::cout << "GAME OVER! Score: " << score << std::endl;
    }

} 

void Snake::render(Window &window) {
    const int tileSize = 20;

    // 1. DESSIN DE LA GRILLE
    SDL_SetRenderDrawColor(window.renderer, 30, 30, 30, 255); 
    for (int i = 0 ; i <= largeur_grille; i++) {
        SDL_RenderDrawLine(window.renderer, i * tileSize, 0, i * tileSize, hauteur_grille * tileSize);
    }
    for (int i = 0 ; i <= hauteur_grille; i++) {
        SDL_RenderDrawLine(window.renderer, 0, i * tileSize, largeur_grille * tileSize, i * tileSize);
    }

    // 2. FRUIT
    SDL_Rect fruitRect = {fruitX * tileSize, fruitY * tileSize, tileSize, tileSize};
    SDL_SetRenderDrawColor(window.renderer, 255, 0, 0, 255); 
    SDL_RenderFillRect(window.renderer, &fruitRect);

    // 3. QUEUE
    SDL_SetRenderDrawColor(window.renderer, 0, 255, 0, 255);
    for (int i = 0; i < nTail; i++) {
        SDL_Rect tailRect = {tailX[i] * tileSize, tailY[i] * tileSize, tileSize, tileSize};
        SDL_RenderFillRect(window.renderer, &tailRect);
    }

    // 4. TÊTE 
    SDL_Rect headRect = {x * tileSize, y * tileSize, tileSize, tileSize};
    SDL_SetRenderDrawColor(window.renderer, 0, 200, 0, 255); 
    SDL_RenderFillRect(window.renderer, &headRect);
    
    // 5. EFFET COLLISION / GAMEOVER
    if (gameOver) {
        SDL_SetRenderDrawBlendMode(window.renderer, SDL_BLENDMODE_BLEND);
        SDL_Rect overlay = {0, 0, largeur_grille * tileSize, hauteur_grille * tileSize};
        SDL_SetRenderDrawColor(window.renderer, 255, 0, 0, 150);
        SDL_RenderFillRect(window.renderer, &overlay);
    }
}