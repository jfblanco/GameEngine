cmake_minimum_required(VERSION 3.5)

project (StringExample)

LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/Core)

add_executable (StringExample main.cpp)
TARGET_LINK_LIBRARIES(StringExample EngineCore EngineDebugging)