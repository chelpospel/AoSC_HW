cmake_minimum_required(VERSION 3.17)
project(HomeWorkABC LANGUAGES CXX)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

set(SOURCE_FILES
        rnd.h
        object_oriented.h
        functional.h
        procedural.h
        shape.h
        container.h

        rnd.cpp
        object_oriented.cpp
        functional.cpp
        procedural.cpp
        shape.cpp
        container.cpp
        main.cpp)

add_executable(HomeWorkABC ${SOURCE_FILES})
