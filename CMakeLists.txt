cmake_minimum_required(VERSION 2.8.4)
project(MIPExercise1_dm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/Image.cpp
    src/Image.h
    src/ImageIO.cpp
    src/ImageIO.h
    src/MIPImageIO.cpp)

add_executable(MIPExercise1_dm ${SOURCE_FILES})