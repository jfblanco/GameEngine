#include <iostream>
#include <iomanip> 
#include <bitset>
#include "../../Core/Core.h"
#include "../../Low-Level-Rendering/RenderSystem.h"

int main(int argc, char** args){
	RenderSystem* renderSystem = new RenderSystem();

	renderSystem->init();

	Core* core = Core::getInstance();
	core->setRender(renderSystem);

	core->begin();
}