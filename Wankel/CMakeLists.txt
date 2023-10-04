set(HEADER_FILES 
	includes/Wankel.h 
	WankelApp.h 
	Utilities.h 
)

set(SOURCE_FILES 
	placeholder.cpp 
)

add_definitions(-DWK_DEBUG=2)
add_definitions(-DWANKEL_LIB)

if(WIN32)
	add_definitions(-DWANKEL_MSCPP)
elseif(LINUX)
	add_definitions(-DWANKEL_LINUX)
elseif(APPLE)
	add_definitions(-DWANKEL_APPLE)
endif()

add_library(Wankel SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Wankel PRIVATE pch.h)