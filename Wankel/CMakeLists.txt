set(HEADER_FILES 
	include/Wankel.h
	WankelApp.h
	Utilities.h
	GameWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
)

set(SOURCE_FILES 
	GameWindow.cpp
	GLFWCode/GLFWImplementation.cpp
)

add_definitions(-DWK_DEBUG=2)
add_definitions(-DWANKEL_LIB)

include_directories(../Wankel)
include_directories(../glfw/include)

add_library(Wankel SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Wankel PRIVATE pch.h)

target_link_libraries(Wankel glfw)