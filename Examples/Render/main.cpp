#include <iostream>
#include <iomanip> 
#include <bitset>
#include "../../Core/Core.h"
#include "../../Core/utils/String.h"
#include "../../Core/utils/Shader.h"
#include "../../Low-Level-Rendering/SDLRenderSystem.h"
#include "../../Low-Level-Rendering/ShaderFactory.h"
#include "../../HID/SDLInputSystem.h"
#include "InputCommands/ExitCommand.h"
#include "InputCommands/PrintCommand.h"
#include <shader_file_path.h>

int main(int argc, char** args){
	SDLRenderSystem* renderSystem = new SDLRenderSystem();
	SDLInputSystem* inputSystem = new SDLInputSystem();
	ShaderFactory* shaderFactory = new ShaderFactory();
	Shader shader;

	renderSystem->init();
	renderSystem->createWindow("Render Example", 800, 600,32, false, true, false, false);

	inputSystem->init();
	inputSystem->addShutDownCommand(new ExitCommand());
	inputSystem->addFunction(SDLK_a, new PrintCommand());

	shaderFactory->createShader(SIMPLE_TEST_VERTEX_SHADER,SIMPLE_TEST_FRAGMENT_SHADER, &shader);
	
	Core* core = Core::getInstance();
	core->setRender(renderSystem);
	core->setInput(inputSystem);

	core->begin();
}