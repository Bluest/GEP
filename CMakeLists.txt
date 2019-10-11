cmake_minimum_required(VERSION 2.6)
project(MMG)

add_library(MMG
	src/MMG/Application.cpp
	src/MMG/Application.h
)

target_link_libraries(MMG SDL2 opengl32 glew32)

add_executable(game
	src/game/main.cpp
)

target_link_libraries(game MMG)