#include "GUISystem.h"
#include <glew.h>
#include <iostream>

#define MAX_VERTEX_MEMORY 512 * 1024
#define MAX_ELEMENT_MEMORY 128 * 1024

GLint status;
static const GLchar *vertex_shader =
    "#version 330 core\n"
    "uniform mat4 ProjMtx;\n"
    "in vec3 Position;\n"
    "in vec2 TexCoord;\n"
    "in vec4 Color;\n"
    "out vec2 Frag_UV;\n"
    "out vec4 Frag_Color;\n"
    "void main() {\n"
    "   Frag_UV = TexCoord;\n"
    "   Frag_Color = Color;\n"
    "   gl_Position = ProjMtx * vec4(Position.xyz, 1);\n"
    "}\n";
static const GLchar *fragment_shader =
    "#version 330 core\n"
    "precision mediump float;\n"
    "uniform sampler2D Texture;\n"
    "in vec2 Frag_UV;\n"
    "in vec4 Frag_Color;\n"
    "out vec4 Out_Color;\n"
    "void main(){\n"
    "   Out_Color = Frag_Color * texture(Texture, Frag_UV.st);\n"
    "}\n";

GUISystem::GUISystem(){
    renderCommand[NK_COMMAND_NOP] = new NopCommand();
    renderCommand[NK_COMMAND_SCISSOR] = new NopCommand();
    renderCommand[NK_COMMAND_LINE] = new LineCommand();
    renderCommand[NK_COMMAND_CURVE] = new CurveCommand();
    renderCommand[NK_COMMAND_RECT] = new RectCommand();
    renderCommand[NK_COMMAND_RECT_FILLED] = new RectFilledCommand();
    renderCommand[NK_COMMAND_RECT_MULTI_COLOR] = new RectMultiColorCommand();
    renderCommand[NK_COMMAND_CIRCLE] = new CirleCommand();
    renderCommand[NK_COMMAND_CIRCLE_FILLED] = new CircleFilledCommand();
    renderCommand[NK_COMMAND_ARC] = new ArcCommand();
    renderCommand[NK_COMMAND_ARC_FILLED] = new ArcFilledCommand();
    renderCommand[NK_COMMAND_TRIANGLE] = new TriangleCommand();
    renderCommand[NK_COMMAND_TRIANGLE_FILLED] = new TriangleFilledCommand();
    renderCommand[NK_COMMAND_POLYGON] = new PolygonCommand();
    renderCommand[NK_COMMAND_POLYGON_FILLED] = new PolygonFilledCommand();
    renderCommand[NK_COMMAND_POLYLINE] = new PolylineCommand();
    renderCommand[NK_COMMAND_TEXT] = new TextCommand();
    renderCommand[NK_COMMAND_IMAGE] = new ImageCommand();
    renderCommand[NK_COMMAND_CUSTOM] = new CustomCommand();
}

GUISystem::~GUISystem(){

}

void GUISystem::init(SDL_Window* win){
    nk_init_fixed(&ctx, calloc(1, MAX_ELEMENT_MEMORY), MAX_ELEMENT_MEMORY, 0);
    nk_buffer_init_default(&cmds);
    nk_font_atlas_init_default(&atlas);
    nk_font_atlas_begin(&atlas);
    loadFont();
	initShader();

    enum {EASY, HARD};
    static int op = EASY;
    static float value = 0.6f;
    static int i =  20;
    if (nk_begin(&ctx, "Show", nk_rect(50, 50, 220, 220), NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_CLOSABLE)) {
        nk_layout_row_static(&ctx, 30, 80, 1);
        if (nk_button_label(&ctx, "button")) {

        }

        nk_layout_row_dynamic(&ctx, 30, 2);
        if (nk_option_label(&ctx, "easy", op == EASY)) op = EASY;
        if (nk_option_label(&ctx, "hard", op == HARD)) op = HARD;

        nk_layout_row_begin(&ctx, NK_STATIC, 30, 2);
        {
            nk_layout_row_push(&ctx, 50);
            nk_label(&ctx, "Volume:", NK_TEXT_LEFT);
            nk_layout_row_push(&ctx, 110);
            nk_slider_float(&ctx, 0, &value, 1.0f, 0.1f);
        }
        nk_layout_row_end(&ctx);
    }
    nk_end(&ctx);
}

void GUISystem::draw(){
    glUseProgram(prog);
    nk_foreach(cmd, &ctx) {
        renderCommand[cmd->type]->excecute(this);
    }
}

void GUISystem::initShader(){
    this->projectionMatrix.orthoMatrix(0.0f, 800.0f, 0.0f, 600.0f, -100.0f, 100.0f);
    prog = glCreateProgram();
    vert_shdr = glCreateShader(GL_VERTEX_SHADER);
    frag_shdr = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(vert_shdr, 1, &vertex_shader, 0);
    glShaderSource(frag_shdr, 1, &fragment_shader, 0);
    glCompileShader(vert_shdr);
    glCompileShader(frag_shdr);
    glGetShaderiv(vert_shdr, GL_COMPILE_STATUS, &status);
    assert(status == GL_TRUE);
    glGetShaderiv(frag_shdr, GL_COMPILE_STATUS, &status);
    assert(status == GL_TRUE);
    glAttachShader(prog, vert_shdr);
    glAttachShader(prog, frag_shdr);
    glLinkProgram(prog);
    glGetProgramiv(prog, GL_LINK_STATUS, &status);
    assert(status == GL_TRUE);

    uniform_tex = glGetUniformLocation(prog, "Texture");
    uniform_proj = glGetUniformLocation(prog, "ProjMtx");
    attrib_pos = glGetAttribLocation(prog, "Position");
    attrib_uv = glGetAttribLocation(prog, "TexCoord");
    attrib_col = glGetAttribLocation(prog, "Color");

    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
    glGenVertexArrays(1, &vao);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

    glEnableVertexAttribArray((GLuint)attrib_pos);
    glEnableVertexAttribArray((GLuint)attrib_uv);
    glEnableVertexAttribArray((GLuint)attrib_col);

    //glVertexAttribPointer((GLuint)attrib_pos, 2, GL_FLOAT, GL_FALSE, vs, (void*)vp);
    //glVertexAttribPointer((GLuint)attrib_uv, 2, GL_FLOAT, GL_FALSE, vs, (void*)vt);
    //glVertexAttribPointer((GLuint)attrib_col, 4, GL_UNSIGNED_BYTE, GL_TRUE, vs, (void*)vc);

    glBindTexture(GL_TEXTURE_2D, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void GUISystem::loadFont() {
    const void *image; int w, h;
    image = nk_font_atlas_bake(&atlas, &w, &h, NK_FONT_ATLAS_RGBA32);
    createOpenGLRender(image, w, h);
    nk_font_atlas_end(&atlas, nk_handle_id(font_tex), &nullTexture);
    if (atlas.default_font)
        nk_style_set_font(&ctx, &atlas.default_font->handle);

}

void GUISystem::createOpenGLRender(const void *image, int width, int height)
{
    glGenTextures(1, &font_tex);
    glBindTexture(GL_TEXTURE_2D, font_tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)width, (GLsizei)height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
}

unsigned int GUISystem::getAttribPos(){
    return this->attrib_pos;
}

void NopCommand::excecute(GUISystem* guiSystem){
    std::cout << "NopCommand\n" << std::endl;
}

void ScissorCommand::excecute(GUISystem* guiSystem){
    std::cout << "ScissorCommand\n" << std::endl;
}

void LineCommand::excecute(GUISystem* guiSystem){
    std::cout << ((const struct nk_command_line*)guiSystem->cmd)->begin.x << "-"<< ((const struct nk_command_line*)guiSystem->cmd)->begin.y << std::endl;
}

void CurveCommand::excecute(GUISystem* guiSystem){
    std::cout << "CurveCommand\n" << std::endl;
}

void RectCommand::excecute(GUISystem* guiSystem){
    std::cout << "RectCommand\n" << std::endl;
}

void RectFilledCommand::excecute(GUISystem* guiSystem){
    std::cout << guiSystem->cmd->type << std::endl;
    glVertexAttribPointer(guiSystem->getAttribPos(), 3, GL_FLOAT, GL_FALSE, 0, ((const struct nk_command_rect_filled*)guiSystem->cmd)->vertexPointers);
    glEnableVertexAttribArray(guiSystem->getAttribPos());
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, ((const struct nk_command_rect_filled*)guiSystem->cmd)->facesIndex);
}

void RectMultiColorCommand::excecute(GUISystem* guiSystem){
    std::cout << "RectMultiColorCommand\n" << std::endl;
}

void CirleCommand::excecute(GUISystem* guiSystem){
    std::cout << "CirleCommand\n" << std::endl;
}

void CircleFilledCommand::excecute(GUISystem* guiSystem){
    std::cout << "CircleFilledCommand\n" << std::endl;
}

void ArcCommand::excecute(GUISystem* guiSystem){
    std::cout << "ArcCommand\n" << std::endl;
}

void ArcFilledCommand::excecute(GUISystem* guiSystem){
    std::cout << "ArcFilledCommand\n" << std::endl;
}

void TriangleCommand::excecute(GUISystem* guiSystem){
    std::cout << "TriangleCommand\n" << std::endl;
}

void TriangleFilledCommand::excecute(GUISystem* guiSystem){
    std::cout << "TriangleFilledCommand\n" << std::endl;
}
    
void PolygonCommand::excecute(GUISystem* guiSystem){
    std::cout << "PolygonCommand\n" << std::endl;
}
    

void PolygonFilledCommand::excecute(GUISystem* guiSystem){
    std::cout << "PolygonFilledCommand\n" << std::endl;
}
    
void PolylineCommand::excecute(GUISystem* guiSystem){
    std::cout << "PolylineCommand\n" << std::endl;
}   

void TextCommand::excecute(GUISystem* guiSystem){
    std::cout << "TextCommand\n" << std::endl;
}

void ImageCommand::excecute(GUISystem* guiSystem){
    std::cout << "ImageCommand\n" << std::endl;
}
    
void CustomCommand::excecute(GUISystem* guiSystem){
    std::cout << "CustomCommand\n" << std::endl;
}