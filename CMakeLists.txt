cmake_minimum_required(VERSION 3.10.0)
project(SpatialHashing VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include utils)
add_executable(SpatialHashing 
    src/main.cpp
    src/glad.c
    utils/glslprogram.cpp
    utils/GLUtils.cpp)

target_link_libraries(SpatialHashing glfw)

