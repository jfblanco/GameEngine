#include <iostream>
#include <iomanip> 
#include <bitset>
#include "../../Core/Core.h"
#include "../../Low-Level-Rendering/SDLRenderSystem.h"
#include "../../HID/SDLInputSystem.h"
#include "InputCommands/ExitCommand.h"
#include "InputCommands/PrintCommand.h"

int main(int argc, char** args){
	SDLRenderSystem* renderSystem = new SDLRenderSystem();
	SDLInputSystem* inputSystem = new SDLInputSystem();

	renderSystem->init();
	renderSystem->createWindow("Render Example", 800, 600,32, false, true, false, false);

	inputSystem->init();
	inputSystem->addShutDownCommand(new ExitCommand());
	inputSystem->addFunction(SDLK_a, new PrintCommand());

	Core* core = Core::getInstance();
	core->setRender(renderSystem);
	core->setInput(inputSystem);

	core->begin();
}