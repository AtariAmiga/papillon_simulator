cmake_minimum_required(VERSION 3.5)

project(simulator C)
set(CMAKE_C_STANDARD 17)

project(tests CXX)
set(CMAKE_CXX_STANDARD 11)

Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.0-preview3
)

FetchContent_MakeAvailable(Catch2)

add_library(papillon_lib
        Terminal.h Terminal.c
        World.h World.c
        List.h List.c
        Message.h Message.c
        Repeater.h Repeater.c
        Location.h Location.c)

add_executable(tests Location-test.cpp)
target_link_libraries(tests
        PRIVATE Catch2::Catch2WithMain
        papillon_lib)

add_executable(simulator main.c)
target_link_libraries(simulator
        papillon_lib)