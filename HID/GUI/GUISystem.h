#ifndef __ENGINE__HID__GUI_GUISYSTEM__
#define __ENGINE__HID__GUI_GUISYSTEM__

	#include "../../Core/interfaces/FrontEnd.h"
	#include "../../Core/utils/Matrix4x4.h"
	#include "../../Core/utils/Vector3.h"
	#include "../../Core/interfaces/GuiRenderCommand.h"
	#include "../../Low-Level-Rendering/utils/Camera.h"
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
    	friend class NopCommand;
    	friend class ScissorCommand;
    	friend class LineCommand;
    	friend class CirleCommand;
    	friend class CircleFilledCommand;
    	friend class RectCommand;
    	friend class RectFilledCommand;
    	
        private:
        	GuiRenderCommand* renderCommand[19];
        	Vector3 colors[19];
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
            Camera camera;
            unsigned int progRectangle, progCircle, font_tex;
            unsigned int uniform_rectangle_proj, attrib_rectangle_pos, attrib_rectangle_col;
            unsigned int uniform_circle_proj, attrib_circle_pos, attrib_circle_col, element_position;

        public:
            GUISystem();
            ~GUISystem();
            const struct nk_command* cmd;
            
            void init(SDL_Window*);
            void draw();
            void createDrawableObject();
            unsigned int getAttribPos();
            unsigned int getUniformProj();
            unsigned int getUniformView();
            unsigned int getAttribCol();
    };

    class NopCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
			void setOpenGLBuffers(GUISystem*);
	};

	class ScissorCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
			void setOpenGLBuffers(GUISystem*);
	};

	class LineCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
			void setOpenGLBuffers(GUISystem*);
	};

	class CurveCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
			void setOpenGLBuffers(GUISystem*);
	};

	class RectCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
			void setOpenGLBuffers(GUISystem*);
	};

	class RectFilledCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
			void setOpenGLBuffers(GUISystem*);
	};

	class RectMultiColorCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
			void setOpenGLBuffers(GUISystem*);
	};

    class CirleCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
			void setOpenGLBuffers(GUISystem*);
	};

	class CircleFilledCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
			void setOpenGLBuffers(GUISystem*);
	};

	class ArcCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
			void setOpenGLBuffers(GUISystem*);
	};

	class ArcFilledCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
			void setOpenGLBuffers(GUISystem*);
	};

	class TriangleCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
			void setOpenGLBuffers(GUISystem*);
	};

	class TriangleFilledCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
			void setOpenGLBuffers(GUISystem*);
	};

	class PolygonCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
			void setOpenGLBuffers(GUISystem*);
	};

	class PolygonFilledCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
			void setOpenGLBuffers(GUISystem*);
	};

	class PolylineCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
			void setOpenGLBuffers(GUISystem*);
	};

	class TextCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
			void setOpenGLBuffers(GUISystem*);
	};

	class ImageCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
			void setOpenGLBuffers(GUISystem*);
	};

	class CustomCommand : public GuiRenderCommand{
		public:
			void excecute(GUISystem*);
			void setOpenGLBuffers(GUISystem*);
	};

#endif