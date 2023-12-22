cmake_minimum_required(VERSION 3.24)

project(Game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DWANKEL_MSCPP)
elseif(LINUX)
	add_definitions(-DWANKEL_LINUX)
elseif(APPLE)
	add_definitions(-DWANKEL_APPLE)
endif()

add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(stbi)
add_subdirectory(Wankel)
add_subdirectory(Game_JM)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Game_JM)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR})
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)