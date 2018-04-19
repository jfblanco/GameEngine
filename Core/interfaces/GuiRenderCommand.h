#ifndef __ENGINE__GUI__RENDER__GUICOMMAND__
#define __ENGINE__GUI__RENDER__GUICOMMAND__

	class GUISystem;

	class GuiRenderCommand {
		public:
			virtual void excecute(GUISystem*)=0;
			virtual void setOpenGLBuffers(GUISystem*)=0;
	};

#endif