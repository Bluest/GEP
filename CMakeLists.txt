cmake_minimum_required(VERSION 2.6)

project(MMG)

include_directories(
	contrib
	src/MMG
)

add_library(MMG
	src/MMG/MMG.h
	src/MMG/Core.h
	src/MMG/Core.cpp
	src/MMG/Entity.h
	src/MMG/Entity.cpp
	src/MMG/Component.h
	src/MMG/Component.cpp
	src/MMG/TriangleRenderer.h
	src/MMG/TriangleRenderer.cpp
)

target_link_libraries(MMG SDL2 opengl32 glew32)

add_executable(game
	src/game/main.cpp
)

target_link_libraries(game MMG)