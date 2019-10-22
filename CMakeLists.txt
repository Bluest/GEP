cmake_minimum_required(VERSION 2.6)
project(MMG)

include_directories(
	src
)

add_library(MMG
	src/MMG/MMG.h
	src/MMG/Application.h
	src/MMG/Application.cpp
	src/MMG/Entity.h
	src/MMG/Entity.cpp
	src/MMG/Component.h
	src/MMG/Component.cpp
)

target_link_libraries(MMG SDL2 opengl32 glew32)

add_executable(game
	src/game/main.cpp
)

target_link_libraries(game MMG)