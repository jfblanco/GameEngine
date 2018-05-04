#ifndef __ENGINE__HID__GUI_GUISYSTEM__
#define __ENGINE__HID__GUI_GUISYSTEM__

	#include "../../Core/interfaces/FrontEnd.h"
	#include "../../Core/utils/Matrix4x4.h"
	#include "../../Core/utils/Vector3.h"
	#include "../../Low-Level-Rendering/utils/Camera.h"
	#include "../../Core/interfaces/Input.h"	
	#define NK_PRIVATE
	#define NK_INCLUDE_FIXED_TYPES
	#define NK_INCLUDE_STANDARD_IO
	#define NK_INCLUDE_DEFAULT_ALLOCATOR
	#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
	#define NK_INCLUDE_FONT_BAKING
	#define NK_INCLUDE_DEFAULT_FONT
	#define NK_IMPLEMENTATION
	#define NK_SDL_GL3_IMPLEMENTATION
	#define INCLUDE_OVERVIEW
	#include "nuklear.h"
	#include "GUIEvent.h"

	class SDL_Window;
	class SDLInputSystem;
	class SDLRenderSystem;
	class GuiConfig;
	class MouseManager;

    class GUISystem : public FrontEndInterface {
    	friend class MouseManager;
    	
        private:
        	GUIEvent events[1000];
        	unsigned int eventsCount;
            void initShader();
            struct nk_context* ctx;
            struct nk_font_atlas *atlas;
            struct nk_buffer cmds;
            struct nk_convert_config config;
            struct nk_draw_null_texture nullTexture;
            struct nk_colorf bg;
            
            Matrix4x4 projectionMatrix;
            Camera camera;
            SDLRenderSystem* sdlRenderSystem;
            SDLInputSystem* inputSystem;
            GuiConfig* guiConfig;
            MouseManager* mouseManager;
            unsigned int mouseX, mouseY;
            const struct nk_command* cmd;

        public:
            GUISystem(SDLInputSystem*, SDLRenderSystem*, GuiConfig*);
            ~GUISystem();
            
            void init(SDL_Window*);
            void draw();
    };

	class MouseManager : public MouseInputCommand {
		private:
			GUISystem* guiSystem;
		public:
			void addGuiSystem(GUISystem*);
			void leftClick();
			void rightClick();
			void leftUp();
			void rightUp();
			void middleClick();
			void mouseMove(unsigned int, unsigned int);
			void wheelMove(unsigned int);
	};
#endif