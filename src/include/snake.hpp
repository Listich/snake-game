#ifndef SNAKE_HPP
#define SNAKE_HPP
#include <iostream>
#include <SDL.h>

struct Snake
{
    public:
    void start();
    bool gameOver;
    int score = 0;
    enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN};
    Direction dir;
    int tailX[100], tailY[100]; 
    int nTail = 0;
    int largeur_grille = 20;
    int hauteur_grille = 20;
    int x, y, fruitX, fruitY;
    int vitesse = 150;

    void Update();
    void render(Window &window);

};

#endif // SNAKE_HPP