#ifndef __RENDER_EXAMPLE_PRINT_COMMAND_
#define __RENDER_EXAMPLE_PRINT_COMMAND_

	#include "../../../Core/interfaces/Input.h"	

	class PrintCommand : public KeyBoardInputCommand {
	
	public:
		void keyDown(unsigned int);
		void keyUp(unsigned int);
	};

#endif