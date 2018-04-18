#include "GUISystem.h"
#include <glew.h>
#include <iostream>
#include <string>

#define MAX_VERTEX_MEMORY 512 * 1024
#define MAX_ELEMENT_MEMORY 128 * 1024

GLint status, blen;
GLsizei slen = 0;
std::string vertex_shader = "#version 330\n" 
                            "uniform mat4 ProjMtx;\n"
                            "in vec3 vertexPosition;\n" 
                            "in vec3 vertexColor;\n" 
                            "out vec3 color;\n" 
                            "void main() {\n" 
                            "    color = vertexColor;\n" 
                            "    gl_Position = ProjMtx * vec4(vertexPosition.xyz, 1.0);\n"
                            "}";

std::string fragment_shader = "#version 330\n" 
                              "in vec3 color;\n"
                              "void main(){\n" 
                              "     gl_FragColor = vec4(color.xyz ,0.0);\n" 
                              "}";

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

    //this->projectionMatrix.perspectiveMatrix(45.0f, 800.0f/600.0f, 0.1f, 2000.0f);
    this->projectionMatrix.orthoMatrix(0.0f, 1024.0f, 0.0f, 780.0f, -0.1f, 10.0f);
    Vector3* position = new Vector3(0.0,0.0,-1.0);
    Vector3* point = new Vector3(0.0,0.0,0.0);
    Vector3* up = new Vector3(0.0,1.0,0.0);
    this->camera.lookAt(*position,*point,*up);
    delete position;
    delete point;
    delete up;

    nk_style_button pruebaButton;
    pruebaButton.normal.data.color.r = 1.0;
    pruebaButton.normal.data.color.g = 1.0;
    pruebaButton.normal.data.color.b = 1.0;

    enum {EASY, HARD};
    static int op = EASY;
    static float value = 0.6f;
    if (nk_begin(&ctx, "Show", nk_rect(100, 100, 400, 300), NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_CLOSABLE)) {
        /*nk_layout_row_static(&ctx, 50, 100, 1);
        if (nk_button_label_styled(&ctx, &pruebaButton, "button")) {

        }*/

        nk_layout_row_dynamic(&ctx, 100, 10);
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
    std::cout << "llega" << std::endl;
}

void GUISystem::draw(){
    nk_foreach(cmd, &ctx) {
        renderCommand[cmd->type]->excecute(this);
    }
}

void GUISystem::initShader(){
    prog = glCreateProgram();
    vert_shdr = glCreateShader(GL_VERTEX_SHADER);
    frag_shdr = glCreateShader(GL_FRAGMENT_SHADER);

    const GLchar *sourceVertex = (const GLchar *) vertex_shader.c_str();
    glShaderSource(vert_shdr, 1, &sourceVertex, 0);

    const GLchar *sourceFragment = (const GLchar *) fragment_shader.c_str();
    glShaderSource(frag_shdr, 1, &sourceFragment, 0);

    glCompileShader(vert_shdr);
    glCompileShader(frag_shdr);
    
    glGetShaderiv(vert_shdr, GL_COMPILE_STATUS, &status);
    if(!status){
        glGetShaderiv(vert_shdr, GL_INFO_LOG_LENGTH , &blen);
        GLchar* compiler_log = (GLchar*)malloc(blen);
        glGetInfoLogARB(vert_shdr, blen, &slen, compiler_log);
        std::cout << "Vertex Shader Compilation has failed: " << compiler_log << std::endl;
        free (compiler_log);
    }

    glGetShaderiv(frag_shdr, GL_COMPILE_STATUS, &status);
    if(!status){
        glGetShaderiv(frag_shdr, GL_INFO_LOG_LENGTH , &blen);
        GLchar* compiler_log = (GLchar*)malloc(blen);
        glGetInfoLogARB(frag_shdr, blen, &slen, compiler_log);
        std::cout << "Vertex Shader Compilation has failed: " << compiler_log << std::endl;
        free (compiler_log);
    }

    glAttachShader(prog, vert_shdr);
    glAttachShader(prog, frag_shdr);
    glLinkProgram(prog);
    glGetProgramiv(prog, GL_LINK_STATUS, &status);

    uniform_proj = glGetUniformLocation(prog, "ProjMtx");
    std::cout << uniform_proj << std::endl;
    if(uniform_proj == -1)
        std::cout << "\033[1;31m[ERROR]:\033[0m" << " uniform_proj was not finded into Shader Object" << std::endl;
    
    attrib_pos = glGetAttribLocation(prog, "vertexPosition");
    std::cout << attrib_pos << std::endl;
    if(attrib_pos == -1)
        std::cout << "\033[1;31m[ERROR]:\033[0m" << " attrib_pos was not finded into Shader Object" << std::endl;
    
    attrib_col = glGetAttribLocation(prog, "vertexColor");
    std::cout << attrib_col << std::endl;
    if(attrib_col == -1)
        std::cout << "\033[1;31m[ERROR]:\033[0m" << " attrib_col was not finded into Shader Object" << std::endl;
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

void NopCommand::excecute(GUISystem* guiSystem){

}

void ScissorCommand::excecute(GUISystem* guiSystem){

}

void LineCommand::excecute(GUISystem* guiSystem){
    GLuint element[2] = {0,1};
    float vertex[6] = { ((const struct nk_command_line*)guiSystem->cmd)->begin.x, ((const struct nk_command_line*)guiSystem->cmd)->begin.y, 0.0,
                         ((const struct nk_command_line*)guiSystem->cmd)->end.x, ((const struct nk_command_line*)guiSystem->cmd)->end.y, 0.0};

    float color[12] = {1.0,0.0,1.0,
                       1.0,0.0,1.0,
                       1.0,0.0,1.0,
                       1.0,0.0,1.0};

    glLineWidth(5.0);
    glEnableVertexAttribArray(guiSystem->attrib_pos);
    glEnableVertexAttribArray(guiSystem->attrib_col);
    glUseProgram(guiSystem->prog);
    glUniformMatrix4fv(guiSystem->uniform_proj, 1, GL_FALSE, guiSystem->projectionMatrix.toFloatPointer());
    glUniformMatrix4fv(guiSystem->uniform_view, 1, GL_FALSE, guiSystem->camera.getViewMatrixAsPointer());
    glVertexAttribPointer(guiSystem->attrib_pos, 3, GL_FLOAT, GL_FALSE, 0, vertex);
    glVertexAttribPointer(guiSystem->attrib_col, 3, GL_FLOAT, GL_FALSE, 0, color);
    glEnableVertexAttribArray(guiSystem->attrib_pos);
    glEnableVertexAttribArray(guiSystem->attrib_col);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_INT, element);
    
}

void CurveCommand::excecute(GUISystem* guiSystem){

}

void RectCommand::excecute(GUISystem* guiSystem){
    GLuint element[6] = {1,2,0,1,3,2};
    float vertex[12] = {((const struct nk_command_line*)guiSystem->cmd)->begin.x, ((const struct nk_command_line*)guiSystem->cmd)->begin.y, 0.0,
                        ((const struct nk_command_line*)guiSystem->cmd)->begin.x, ((const struct nk_command_line*)guiSystem->cmd)->begin.y, 0.0,
                        ((const struct nk_command_line*)guiSystem->cmd)->begin.x, ((const struct nk_command_line*)guiSystem->cmd)->begin.y, 0.0,
                        ((const struct nk_command_line*)guiSystem->cmd)->begin.x, ((const struct nk_command_line*)guiSystem->cmd)->begin.y, 0.0};


    float color[16] = {1.0,0.0,0.0,0.0, 1.0,0.0,0.0,0.0, 1.0,0.0,0.0,0.0, 1.0,0.0,0.0,0.0};

    glLineWidth(1.0);
    glUseProgram(guiSystem->prog);
    glEnableVertexAttribArray(guiSystem->attrib_pos);
    glEnableVertexAttribArray(guiSystem->attrib_col);
    glUniformMatrix4fv(guiSystem->uniform_proj, 1, GL_FALSE, guiSystem->projectionMatrix.toFloatPointer());
    glUniformMatrix4fv(guiSystem->uniform_view, 1, GL_FALSE, guiSystem->camera.getViewMatrixAsPointer());
    glVertexAttribPointer(guiSystem->attrib_pos, 3, GL_FLOAT, GL_FALSE, 0, vertex);
    glVertexAttribPointer(guiSystem->attrib_col, 4, GL_FLOAT, GL_FALSE, 0, color);
    glEnableVertexAttribArray(guiSystem->attrib_pos);
    glEnableVertexAttribArray(guiSystem->attrib_col);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, element);
}

void RectFilledCommand::excecute(GUISystem* guiSystem){
    GLuint element[6] = {1,2,0,1,3,2};
    float vertex[12] = { ((const struct nk_command_rect_filled*)guiSystem->cmd)->x, ((const struct nk_command_rect_filled*)guiSystem->cmd)->y, 0.0,
                        ((const struct nk_command_rect_filled*)guiSystem->cmd)->x+((const struct nk_command_rect_filled*)guiSystem->cmd)->w, ((const struct nk_command_rect_filled*)guiSystem->cmd)->y, 0.0,
                        ((const struct nk_command_rect_filled*)guiSystem->cmd)->x, ((const struct nk_command_rect_filled*)guiSystem->cmd)->y+((const struct nk_command_rect_filled*)guiSystem->cmd)->h, 0.0,
                        ((const struct nk_command_rect_filled*)guiSystem->cmd)->x+((const struct nk_command_rect_filled*)guiSystem->cmd)->w, ((const struct nk_command_rect_filled*)guiSystem->cmd)->y+((const struct nk_command_rect_filled*)guiSystem->cmd)->h, 0.0};

    float color[15] = {0.0,1.0,0.0,
                       0.0,1.0,0.0,
                       0.0,1.0,0.0,
                       0.0,1.0,0.0};

    glLineWidth(1.0);
    glUseProgram(guiSystem->prog);
    glEnableVertexAttribArray(guiSystem->attrib_pos);
    glEnableVertexAttribArray(guiSystem->attrib_col);
    glUniformMatrix4fv(guiSystem->uniform_proj, 1, GL_FALSE, guiSystem->projectionMatrix.toFloatPointer());
    glUniformMatrix4fv(guiSystem->uniform_view, 1, GL_FALSE, guiSystem->camera.getViewMatrixAsPointer());
    glVertexAttribPointer(guiSystem->attrib_pos, 3, GL_FLOAT, GL_FALSE, 0, vertex);
    glVertexAttribPointer(guiSystem->attrib_col, 3, GL_FLOAT, GL_FALSE, 0, color);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, element);
}

void RectMultiColorCommand::excecute(GUISystem* guiSystem){

}

void CirleCommand::excecute(GUISystem* guiSystem){

}

void CircleFilledCommand::excecute(GUISystem* guiSystem){
    GLuint element[1] = {0};
    float vertex[3] = { ((const struct nk_command_circle_filled*)guiSystem->cmd)->x, ((const struct nk_command_circle_filled*)guiSystem->cmd)->y, 0.0};

    float color[16] = {1.0,0.0,0.0,0.0, 1.0,0.0,0.0,0.0, 1.0,0.0,0.0,0.0, 1.0,0.0,0.0,0.0};

    glPointSize(10.0);
    glUseProgram(guiSystem->prog);
    glUniformMatrix4fv(guiSystem->uniform_proj, 1, GL_FALSE, guiSystem->projectionMatrix.toFloatPointer());
    glUniformMatrix4fv(guiSystem->uniform_view, 1, GL_FALSE, guiSystem->camera.getViewMatrixAsPointer());
    glVertexAttribPointer(guiSystem->attrib_pos, 3, GL_FLOAT, GL_FALSE, 0, vertex);
    glVertexAttribPointer(guiSystem->attrib_col, 4, GL_FLOAT, GL_FALSE, 0, color);
    glEnableVertexAttribArray(guiSystem->attrib_pos);
    glEnableVertexAttribArray(guiSystem->attrib_col);
    glDrawElements(GL_POINTS, 1, GL_UNSIGNED_INT, element);
}

void ArcCommand::excecute(GUISystem* guiSystem){

}

void ArcFilledCommand::excecute(GUISystem* guiSystem){

}

void TriangleCommand::excecute(GUISystem* guiSystem){

}

void TriangleFilledCommand::excecute(GUISystem* guiSystem){

}
    
void PolygonCommand::excecute(GUISystem* guiSystem){

}
    

void PolygonFilledCommand::excecute(GUISystem* guiSystem){

}
    
void PolylineCommand::excecute(GUISystem* guiSystem){

}   

void TextCommand::excecute(GUISystem* guiSystem){

}

void ImageCommand::excecute(GUISystem* guiSystem){

}
    
void CustomCommand::excecute(GUISystem* guiSystem){

}