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
        world/Location.h world/Location.cpp
        messages/TextMessage.h messages/TextMessage.cpp
        nodes/Repeater.h nodes/Repeater.cpp
        nodes/Terminal.h nodes/Terminal.cpp
        world/World.h world/World.cpp
        nodes/CommunicationNode.cpp nodes/CommunicationNode.h
        messages/Message.cpp messages/Message.h
        Clock.cpp Clock.h
        RandomGenerator.cpp RandomGenerator.h
        Logger.cpp Logger.h
        nodes/NodeScheduler.cpp nodes/NodeScheduler.h)

add_executable(tests
        world/Location-test.cpp
        messages/Message-test.cpp
        messages/TextMessage-test.cpp
        nodes/Terminal-test.cpp
        nodes/Repeater-test.cpp
        world/World-test.cpp Clock-test.cpp
        RandomGenerator-test.cpp
        Logger-test.cpp
        nodes/NodeScheduler-test.cpp)


target_link_libraries(tests
        PRIVATE Catch2::Catch2WithMain
        papillon_lib)

add_executable(simulator main.cpp)
target_link_libraries(simulator
        papillon_lib)