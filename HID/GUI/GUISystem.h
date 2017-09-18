#ifndef __ENGINE__HID__GUI_GUISYSTEM__
#define __ENGINE__HID__GUI_GUISYSTEM__

	#include "../../Core/interfaces/FrontEnd.h"
	#include "../../Core/utils/Matrix4x4.h"
	#include "../../Core/interfaces/GuiRenderCommand.h"
	#define NK_PRIVATE
	#define NK_INCLUDE_FIXED_TYPES
	#define NK_INCLUDE_STANDARD_IO
	#define NK_INCLUDE_DEFAULT_ALLOCATOR
	#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
	#define NK_INCLUDE_FONT_BAKING
	#define NK_INCLUDE_DEFAULT_FONT
	#define NK_IMPLEMENTATION
	#include "nuklear.h"

	class SDL_Window;
	class GuiRenderCommand;

    class GUISystem : public FrontEndInterface{
        private:
        	GuiRenderCommand* renderCommand[19];
            void initShader();
			void loadFont();
			void createOpenGLRender();
			void createOpenGLRender(const void *,int,int);
            struct nk_context ctx;
            struct nk_font_atlas atlas;
            struct nk_buffer cmds;
            struct nk_convert_config config;
            struct nk_draw_null_texture nullTexture;
            Matrix4x4 projectionMatrix;
            unsigned int prog, vert_shdr, frag_shdr,uniform_tex, uniform_proj, attrib_pos, attrib_uv, attrib_col, vao, ebo, vbo, font_tex;

        public:
            GUISystem();
            ~GUISystem();
            const struct nk_command* cmd;
            
            void init(SDL_Window*);
            void draw();
    };

    class NopCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
	};

	class ScissorCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
	};

	class LineCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
	};

	class CurveCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
	};

	class RectCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
	};

	class RectFilledCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
	};

	class RectMultiColorCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
	};

    class CirleCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
	};

	class CircleFilledCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
	};

	class ArcCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
	};

	class ArcFilledCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
	};

	class TriangleCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
	};

	class TriangleFilledCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
	};

	class PolygonCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
	};

	class PolygonFilledCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
	};

	class PolylineCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
	};

	class TextCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
	};

	class ImageCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
	};

	class CustomCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
	};

#endif