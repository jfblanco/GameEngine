#include <iostream>
#include "../../GameEngine.h"
#include <shader_file_path.h>

int main(int argc, char** args){
	SDLRenderSystem* renderSystem = new SDLRenderSystem();
	SDLInputSystem* inputSystem = new SDLInputSystem();
	ShaderFactory* shaderFactory = new ShaderFactory();
	GUISystem* guiSystem = new GUISystem();

	renderSystem->init();
	renderSystem->createWindow("GuiSystem Example", 800, 600,32, false, true, false, false);

	inputSystem->init();
	inputSystem->addShutDownCommand(new ExitCommand());

	guiSystem->init(renderSystem->getWindow());

	Core* core = Core::getInstance();
	core->setRender(renderSystem);
	core->setInput(inputSystem);
	core->setFrontEnd(guiSystem);

	Scene* firstScene = new Scene();
	renderSystem->setActualScene(firstScene);
	core->begin();
}