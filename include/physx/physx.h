#include <SDL2/SDL.h>
#include <SDL2/SDL.h>
#include "debug.h"

typedef enum physx_simulation_state_t
{
    PHYSX_SIMULATION_STATE_IDLE = 0,
    PHYSX_SIMULATION_STATE_COMPLETE = 1,
    PHYSX_SIMULATION_STATE_IN_PROGRESS = 2,
} physx_simulation_state;

typedef struct physx_simulation_t {
    char *name;
    physx_simulation_state state;
    physx_window *window;
    // Functions
    void *start;
    void *update;
    void *late_update;
    void *end;
} physx_simulation;

extern SDL_Window *window;

int physx_init();
int physx_start(physx_simulation* simulation);
void physx_update();