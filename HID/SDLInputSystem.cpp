#include "SDLInputSystem.h"
#include "../Core/interfaces/Input.h"
#include <SDL.h>
#include <glew.h>
#include <iostream>

SDLInputSystem::SDLInputSystem():Input(){
    shutDownFunction = new InputFunction();
}

SDLInputSystem::~SDLInputSystem(){

}

void SDLInputSystem::init(){

}

void SDLInputSystem::addFunction(int, InputFunction*){

}

void SDLInputSystem::checkInput(){
    SDL_PollEvent(&(this->event));
    if(this->event.type == SDL_QUIT)
        shutDownFunction->excecute();
    if(this->event.type == SDL_KEYDOWN || this->event.type == SDL_KEYUP)
    	std::cout << SDL_KEYDOWN << std::endl;
    if(this->event.type == SDL_MOUSEBUTTONDOWN || this->event.type == SDL_MOUSEBUTTONUP)
    	std::cout << SDL_MOUSEBUTTONDOWN << std::endl;
    if((this->event.type & 0x100) == 0x600)
    	std::cout << "Joystick Event" << std::endl;
    if((this->event.type & 0x100) == 0x650)
    	std::cout << "Game controller Event" << std::endl;
}

void SDLInputSystem::addShutDownCommand(InputFunction* _shutDownFunction){
    this->shutDownFunction = _shutDownFunction;
}