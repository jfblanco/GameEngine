cmake_minimum_required(VERSION 3.5)

project (EngineInputSystem)

add_library (EngineInputSystem SHARED SDLInputSystem.cpp)
TARGET_LINK_LIBRARIES(EngineInputSystem EngineCore)
TARGET_INCLUDE_DIRECTORIES(EngineInputSystem PUBLIC ${SDL2_INCLUDE_DIR} ${GLEW_INCLUDE_DIR})