cmake_minimum_required(VERSION 3.5)

project (RenderExample)

add_executable (RenderExample main.cpp
							  InputCommands/ExitCommand.cpp
							  InputCommands/PrintCommand.cpp)
TARGET_LINK_LIBRARIES(RenderExample EngineCore EngineRenderSystem EngineInputSystem SDL2 SDL2main GLEW)