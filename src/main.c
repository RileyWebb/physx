#include <physx/physx.h>
#include <stdio.h>

//#include <libxml2/libxml/parser.h>


int main()
{
    physx_build_simulation((void*)0);
    physx_load_simulation();
    physx_init();


    //physx_start(&sim);
    return 0;
}
