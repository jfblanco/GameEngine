cmake_minimum_required(VERSION 3.5)

project (RenderExample)

configure_file(shader_file_path.h.in shader_file_path.h)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable (RenderExample main.cpp
							  InputCommands/ExitCommand.cpp
							  InputCommands/PrintCommand.cpp)
TARGET_LINK_LIBRARIES(RenderExample EngineCore EngineRenderSystem EngineInputSystem SDL2 SDL2main GLEW)

set(SHADER_DESTIATION_DIR ${PROJECT_SOURCE_DIR}/shaders)

add_custom_command(TARGET RenderExample PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory ${SHADER_DESTIATION_DIR} $<TARGET_FILE_DIR:RenderExample>/shaders)