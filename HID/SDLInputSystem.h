#ifndef __ENGINE__SDL_INPUT_SYSTEM_
#define __ENGINE__SDL_INPUT_SYSTEM_

	#include "../Core/interfaces/Input.h"
	#include <SDL.h>
	

	class SDLInputSystem : public Input {
	
	private:	
		SDL_Event event;
		InputFunction* shutDownFunction;

	public:
		SDLInputSystem();
		~SDLInputSystem();

		void init();
		void addFunction(int, InputFunction*);
		void checkInput();

		void addShutDownCommand(InputFunction*);
	};

#endif