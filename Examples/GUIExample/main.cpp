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

	Shader* shader = new Shader();
	shader->tag = "simpleShader"; 
	shaderFactory->createShader(SIMPLE_TEST_VERTEX_SHADER,SIMPLE_TEST_FRAGMENT_SHADER, shader);
	ShaderStrategy* shaderStrategy = new SimpleShader(shader);

	Scene* firstScene = new Scene();
	renderSystem->setActualScene(firstScene);

	core->begin();
}