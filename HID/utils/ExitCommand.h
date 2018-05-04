#ifndef __RENDER_EXAMPLE_EXIT_COMMAND_
#define __RENDER_EXAMPLE_EXIT_COMMAND_

	#include "../../Core/interfaces/Input.h"	

	class ExitCommand : public ShutDownInputCommand {
	
	public:
		void shutDownEvent();
	};

#endif