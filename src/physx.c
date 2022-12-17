#include "physx/physx.h"

SDL_Window *window;
physx_simulation *currentSimulation;

int physx_init() {

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {

    }

    return 0;
}

int physx_start(physx_simulation *simulation) {
    if (simulation != NULL) {
        currentSimulation = simulation;
        window SDL_CreateWindow(currentSimulation->name, 1000, 1000, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0);

    }



    while (1) physx_update();

    return 0;
}

void physx_update()
{
    ((void(*)())currentSimulation->update)();
}