cmake_minimum_required(VERSION 3.22)
project(papillon_simulator C)

set(CMAKE_C_STANDARD 17)

add_executable(papillon_simulator main.c)
add_library(papillon Emitter.h Emitter.c World.h World.c List.h List.c Message.c Message.h)
target_link_libraries(papillon_simulator papillon)