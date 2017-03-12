cmake_minimum_required(VERSION 3.5)

project (RenderExample)

LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/Core)
LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/Low-Level-Rendering)

add_executable (RenderExample main.cpp)
TARGET_LINK_LIBRARIES(RenderExample EngineCore EngineRenderSystem)