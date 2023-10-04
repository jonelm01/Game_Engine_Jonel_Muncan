cmake_minimum_required(VERSION 3.24)

project(Game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(Wankel)
add_subdirectory(Game_JM)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Game_JM)