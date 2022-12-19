#include "physx/physx.h"

#include <libtcc.h>
#include <stdio.h>
//#include <libxml2/libxml/parser.h>



typedef struct physx_program_s {
    TCCState *state;
    void *start_func;
    void *update_func;
    void *update_late_func;
    void *end_func;
} physx_program_t;


void *physx_simulation_error(void *v, const char *msg)
{
    printf("error: %s", msg);
}

void physx_load_simulation(char *path)
{

}

void physx_build_simulation(physx_simulation_t *sim)
{
    TCCState *buildState = tcc_new();

    tcc_add_include_path(buildState, "include");
    //tcc_add_include_path(buildState, "include"); INCLUDE WORKING DIRECTORY
    tcc_set_options(buildState, "-nostdlib");

    tcc_set_error_func(buildState, (void*)0, (void (*)(void *, const char *)) physx_simulation_error);

    char *program = "#include \"physx/physx.h\"\n"
                    "\n"
                    "physx_simulation_t simulation =\n"
                    "        {\n"
                    "            .name = \"test\"\n"
                    "        };\n"
                    "\n"
                    "physx_simulation_t* init()\n"
                    "{\n"
                    "\n"
                    "\n"
                    "    return &simulation;\n"
                    "}\n"
                    "\n"
                    "void start()\n"
                    "{\n"
                    "\n"
                    "}\n"
                    "\n"
                    "void update()\n"
                    "{\n"
                    "\n"
                    "}\n"
                    "\n"
                    "void late_update()\n"
                    "{\n"
                    "\n"
                    "}\n"
                    "\n"
                    "void end()\n"
                    "{\n"
                    "\n"
                    "}";

    if (tcc_compile_string(buildState, program) < 0)
        return;

    tcc_add_symbol(buildState, "physx_register_simulation", &physx_register_simulation);

    if (tcc_relocate(buildState, TCC_RELOCATE_AUTO) < 0)
    {
        //error
    }

    physx_simulation_t *asb = (physx_simulation_t*)tcc_get_symbol(buildState, "simulation");
    printf("name: %s\n", asb->name);

    void *init_func = tcc_get_symbol(buildState, "init");
    physx_simulation_t *test = ((physx_simulation_t*(*)()) init_func)();
    printf("name: %s\n", test->name);

    void *start_func = tcc_get_symbol(buildState, "start");
    ((void(*)()) start_func)();
}

void *physx_register_program(physx_simulation_t *sim)
{

}