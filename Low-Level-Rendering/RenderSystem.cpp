#include "RenderSystem.h"
#include "../Core/interfaces/Render.h"
#include <SDL.h>
#include <glew.h>
#include <iostream>

RenderSystem::RenderSystem():Render(){

}

RenderSystem::~RenderSystem(){

}

void RenderSystem::init(){
	std::cout << "init render system" << std::endl;
}

void RenderSystem::renderScene(){
	std::cout << "hola" << std::endl;
}

void RenderSystem::createWindow(){
	
}