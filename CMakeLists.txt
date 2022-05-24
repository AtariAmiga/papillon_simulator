cmake_minimum_required(VERSION 3.5)

project(simulator CXX)
set(CMAKE_CXX_STANDARD 11)

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
        Location.h Location.cpp
        Message.h Message.cpp
        Repeater.h Repeater.cpp
        Terminal.h Terminal.cpp
        World.h World.cpp
        CommunicationNode.cpp CommunicationNode.h)

add_executable(tests
        Location-test.cpp)
target_link_libraries(tests
        PRIVATE Catch2::Catch2WithMain
        papillon_lib)

add_executable(simulator main.cpp)
target_link_libraries(simulator
        papillon_lib)