cmake_minimum_required(VERSION 2.6)
project(GEP)

add_library(GEP
	src/GEP/dummy.cpp
)

target_link_libraries(GEP SDL2 opengl32 glew32)

add_executable(game
	src/game/main.cpp
)

target_link_libraries(game GEP)