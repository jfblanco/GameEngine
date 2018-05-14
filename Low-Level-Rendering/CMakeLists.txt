cmake_minimum_required(VERSION 3.5)

project (EngineRenderSystem)

add_library (EngineRenderSystem SHARED SDLRenderSystem.cpp 
									   ShaderFactory.cpp
									   renderingPipe/ShaderStrategy.cpp
									   renderingPipe/renderingStrategies/SimpleShader.cpp
									   utils/MeshFactory.cpp
									   utils/Mesh.cpp
									   utils/Camera.cpp
									   utils/Scene.cpp)
TARGET_LINK_LIBRARIES(EngineRenderSystem EngineCore EngineDebugging)
TARGET_INCLUDE_DIRECTORIES(EngineRenderSystem PUBLIC ${SDL2_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR})