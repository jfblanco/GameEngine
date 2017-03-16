#include "SDLInputSystem.h"
#include "../Core/interfaces/Input.h"
#include <SDL.h>
#include <glew.h>
#include <iostream>
#include <cstddef>

SDLInputSystem::SDLInputSystem():Input(){
    shutDownFunction = new InputFunction();
}

SDLInputSystem::~SDLInputSystem(){

}

void SDLInputSystem::init(){

}

void SDLInputSystem::addFunction(int _key, InputFunction* _command){
	int scancode = SDL_GetScancodeFromKey(_key);
	this->keyboardCommands[scancode] = _command;
}

void SDLInputSystem::checkInput(){
    SDL_PollEvent(&(this->event));
    if(this->event.type == SDL_QUIT)
        shutDownFunction->excecute();
    if(this->event.type == SDL_KEYDOWN)
    	this->keyboardInput();
}

void SDLInputSystem::addShutDownCommand(InputFunction* _shutDownFunction){
    this->shutDownFunction = _shutDownFunction;
}

void SDLInputSystem::keyboardInput(){
	if(this->keyboardCommands[this->event.key.keysym.scancode] != NULL){
		(this->keyboardCommands[this->event.key.keysym.scancode])->excecute();
	}
}