cmake_minimum_required(VERSION 3.5)

project (EngineCore)

add_library (EngineCore SHARED Core.cpp 
							   interfaces/Animation.cpp
							   interfaces/Audio.cpp
							   interfaces/ArtificialInteligense.cpp
							   interfaces/Debug.cpp
							   interfaces/FrontEnd.cpp
							   interfaces/GamePlay.cpp
							   interfaces/Input.cpp
							   interfaces/NetWork.cpp
							   interfaces/Physics.cpp
							   interfaces/Render.cpp
							   interfaces/Resources.cpp
							   interfaces/VisualEfects.cpp
							   interfaces/GuiRenderCommand.cpp
							   events/TickEventInterface.cpp
							   utils/Vector2.cpp
							   utils/Vector3.cpp
							   utils/Vector4.cpp
							   utils/String.cpp
							   utils/Matrix3x3.cpp
							   utils/Matrix4x4.cpp
							   utils/ShortString.cpp
							   utils/String.cpp
							   utils/Buffer.cpp
							   utils/LongString.cpp)
TARGET_INCLUDE_DIRECTORIES(EngineCore PUBLIC ${SDL2_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(EngineCore SDL2 SDL2main)							   