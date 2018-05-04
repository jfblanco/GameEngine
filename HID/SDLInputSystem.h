#ifndef __ENGINE__SDL_INPUT_SYSTEM_
#define __ENGINE__SDL_INPUT_SYSTEM_
	
	#include <SDL.h>
	#include "../Core/interfaces/Input.h"	

	class SDLInputSystem : public Input {
	
	private:	
		SDL_Event event;
		KeyBoardInputCommand* keyboardCommands;
		ShutDownInputCommand* shutDownFunction;
		MouseInputCommand* mouseMotionFunction;
		JoyStickInputCommand* joyStickFunction;
		ControllerInputCommand* controllerFunction;

	public:
		SDLInputSystem();
		~SDLInputSystem();

		void init();
		void checkInput();
		SDL_Event* getSDLEvent();

		void addShutDownCommand(ShutDownInputCommand*);
		void addMouseMotionCommand(MouseInputCommand*);
		void addKeyBoardCommand(KeyBoardInputCommand*);
		void addJoyStickCommand(JoyStickInputCommand*);
		void addControllerCommand(ControllerInputCommand*);
	};

#endif