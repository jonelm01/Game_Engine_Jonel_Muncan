set(HEADER_FILES 
	
)

set(SOURCE_FILES 
	main.cpp
)


add_executable(Game_JM ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(Game_JM Wankel)

include_directories(../Wankel/include)