#include "SDLRenderSystem.h"
#include "utils/Scene.h"
#include "../Core/interfaces/Render.h"
#include "../Core/utils/LongString.h"
#include "../Core/utils/String.h"
#include "../Debugging/ConsoleOutput.h"
#include <SDL.h>
#include <glew.h>
#include <iostream>

SDLRenderSystem::SDLRenderSystem():Render(){

}

SDLRenderSystem::~SDLRenderSystem(){
    SDL_DestroyWindow(this->window);
}

void SDLRenderSystem::init(){
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        LongString message;
        message = message + "Unable to initialize SDL: " + SDL_GetError();
        ConsoleOutput::getInstance()->error(&message);
    }
}

void SDLRenderSystem::cleanScene(){
    glClearColor(0.3, 0.3, 0.3, 0.0);
    glClearDepth(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void SDLRenderSystem::renderScene(){
	this->actualScene->renderScene();
}

void SDLRenderSystem::swapBuffers(){
    SDL_GL_SwapWindow(this->window);
}

SDL_Window* SDLRenderSystem::getWindow(){
    return window;
}

void SDLRenderSystem::sendTickEvent(unsigned int _tick){
    this->actualScene->sendTickEvent(_tick);    
}

void SDLRenderSystem::setActualScene(Scene* _scene){
    this->actualScene = _scene;
}

void SDLRenderSystem::setOpenGLAttributes(){
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,    8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,  8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,   8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,  8); 
    
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 8); 
    
    SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,   8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,  8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE, 8); 
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1); 
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 2); 
}

void SDLRenderSystem::printVendorInfo(){
    SDL_GetCurrentDisplayMode(0, &(this->mode));
    String infoScreen;
    String infoVendor;
    String infoRender;
    String infoVersion;
    infoScreen = infoScreen +   "|| Screen BPP:            " + SDL_BITSPERPIXEL(mode.format);
    infoVendor = infoVendor +   "|| Vendor:                " + (const char*) glGetString(GL_VENDOR);
    infoRender = infoRender +   "|| Renderer:              " + (const char*) glGetString(GL_RENDERER);
    infoVersion = infoVersion + "|| Version:               " + (const char*) glGetString(GL_VERSION);
    ConsoleOutput::getInstance()->info("-----------------------------------------------------");
    ConsoleOutput::getInstance()->info(&infoScreen);
    ConsoleOutput::getInstance()->info(&infoVendor);
    ConsoleOutput::getInstance()->info(&infoRender);
    ConsoleOutput::getInstance()->info(&infoVersion);
    ConsoleOutput::getInstance()->info("-----------------------------------------------------");
}

void SDLRenderSystem::createWindow(const char* windowName, int hight, int width, int colorBuffer, int fullScreen, int openGL, int borderless, int highDpi){
	int flags = 0;
	if(fullScreen)
		flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;

	if(openGL)
		flags |= SDL_WINDOW_OPENGL;

	if(borderless)
		flags |= SDL_WINDOW_BORDERLESS;

	if(highDpi)
		flags |= SDL_WINDOW_ALLOW_HIGHDPI;

    this->setOpenGLAttributes();  
	this->window = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, hight, width, flags);
    if (window == NULL) {
        LongString message;
        message = message + "Could not create window: " + SDL_GetError();
        ConsoleOutput::getInstance()->error(&message);
        exit(0);
    }  

    mainContext = SDL_GL_CreateContext(window);
    if (mainContext == NULL) {
        LongString message;
        message = message + "Could not create window: " + SDL_GetError();
        ConsoleOutput::getInstance()->error(&message);
        exit(0);
    }
    if (SDL_GL_MakeCurrent(window, mainContext) < 0) {
        LongString message;
        message = message + "OpenGL context could not be made current! SDL Error: " + SDL_GetError();
        ConsoleOutput::getInstance()->error(&message);
        exit(0);
    }

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL); 
    
    glewExperimental = GL_TRUE;
    const GLenum initCode = glewInit();
    if (initCode != GLEW_OK){
        LongString message;
        message = message + "Unable to initialize Glew: " + (const char*) glewGetErrorString(initCode);
        ConsoleOutput::getInstance()->error(&message);
        exit(0);
    }
    this->printVendorInfo();
}