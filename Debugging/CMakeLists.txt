cmake_minimum_required(VERSION 3.5)

project (EngineDebugging)

add_library (EngineDebugging SHARED 
							   ConsoleOutput.cpp)

TARGET_INCLUDE_DIRECTORIES(EngineDebugging PUBLIC )
TARGET_LINK_LIBRARIES(EngineDebugging )