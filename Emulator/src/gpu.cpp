#include "include/gpu.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

GPU::GPU() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        // Handle initialization error
        SDL_Log("SDL initialization failed: %s", SDL_GetError());
        // Handle error, throw an exception, or exit the program
    }

    // Create a window and renderer
    window = SDL_CreateWindow("Emulator Screen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (!window) {
        // Handle window creation error
        SDL_Log("Window creation failed: %s", SDL_GetError());
        SDL_Quit();
        // Handle error, throw an exception, or exit the program
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        // Handle renderer creation error
        SDL_Log("Renderer creation failed: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        // Handle error, throw an exception, or exit the program
    }
}

GPU::~GPU() {
    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
} 

void GPU::drawPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderDrawPoint(renderer, x, y);
}

void GPU::update() {
    SDL_RenderPresent(renderer);
}

void GPU::reset() {
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}