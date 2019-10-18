cmake_minimum_required(VERSION 2.6)
project(MMG)

add_library(MMG
	src/MMG/Application.h
	src/MMG/Application.cpp
	src/MMG/Entity.h
	src/MMG/Entity.cpp
	src/MMG/Component.h
	src/MMG/Component.h
)

target_link_libraries(MMG SDL2 opengl32 glew32)

add_executable(game
	src/game/main.cpp
)

target_link_libraries(game MMG)