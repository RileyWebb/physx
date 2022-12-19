#include "debug.h"

// SIMULATION
typedef enum physx_simulation_state
{
    PHYSX_SIMULATION_STATE_IDLE = 0,
    PHYSX_SIMULATION_STATE_COMPLETE = 1,
    PHYSX_SIMULATION_STATE_IN_PROGRESS = 2,
} physx_simulation_state_t;

struct physx_program_s;
typedef struct physx_program_s physx_program_t;

typedef struct physx_simulation_s {
    char *name;
    physx_simulation_state_t state;

    //OBJECTS AND COUNT

    //XML DEFINITION
    //RESOURCES
    physx_program_t *program;
} physx_simulation_t;

void physx_load_simulation();
void physx_build_simulation(physx_simulation_t *sim);
void *physx_register_simulation();

// GENERAL
int physx_init();
int physx_start(physx_simulation_t *simulation);
void physx_update();

