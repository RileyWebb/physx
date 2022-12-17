#include <physx/physx.h>

void *test()
{
    printf("abcdefg\n");
}

int main()
{
    physx_init();
    physx_simulation sim = {
            .late_update = NULL,
            .update = &test,
    };

    physx_start(&sim);
    return 0;
}
