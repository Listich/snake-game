# SDL2 Snake Game

![alt text](<Capture d’écran 2026-03-16 à 23.57.10.png>)

A classic Snake game built from scratch using **C++** and the **SDL2** library. This project focuses on clean game loop logic, grid-based rendering, and progressive difficulty.

##  Features

- **Smooth Grid Movement**: Classic snake mechanics with precise 20x20 grid positioning.
- **Dynamic Difficulty**: The game speed increases every time you eat a fruit, making it more challenging over time.
- **Score Tracking**: Real-time score and speed display in the window title.
- **Visual Grid**: Includes a subtle background grid for better spatial awareness.
- **Collision System**: Robust detection for wall collisions and self-intersections.
- **Visual Feedback**: Screen-flash effect upon Game Over.

##  Technical Stack

- **Language**: C++
- **Graphics Library**: SDL2
- **Logic**: 
  - Delta-time based game loop (independent of CPU speed).
  - Memory-efficient tail management using coordinate arrays.

##  How to Play

### Prerequisites
You need to have **SDL2** installed on your system.
- **Mac (Homebrew)**: `brew install sdl2`
- **Linux**: `sudo apt-get install libsdl2-dev`

### Controls
| Key | Action |
|-----|--------|
| **Arrow Up** | Move Up |
| **Arrow Down** | Move Down |
| **Arrow Left** | Move Left |
| **Arrow Right** | Move Right |

##  Project Structure

- `src/`: Source files (`.cpp`).
- `include/`: Header files (`.hpp`).
- `main.cpp`: Entry point and main game loop.

##  Logic Overview

The game follows the standard **Input-Update-Render** pattern:
1. **Input**: Captures keyboard events to change direction (prevents 180° turns).
2. **Update**: Calculates the new head position, shifts the tail segments, and checks for collisions or fruit consumption.
3. **Render**: Clears the screen, draws the grid, fruit, and snake segments using `SDL_Renderer`.

---
*Created by Serena*