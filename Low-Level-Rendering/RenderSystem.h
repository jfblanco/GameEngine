#ifndef __ENGINE__RENDER_SYSTEM_
#define __ENGINE__RENDER_SYSTEM_

	#include "../Core/interfaces/Render.h"

	class RenderSystem : public Render {
	
	private:	

	public:
		RenderSystem();
		~RenderSystem();

		void init();
		void renderScene();
		void createWindow();
	};

#endif