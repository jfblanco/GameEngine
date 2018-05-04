cmake_minimum_required(VERSION 3.5)

project (FactoryExample)

configure_file(shader_file_path.h.in shader_file_path.h)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable (FactoryExample main.cpp
								InputCommands/TickEvent.cpp
								InputCommands/ExitCommand.cpp)

TARGET_LINK_LIBRARIES(FactoryExample EngineCore EngineRenderSystem EngineInputSystem SDL2 SDL2main SDL2_image SDL2_ttf GLEW)

set(SHADER_DESTIATION_DIR ${PROJECT_SOURCE_DIR}/shaders)

add_custom_command(TARGET FactoryExample PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory ${SHADER_DESTIATION_DIR} $<TARGET_FILE_DIR:FactoryExample>/shaders)