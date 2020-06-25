#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include "greycode.h"

#define WINDOW_WIDTH 256

unsigned grid[256][256] = {0};


int main(){
    /*SDL init*/
    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetWindowTitle(window, "hilbert entropy");

    /* do stuff*/

    SDL_RenderPresent(renderer);
    while(1)if(SDL_PollEvent(&event)&&event.type==SDL_QUIT)break;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}