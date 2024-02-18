#pragma once
#include <SDL2/SDL.h>

//GPU class that will handle output to the emulator screen using the SDL2 graphics engine
class GPU {
public:
    GPU();
    ~GPU();
    // Function to draw a pixel at (x, y) with RGB color
    void drawPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b);
    // Function to present the renderer
    void update();
    void reset();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};