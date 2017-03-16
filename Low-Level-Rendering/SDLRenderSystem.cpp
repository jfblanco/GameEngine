#include "SDLRenderSystem.h"
#include "../Core/interfaces/Render.h"
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
        std::cout << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
    }
}

void SDLRenderSystem::renderScene(){
	glClearColor(0.0, 0.0, 0.0, 1.0);
    glClearDepth(1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    

    SDL_GL_SwapWindow(this->window);
}

void SDLRenderSystem::setOpenGLAttributes(){
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,    8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,  8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,   8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,  8); 
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,  16);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32); 
    SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,   8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,  8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE, 8); 
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1); 
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 2);
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

	this->window = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, hight, width, flags);
    if (window == NULL) {
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
    }
    this->setOpenGLAttributes();    

    mainContext = SDL_GL_CreateContext(window);
    if (mainContext == NULL) {
        std::cout << "OpenGL context could not be created! SDL Error: " << SDL_GetError() << std::endl;
    }
    if (SDL_GL_MakeCurrent(window, mainContext) < 0) {
        std::cout << "OpenGL context could not be made current! SDL Error: " << SDL_GetError() << std::endl;
    }

    glewExperimental = GL_TRUE;
    const GLenum initCode = glewInit();
    if (initCode != GLEW_OK){
        std::cout << "Unable to initialize Glew: " << glewGetErrorString(initCode) << std::endl;   
    }
}