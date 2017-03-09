cmake_minimum_required(VERSION 3.5)

project (VectorExample)

LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/Core)

add_executable (VectorExample main.cpp)
TARGET_LINK_LIBRARIES(VectorExample EngineCore)