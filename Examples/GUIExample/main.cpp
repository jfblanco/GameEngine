#include <iostream>
#include "../../GameEngine.h"
#include "../../HID/utils/GuiConfig.h"
#include <shader_file_path.h>

int main(int argc, char** args){
	SDLRenderSystem* renderSystem = new SDLRenderSystem();
	SDLInputSystem* inputSystem = new SDLInputSystem();
	ShaderFactory* shaderFactory = new ShaderFactory();

	GuiConfig* guiConfig = new GuiConfig();

	guiConfig->GUI_RECTANGLE_FRAGMENT_SHADER = GUI_RECTANGLE_FRAGMENT_SHADER;
	guiConfig->GUI_RECTANGLE_VERTEX_SHADER = GUI_RECTANGLE_VERTEX_SHADER;
	guiConfig->GUI_CIRCLE_VERTEX_SHADER = GUI_CIRCLE_VERTEX_SHADER;
	guiConfig->GUI_CIRCLE_FRAGMENT_SHADER = GUI_CIRCLE_FRAGMENT_SHADER;
	guiConfig->GUI_CIRCLE_ASSET_IMAGE = GUI_CIRCLE_ASSET_IMAGE;
	guiConfig->GUI_FONT_ASSET = GUI_FONT_ASSET;
	GUISystem* guiSystem = new GUISystem(inputSystem, renderSystem, guiConfig);

	renderSystem->init();
	renderSystem->createWindow("GuiSystem sdfsdfsdf", 960, 720,32, false, true, false, false);

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
