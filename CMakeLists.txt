cmake_minimum_required(VERSION 2.6)

project(MMG)

include_directories(
	contrib/include
	src/MMG
	src/rend
)

link_directories(
	${CMAKE_SOURCE_DIR}/contrib/lib
)

add_definitions(-DSTD_SR1_DEBUG)

add_library(rend
	src/rend/Exception.cpp
	src/rend/Context.cpp
	src/rend/Texture.cpp
	src/rend/RenderTexture.cpp
	src/rend/Shader.cpp
	src/rend/Buffer.cpp
	src/rend/Mesh.cpp
	src/rend/Util.cpp
)
target_link_libraries(rend opengl32 glew32)

add_library(MMG
	src/MMG/MMG.h
	src/MMG/Environment.h
	src/MMG/Environment.cpp
	src/MMG/Core.h
	src/MMG/Core.cpp
	src/MMG/Entity.h
	src/MMG/Entity.cpp
	src/MMG/Component.h
	src/MMG/Component.cpp
	src/MMG/MeshRenderer.h
	src/MMG/MeshRenderer.cpp
)
target_link_libraries(MMG rend SDL2 opengl32 glew32 OpenAL32)

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
	COMMAND ${CMAKE_COMMAND} -E copy
		"${PROJECT_SOURCE_DIR}/contrib/lib/OpenAL32.dll"
		$<TARGET_FILE_DIR:game>
)
