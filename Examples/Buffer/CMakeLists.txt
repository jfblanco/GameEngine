cmake_minimum_required(VERSION 3.5)

project (BufferExample)

add_executable (BufferExample main.cpp)
TARGET_LINK_LIBRARIES(BufferExample EngineCore EngineRenderSystem EngineInputSystem SDL2 SDL2main GLEW)