#ifndef __ENGINE__SDL_RENDER_SYSTEM_
#define __ENGINE__SDL_RENDER_SYSTEM_

	#include "../Core/interfaces/Render.h"

	class SDL_Window;

	class SDLRenderSystem : public Render {
	
	private:	
		SDL_Window* window;
	public:
		SDLRenderSystem();
		~SDLRenderSystem();

		void init();
		void renderScene();
		virtual void createWindow(const char*,int,int,int,int,int,int,int);
	};

#endif