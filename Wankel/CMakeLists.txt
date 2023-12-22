set(HEADER_FILES 
	include/Wankel.h
	WankelApp.h
	Events.h
	GameWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
	GLFWCode/OpenGLPicture.h
	GLFWCode/OpenGLRenderer.h
	GLFWCode/OpenGLShader.h
	Picture.h
	PictureImplementation.h
	Renderer.h
	RendererImplementation.h
	Shader.h
	ShaderImplementation.h
	Unit.h
	Utilities.h
)

set(SOURCE_FILES 
	Events.cpp
	GameWindow.cpp
	GLFWCode/GLFWImplementation.cpp
	GLFWCode/OpenGLPicture.cpp
	GLFWCode/OpenGLRenderer.cpp
	GLFWCode/OpenGLShader.cpp
	Picture.cpp
	Renderer.cpp
	Shader.cpp
	Unit.cpp
)

add_definitions(-DWK_DEBUG=2)
add_definitions(-DWANKEL_LIB)

include_directories(../Wankel)
include_directories(../glfw/include)
include_directories(../glad/include)
include_directories(../stbi)

add_library(Wankel SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Wankel PRIVATE pch.h)

target_link_libraries(Wankel glfw)
target_link_libraries(Wankel glad)
target_link_libraries(Wankel stbi)