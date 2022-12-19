cmake_minimum_required(VERSION 3.25)
project(physx C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

find_package(SDL2 REQUIRED)

include_directories(include)
add_executable(physx src/main.c include/physx/geometry.h include/physx/physx.h src/physx.c include/physx/debug.h src/debug.c src/window.c include/physx/window.h src/simulation.c)
target_link_libraries(physx ${SDL2_LIBRARIES} tcc)

add_custom_target(copy_headers ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/include)

add_custom_target(copy_examples ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/examples
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/examples)

add_dependencies(physx copy_headers copy_examples)