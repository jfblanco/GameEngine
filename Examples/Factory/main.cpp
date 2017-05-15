#include <iostream>
#include <iomanip> 
#include <bitset>
#include "../../Core/Core.h"
#include "../../Core/utils/String.h"
#include "../../Low-Level-Rendering/utils/Shader.h"
#include "../../Low-Level-Rendering/utils/Mesh.h"
#include "../../Low-Level-Rendering/utils/Scene.h"
#include "../../Low-Level-Rendering/SDLRenderSystem.h"
#include "../../Low-Level-Rendering/ShaderFactory.h"
#include "../../Low-Level-Rendering/utils/MeshFactory.h"
#include "../../Low-Level-Rendering/renderingPipe/renderingStrategies/SimpleShader.h"
#include "InputCommands/ExitCommand.h"
#include "../../HID/SDLInputSystem.h"
#include <shader_file_path.h>

int main(int argc, char** args){
	SDLRenderSystem* renderSystem = new SDLRenderSystem();
	SDLInputSystem* inputSystem = new SDLInputSystem();
	ShaderFactory* shaderFactory = new ShaderFactory();
	MeshFactory* meshFactory = new MeshFactory();

	renderSystem->init();
	renderSystem->createWindow("Factory Example", 800, 600,32, false, true, false, false);

	inputSystem->init();
	inputSystem->addShutDownCommand(new ExitCommand());

	Core* core = Core::getInstance();
	core->setRender(renderSystem);
	core->setInput(inputSystem);

	Shader* shader = new Shader();
	shader->tag = "simpleShader";
	shaderFactory->createShader(SIMPLE_TEST_VERTEX_SHADER,SIMPLE_TEST_FRAGMENT_SHADER, shader);
	ShaderStrategy* shaderStrategy = new SimpleShader(shader);

	Scene* firstScene = new Scene();
	firstScene->addShader(shader, shaderStrategy);
	
	Mesh* plane = meshFactory->createPlane("plane1");
	plane->position.translationMatrix(600.0, 400.0, 0.0);
	Mesh* cube = meshFactory->createCube("cube2");	
	cube->position.translationMatrix(100.0, 200.0,0.0);
	firstScene->addMesh(plane);	
	firstScene->addMesh(cube);	
	renderSystem->setActualScene(firstScene);

	core->begin();
}