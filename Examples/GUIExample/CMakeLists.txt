cmake_minimum_required(VERSION 3.5)

project (GuiExample)

configure_file(shader_file_path.h.in shader_file_path.h)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable (GuiExample main.cpp)
TARGET_LINK_LIBRARIES(GuiExample EngineCore EngineRenderSystem EngineInputSystem SDL2 SDL2main SDL2_image SDL2_ttf GLEW)

set(SHADER_DESTIATION_DIR ${PROJECT_SOURCE_DIR}/../../HID/shaders)
set(ASSETS_DESTIATION_DIR ${PROJECT_SOURCE_DIR}/../../HID/assets)

add_custom_command(TARGET GuiExample PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory ${SHADER_DESTIATION_DIR} $<TARGET_FILE_DIR:GuiExample>/shaders)

add_custom_command(TARGET GuiExample PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory ${ASSETS_DESTIATION_DIR} $<TARGET_FILE_DIR:GuiExample>/assets)       