#include "GUISystem.h"
#include <glew.h>
#include <string>
#include <SDL.h>
#include "../../Core/Core.h"
#include "../../Core/interfaces/Input.h"    
#include "../utils/GuiConfig.h"
#include "../SDLInputSystem.h"
#include "../../Low-Level-Rendering/utils/Shader.h"
#include "../../Low-Level-Rendering/ShaderFactory.h"
#include "../../Debugging/ConsoleOutput.h"
#include "nuklear_sdl_gl3.h"
#include "GUIEvent.h"

#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 720

#define MAX_VERTEX_MEMORY 512 * 1024
#define MAX_ELEMENT_MEMORY 128 * 1024

#define INT_MAX 600
#define INT_MIN 0

#ifdef INCLUDE_ALL
  #define INCLUDE_STYLE
  #define INCLUDE_CALCULATOR
  #define INCLUDE_NODE_EDITOR
#endif

#ifdef INCLUDE_STYLE
  #include "style.c"
#endif
#ifdef INCLUDE_CALCULATOR
  #include "calculator.c"
#endif
#ifdef INCLUDE_OVERVIEW
  #include "overview.c"
#endif
#ifdef INCLUDE_NODE_EDITOR
  #include "node_editor.c"
#endif     

GUISystem::GUISystem(SDLInputSystem* _inputSystem, SDLRenderSystem* _sdlRenderSystem, GuiConfig* _guiConfig){
    this->guiConfig = _guiConfig;
    this->inputSystem = _inputSystem;
    this->sdlRenderSystem = _sdlRenderSystem;
    this->eventsCount = 0;
}

GUISystem::~GUISystem(){

}

enum {EASY, HARD};

void GUISystem::init(SDL_Window* win){

    //this->projectionMatrix.perspectiveMatrix(45.0f, 800.0f/600.0f, 0.1f, 2.0f);
    this->projectionMatrix.orthoMatrix(0.0f, 960.0f, 0.0f, 720.0f, 0.0f, -1.0f);
    Vector3* position = new Vector3(0.0,0.0,-1.0);
    Vector3* point = new Vector3(0.0,0.0,0.0);
    Vector3* up = new Vector3(0.0,1.0,0.0);
    this->camera.lookAt(*position,*point,*up);
    delete position;
    delete point;
    delete up;

    ctx = nk_sdl_init(win);
    nk_sdl_font_stash_begin(&atlas);
    nk_sdl_font_stash_end();

    this->mouseManager = new MouseManager();
    this->mouseManager->addGuiSystem(this);
    this->inputSystem->addMouseMotionCommand(this->mouseManager);
}

void GUISystem::draw(){
   nk_input_begin(ctx);
        for(int i = 0; i <= eventsCount; i++){
            nk_sdl_handle_event(&(events[i]));
        }
        eventsCount = 0;
    nk_input_end(ctx);

    /* GUI */
    if (nk_begin(ctx, "Demo", nk_rect(50, 50, 230, 250),
        NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|
        NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE))
    {
        enum {EASY, HARD};
        static int op = EASY;
        static int property = 20;

        nk_layout_row_static(ctx, 30, 80, 1);
        if (nk_button_label(ctx, "button")){
            ConsoleOutput::getInstance()->info("clickeado!!!");
        }
        nk_layout_row_dynamic(ctx, 30, 2);
        if (nk_option_label(ctx, "easy", op == EASY)) op = EASY;
        if (nk_option_label(ctx, "hard", op == HARD)) op = HARD;
        nk_layout_row_dynamic(ctx, 22, 1);
        nk_property_int(ctx, "Compression:", 0, &property, 100, 10, 1);

        nk_layout_row_dynamic(ctx, 20, 1);
        nk_label(ctx, "background:", NK_TEXT_LEFT);
        nk_layout_row_dynamic(ctx, 25, 1);
        if (nk_combo_begin_color(ctx, nk_rgb_cf(bg), nk_vec2(nk_widget_width(ctx),400))) {
            nk_layout_row_dynamic(ctx, 120, 1);
            bg = nk_color_picker(ctx, bg, NK_RGBA);
            nk_layout_row_dynamic(ctx, 25, 1);
            bg.r = nk_propertyf(ctx, "#R:", 0, bg.r, 1.0f, 0.01f,0.005f);
            bg.g = nk_propertyf(ctx, "#G:", 0, bg.g, 1.0f, 0.01f,0.005f);
            bg.b = nk_propertyf(ctx, "#B:", 0, bg.b, 1.0f, 0.01f,0.005f);
            bg.a = nk_propertyf(ctx, "#A:", 0, bg.a, 1.0f, 0.01f,0.005f);
            nk_combo_end(ctx);
        }
    }
    nk_end(ctx);

    /* -------------- EXAMPLES ---------------- */
    #ifdef INCLUDE_CALCULATOR
      calculator(ctx);
    #endif
    #ifdef INCLUDE_OVERVIEW
      overview(ctx);
    #endif
    #ifdef INCLUDE_NODE_EDITOR
      node_editor(ctx);
    #endif

    nk_sdl_render(NK_ANTI_ALIASING_ON, MAX_VERTEX_MEMORY, MAX_ELEMENT_MEMORY);
}

void MouseManager::leftClick() {
    if(this->guiSystem->eventsCount <= 1000){
        this->guiSystem->eventsCount++;
        (this->guiSystem->events[this->guiSystem->eventsCount]).type = SDL_MOUSEBUTTONDOWN;
        (this->guiSystem->events[this->guiSystem->eventsCount]).button.button = SDL_BUTTON_LEFT;
        (this->guiSystem->events[this->guiSystem->eventsCount]).button.x = this->guiSystem->mouseX;
        (this->guiSystem->events[this->guiSystem->eventsCount]).button.y = this->guiSystem->mouseY;
    }    
}

void MouseManager::leftUp() {
    if(this->guiSystem->eventsCount <= 1000){
        this->guiSystem->eventsCount++;
        (this->guiSystem->events[this->guiSystem->eventsCount]).type = SDL_MOUSEBUTTONUP;
        (this->guiSystem->events[this->guiSystem->eventsCount]).button.button = SDL_BUTTON_LEFT;
        (this->guiSystem->events[this->guiSystem->eventsCount]).button.x = this->guiSystem->mouseX;
        (this->guiSystem->events[this->guiSystem->eventsCount]).button.y = this->guiSystem->mouseY;
    }
}

void MouseManager::rightUp() {
    nk_input_button(this->guiSystem->ctx, NK_BUTTON_LEFT, this->guiSystem->mouseX, this->guiSystem->mouseY, 0);
}

void MouseManager::rightClick() {
    
}

void MouseManager::middleClick() {
    
}

void MouseManager::mouseMove(unsigned int _x, unsigned int _y) {
    if(this->guiSystem->eventsCount <= 1000){
        this->guiSystem->eventsCount++;
        (this->guiSystem->events[this->guiSystem->eventsCount]).type = SDL_MOUSEMOTION;
        (this->guiSystem->events[this->guiSystem->eventsCount]).button.x = _x;
        (this->guiSystem->events[this->guiSystem->eventsCount]).button.y = _y;
        this->guiSystem->mouseX = _x;
        this->guiSystem->mouseY = _y;
    }
}

void MouseManager::wheelMove(unsigned int) {
    
}

void MouseManager::addGuiSystem(GUISystem* _guiSystem) {
    this->guiSystem = _guiSystem;
}