cmake_minimum_required(VERSION 3.5)

project (EngineInputSystem)

set(INPUT_SOURCES SDLInputSystem.cpp GUI/GUISystem.cpp GUI/Window.cpp utils/ExitCommand.cpp)

add_library (EngineInputSystem SHARED ${INPUT_SOURCES})
TARGET_LINK_LIBRARIES(EngineInputSystem EngineCore)
TARGET_INCLUDE_DIRECTORIES(EngineInputSystem PUBLIC ${SDL2_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR})