cmake_minimum_required(VERSION 3.5)

project (MatrixExample)

LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/Core)

add_executable (MatrixExample main.cpp)
TARGET_LINK_LIBRARIES(MatrixExample EngineCore)