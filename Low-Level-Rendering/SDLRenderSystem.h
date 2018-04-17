#ifndef __ENGINE__SDL_RENDER_SYSTEM_
#define __ENGINE__SDL_RENDER_SYSTEM_

	#include "../Core/interfaces/Render.h"
	#include <SDL.h>

	class Scene;

	class SDLRenderSystem : public Render {
	
	private:	
		SDL_Window* window;
		SDL_GLContext mainContext;
    	SDL_DisplayMode mode;

		Scene* actualScene;	
		void setOpenGLAttributes();
	public:
		SDLRenderSystem();
		~SDLRenderSystem();

		void setActualScene(Scene*);
		void init();
		void cleanScene();
		void renderScene();
		void swapBuffers();
		void printVendorInfo();
		SDL_Window* getWindow();
		void sendTickEvent(unsigned int);
		virtual void createWindow(const char*,int,int,int,int,int,int,int);
	};

#endif