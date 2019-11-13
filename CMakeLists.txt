cmake_minimum_required(VERSION 2.6)

project(MMG)

include_directories(
	contrib/include
	src/MMG
)

link_directories(
	${CMAKE_SOURCE_DIR}/contrib/lib
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

add_custom_command(TARGET game
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
		"${PROJECT_SOURCE_DIR}/contrib/lib/SDL2.dll"
		$<TARGET_FILE_DIR:game>
	COMMAND ${CMAKE_COMMAND} -E copy
		"${PROJECT_SOURCE_DIR}/contrib/lib/glew32.dll"
		$<TARGET_FILE_DIR:game>
)
