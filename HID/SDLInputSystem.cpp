#include "SDLInputSystem.h"
#include "../Core/interfaces/Input.h"
#include <SDL.h>
#include <glew.h>
#include <iostream>
#include <cstddef>

SDLInputSystem::SDLInputSystem():Input(){
    this->shutDownFunction = new ShutDownInputNullCommand();
    this->mouseMotionFunction = new MouseInputNullCommand();
    this->keyboardCommands = new KeyBoardInputNullCommand();
}

SDLInputSystem::~SDLInputSystem(){

}

void SDLInputSystem::init(){

}

void SDLInputSystem::checkInput(){
    while(SDL_PollEvent(&(this->event))){
        if(this->event.type == SDL_QUIT)
            this->shutDownFunction->shutDownEvent();
        if(this->event.type == SDL_KEYDOWN){
        	this->keyboardCommands->keyDown(this->event.key.keysym.sym);
        }
        if(this->event.type == SDL_MOUSEMOTION)
            this->mouseMotionFunction->mouseMove(this->event.motion.x, this->event.motion.y);
        if(this->event.type == SDL_MOUSEBUTTONDOWN && this->event.button.button == SDL_BUTTON_LEFT)
            this->mouseMotionFunction->leftClick();
        if(this->event.type == SDL_MOUSEBUTTONDOWN && this->event.button.button == SDL_BUTTON_RIGHT)
            this->mouseMotionFunction->rightClick();
        if(this->event.type == SDL_MOUSEBUTTONUP && this->event.button.button == SDL_BUTTON_LEFT)
            this->mouseMotionFunction->leftUp();
        if(this->event.type == SDL_MOUSEBUTTONUP && this->event.button.button == SDL_BUTTON_RIGHT)
            this->mouseMotionFunction->rightUp();
    }
}

SDL_Event* SDLInputSystem::getSDLEvent() {
    return &this->event;
}

void SDLInputSystem::addShutDownCommand(ShutDownInputCommand* _shutDownFunction){
    this->shutDownFunction = _shutDownFunction;
}

void SDLInputSystem::addMouseMotionCommand(MouseInputCommand* _mouseMotionFunction){
    this->mouseMotionFunction = _mouseMotionFunction;
}

void SDLInputSystem::addKeyBoardCommand(KeyBoardInputCommand* _keyboardCommands){
    this->keyboardCommands = _keyboardCommands;
}

void SDLInputSystem::addJoyStickCommand(JoyStickInputCommand*){

}

void SDLInputSystem::addControllerCommand(ControllerInputCommand*) {

}