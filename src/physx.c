#include "physx/physx.h"

#include <SDL2/SDL.h>

SDL_Window *window;
physx_simulation_t *currentSimulation;

int physx_init() {

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {

    }
    //CREATE WINDOW
    //START EVENT LISTENER
    return 0;
}

int physx_start(physx_simulation_t *simulation) {
    if (simulation != NULL) {
        currentSimulation = simulation;
        //window SDL_CreateWindow(currentSimulation->name, 1000, 1000, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0);

    }



    while (1) physx_update();

    return 0;
}

void physx_update()
{
    //((void(*)())currentSimulation->update)();
}

void *physx_register_simulation(physx_simulation_t *sim) {
    printf("aasdadssadada\n");
    return NULL;
}
