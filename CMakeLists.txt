cmake_minimum_required(VERSION 3.25)
project(physx C)

set(CMAKE_C_STANDARD 99)

find_package(SDL2 REQUIRED)

include_directories(include)
add_executable(physx src/main.c include/physx/geometry.h include/physx/physx.h src/physx.c include/physx/debug.h src/debug.c src/window.c include/physx/window.h include/physx/simulation.h)
target_link_libraries(physx ${SDL2_LIBRARIES} tcc)
