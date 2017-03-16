#ifndef __ENGINE__SDL_RENDER_SYSTEM_
#define __ENGINE__SDL_RENDER_SYSTEM_

	#include "../Core/interfaces/Render.h"
	#include <SDL.h>

	class SDLRenderSystem : public Render {
	
	private:	
		SDL_Window* window;
		SDL_GLContext mainContext;

		void setOpenGLAttributes();
	public:
		SDLRenderSystem();
		~SDLRenderSystem();

		void init();
		void renderScene();
		virtual void createWindow(const char*,int,int,int,int,int,int,int);
	};

#endif