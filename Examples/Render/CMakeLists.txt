cmake_minimum_required(VERSION 3.5)

project (RenderExample)

LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/Core)
LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/Low-Level-Rendering)
LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/HID)
LINK_DIRECTORIES(${SDL2_LIB_DIR})

add_executable (RenderExample main.cpp
							  InputCommands/ExitCommand.cpp)
TARGET_LINK_LIBRARIES(RenderExample EngineCore EngineRenderSystem EngineInputSystem SDL2 SDL2main)