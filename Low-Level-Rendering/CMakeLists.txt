cmake_minimum_required(VERSION 3.5)

project (EngineRenderSystem)

add_library (EngineRenderSystem SHARED RenderSystem.cpp)
TARGET_LINK_LIBRARIES(EngineRenderSystem EngineCore)
TARGET_INCLUDE_DIRECTORIES(EngineRenderSystem PUBLIC ${SDL2_INCLUDE_DIR} ${GLEW_INCLUDE_DIR})