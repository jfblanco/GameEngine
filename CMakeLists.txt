set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

cmake_minimum_required(VERSION 3.5)

option(ENGINE_BUILD_EXAMPLES "Build examples?" OFF)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(GLEW REQUIRED)
find_package(LibRocket REQUIRED)

add_subdirectory("${PROJECT_SOURCE_DIR}/Core")
add_subdirectory("${PROJECT_SOURCE_DIR}/Low-Level-Rendering")
if(ENGINE_BUILD_EXAMPLES)
	add_subdirectory("${PROJECT_SOURCE_DIR}/Examples")
endif()