#ifndef __ENGINE__RENDER_
#define __ENGINE__RENDER_

	class Render {	

	public:
		Render();
		~Render();

		virtual void init();
		virtual void renderScene();
		virtual void createWindow();		
	};

#endif