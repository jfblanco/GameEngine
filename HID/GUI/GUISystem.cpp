#include "GUISystem.h"
#include <glew.h>
#include <iostream>
#include <string>

#define MAX_VERTEX_MEMORY 512 * 1024
#define MAX_ELEMENT_MEMORY 128 * 1024

void initializeShaderFromString(unsigned int* program, const char* vertexCode, const char* fragmentCode);

GLint status, blen;
GLsizei slen = 0;
std::string vertex_shader = "#version 400 core\n"
                            "uniform mat4 ProjMtx;\n"
                            "in vec4 vPosition;\n"
                            "in vec4 vColor;\n"
                            "out vec4 color;\n"
                            "void main() {\n"
                            "    color = vColor;\n"
                            "    gl_Position = ProjMtx * vPosition;\n"
                            "}";

std::string fragment_shader = "#version 450 core\n"
                              "in vec4 color;\n"
                              "void main(){\n"
                              "     gl_FragColor = color;\n"
                              "}";

std::string vertex_circle_shader =   "#version 400 core\n"
                                    "uniform mat4 ProjMtx;\n"
                                    "uniform vec2 ePosition;\n"
                                    "in vec4 vPosition;\n"
                                    "in vec4 vColor;\n"
                                    "out vec4 color;\n"
                                    "out vec2 elementPosition;\n"
                                    "void main() {\n"
                                    "    color = vColor;\n"
                                    "    elementPosition = ePosition;\n"
                                    "    gl_Position = ProjMtx * vPosition;\n"
                                    "}";

std::string fragment_circle_shader =  "#version 450 core\n"
                                      "in vec4 color;\n"
                                      "in vec2 elementPosition;\n"
                                      "out vec4 fColor;\n"
                                      "void main(){\n"
                                      "     fColor = vec4(1.0,1.0,0.0,1.0);\n"
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

void GUISystem::createDrawableObject(){
    nk_foreach(cmd, &ctx) {
        renderCommand[cmd->type]->setOpenGLBuffers(this);
    }
}

void GUISystem::init(SDL_Window* win){
    nk_init_fixed(&ctx, calloc(1, MAX_ELEMENT_MEMORY), MAX_ELEMENT_MEMORY, 0);
    nk_buffer_init_default(&cmds);
    nk_font_atlas_init_default(&atlas);
    nk_font_atlas_begin(&atlas);
    loadFont();
    initShader();

    ctx.style.button.normal.data.color.r = 100;
    ctx.style.button.normal.data.color.g = 0;
    ctx.style.button.normal.data.color.b = 100;

    ctx.style.window.header.normal.data.color.r = 100;
    ctx.style.window.header.normal.data.color.g = 0;
    ctx.style.window.header.normal.data.color.b = 100;

    ctx.style.window.fixed_background.data.color.r = 80;
    ctx.style.window.fixed_background.data.color.g = 80;
    ctx.style.window.fixed_background.data.color.b = 80;

    //this->projectionMatrix.perspectiveMatrix(45.0f, 800.0f/600.0f, 0.1f, 2.0f);
    this->projectionMatrix.orthoMatrix(0.0f, 800.0f, 0.0f, 600.0f, 0.0f, -1.0f);
    Vector3* position = new Vector3(0.0,0.0,-1.0);
    Vector3* point = new Vector3(0.0,0.0,0.0);
    Vector3* up = new Vector3(0.0,1.0,0.0);
    this->camera.lookAt(*position,*point,*up);
    delete position;
    delete point;
    delete up;

    enum {EASY, HARD};
    static int op = EASY;
    static float value = 0.6f;
    if (nk_begin(&ctx, "Show", nk_rect(50, 50, 220, 220), NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_CLOSABLE)) {

        nk_layout_row_static(&ctx, 30, 80, 1);
        if (nk_button_label(&ctx, "button")) {
            /* event handling */
        }

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

    this->createDrawableObject();
}

void GUISystem::draw(){
    nk_foreach(cmd, &ctx) {
        renderCommand[cmd->type]->excecute(this);
    }
}

void GUISystem::initShader(){
    initializeShaderFromString(&progRectangle,vertex_shader.c_str(), fragment_shader.c_str());

    uniform_rectangle_proj = glGetUniformLocation(progRectangle, "ProjMtx");
    if(uniform_rectangle_proj == -1)
        std::cout << "\033[1;31m[ERROR]:\033[0m" << " uniform_rectangle_proj was not finded into Shader Object" << std::endl;

    attrib_rectangle_pos = glGetAttribLocation(progRectangle, "vPosition");
     if(attrib_rectangle_pos == -1)
        std::cout << "\033[1;31m[ERROR]:\033[0m" << " attrib_rectangle_pos was not finded into Shader Object" << std::endl;

    attrib_rectangle_col = glGetAttribLocation(progRectangle, "vColor");
    if(attrib_rectangle_col == -1)
        std::cout << "\033[1;31m[ERROR]:\033[0m" << " vColor was not finded into Shader Object" << std::endl;

    initializeShaderFromString(&progCircle,vertex_circle_shader.c_str(), fragment_circle_shader.c_str());

    uniform_circle_proj = glGetUniformLocation(progCircle, "ProjMtx");
    if(uniform_circle_proj == -1)
        std::cout << "\033[1;31m[ERROR]:\033[0m" << " uniform_circle_proj was not finded into Shader Object" << std::endl;

    attrib_circle_pos = glGetAttribLocation(progCircle, "vPosition");
     if(attrib_circle_pos == -1)
        std::cout << "\033[1;31m[ERROR]:\033[0m" << " attrib_circle_pos was not finded into Shader Object" << std::endl;

    attrib_circle_col = glGetAttribLocation(progCircle, "vColor");
    if(attrib_circle_col == -1)
        std::cout << "\033[1;31m[ERROR]:\033[0m" << " vColor was not finded into Shader Object" << std::endl;

    element_position = glGetUniformLocation(progCircle, "ePosition");
    if(element_position == -1)
        std::cout << "\033[1;31m[ERROR]:\033[0m" << " ePosition was not finded into Shader Object" << std::endl;
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

void NopCommand::setOpenGLBuffers(GUISystem* guiSystem){

}

void ScissorCommand::excecute(GUISystem* guiSystem){

}

void ScissorCommand::setOpenGLBuffers(GUISystem* guiSystem){

}

void LineCommand::excecute(GUISystem* guiSystem){

}

void LineCommand::setOpenGLBuffers(GUISystem* guiSystem){

}

void CurveCommand::excecute(GUISystem* guiSystem){

}

void CurveCommand::setOpenGLBuffers(GUISystem* guiSystem){

}

void RectCommand::excecute(GUISystem* guiSystem){

}

void RectCommand::setOpenGLBuffers(GUISystem* guiSystem){

}

void RectFilledCommand::excecute(GUISystem* guiSystem){

    nk_command_rect_filled* rectFilled = (struct nk_command_rect_filled* )guiSystem->cmd;

    glUseProgram(guiSystem->progRectangle);
    glBindVertexArray(rectFilled->vertexBufferObject);

    glUniformMatrix4fv(guiSystem->uniform_rectangle_proj, 1, GL_FALSE, guiSystem->projectionMatrix.toFloatPointer());

    glBindBuffer(GL_ARRAY_BUFFER, rectFilled->vertexId);
    glVertexAttribPointer( guiSystem->attrib_rectangle_pos, 2, GL_FLOAT, GL_FALSE, 0, 0 );
    glEnableVertexAttribArray( guiSystem->attrib_rectangle_pos );

    glBindBuffer(GL_ARRAY_BUFFER, rectFilled->colorId);
    glVertexAttribPointer( guiSystem->attrib_rectangle_col, 3, GL_FLOAT, GL_FALSE, 0, 0 );
    glEnableVertexAttribArray( guiSystem->attrib_rectangle_col);

    glBindBuffer(GL_ARRAY_BUFFER, rectFilled->indexId);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void RectFilledCommand::setOpenGLBuffers(GUISystem* guiSystem){

    nk_command_rect_filled* rectFilled = (struct nk_command_rect_filled* )guiSystem->cmd;

    GLfloat  vertices[8] = { rectFilled->x, rectFilled->y , rectFilled->x + rectFilled->w, rectFilled->y, rectFilled->x,  rectFilled->y + rectFilled->h , rectFilled->x + rectFilled->w,  rectFilled->y + rectFilled->h };
    GLfloat red = rectFilled->color.r/100.0f;
    GLfloat green = rectFilled->color.g/100.0f;
    GLfloat blue = rectFilled->color.b/100.0f;

    GLfloat  colours[12] = { red, green , blue, red, green , blue, red, green , blue, red, green , blue };
    GLuint  index[6] = { 1,2,0,1,3,2 };

    glCreateVertexArrays( 1, &rectFilled->vertexBufferObject );
    glBindVertexArray( rectFilled->vertexBufferObject );

    glGenBuffers(1, &rectFilled->vertexId);
    glBindBuffer(GL_ARRAY_BUFFER, rectFilled->vertexId);
    glBufferStorage( GL_ARRAY_BUFFER, sizeof(vertices), vertices, 0);

    glGenBuffers(1, &rectFilled->colorId);
    glBindBuffer(GL_ARRAY_BUFFER, rectFilled->colorId);
    glBufferStorage( GL_ARRAY_BUFFER, sizeof(colours), colours, 0);

    glGenBuffers(1, &rectFilled->indexId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rectFilled->indexId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);
}

void RectMultiColorCommand::excecute(GUISystem* guiSystem){

}

void RectMultiColorCommand::setOpenGLBuffers(GUISystem* guiSystem){

}

void CirleCommand::excecute(GUISystem* guiSystem){

}

void CirleCommand::setOpenGLBuffers(GUISystem* guiSystem){

}

void CircleFilledCommand::excecute(GUISystem* guiSystem){
    nk_command_circle_filled* circleFilled = (struct nk_command_circle_filled* )guiSystem->cmd;

    glUseProgram(guiSystem->progCircle);
    glBindVertexArray(circleFilled->vertexBufferObject);

    glUniformMatrix4fv(guiSystem->uniform_rectangle_proj, 1, GL_FALSE, guiSystem->projectionMatrix.toFloatPointer());
    glUniform2fv(guiSystem->element_position, 1, (GLfloat*)&(circleFilled->x));

    glBindBuffer(GL_ARRAY_BUFFER, circleFilled->vertexId);
    glVertexAttribPointer( guiSystem->attrib_rectangle_pos, 2, GL_FLOAT, GL_FALSE, 0, 0 );
    glEnableVertexAttribArray( guiSystem->attrib_rectangle_pos );

    glBindBuffer(GL_ARRAY_BUFFER, circleFilled->colorId);
    glVertexAttribPointer( guiSystem->attrib_rectangle_col, 3, GL_FLOAT, GL_FALSE, 0, 0 );
    glEnableVertexAttribArray( guiSystem->attrib_rectangle_col);

    glBindBuffer(GL_ARRAY_BUFFER, circleFilled->indexId);
    glDrawElements(GL_POINTS, 1, GL_UNSIGNED_INT, 0);
}

void CircleFilledCommand::setOpenGLBuffers(GUISystem* guiSystem){
    nk_command_circle_filled* circleFilled = (struct nk_command_circle_filled* )guiSystem->cmd;

    GLfloat  vertices[2] = { circleFilled->x, circleFilled->y};
    GLfloat red = circleFilled->color.r/100.0f;
    GLfloat green = circleFilled->color.g/100.0f;
    GLfloat blue = circleFilled->color.b/100.0f;

    GLfloat  colours[3] = { red, green , blue };
    GLuint  index[1] = { 0};

    glCreateVertexArrays( 1, &circleFilled->vertexBufferObject );
    glBindVertexArray( circleFilled->vertexBufferObject );

    glGenBuffers(1, &circleFilled->vertexId);
    glBindBuffer(GL_ARRAY_BUFFER, circleFilled->vertexId);
    glBufferStorage( GL_ARRAY_BUFFER, sizeof(vertices), vertices, 0);

    glGenBuffers(1, &circleFilled->colorId);
    glBindBuffer(GL_ARRAY_BUFFER, circleFilled->colorId);
    glBufferStorage( GL_ARRAY_BUFFER, sizeof(colours), colours, 0);

    glGenBuffers(1, &circleFilled->indexId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, circleFilled->indexId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);
}

void ArcCommand::excecute(GUISystem* guiSystem){

}

void ArcCommand::setOpenGLBuffers(GUISystem* guiSystem){

}

void ArcFilledCommand::excecute(GUISystem* guiSystem){

}

void ArcFilledCommand::setOpenGLBuffers(GUISystem* guiSystem){

}

void TriangleCommand::excecute(GUISystem* guiSystem){

}

void TriangleCommand::setOpenGLBuffers(GUISystem* guiSystem){

}

void TriangleFilledCommand::excecute(GUISystem* guiSystem){

}

void TriangleFilledCommand::setOpenGLBuffers(GUISystem* guiSystem){

}

void PolygonCommand::excecute(GUISystem* guiSystem){

}

void PolygonCommand::setOpenGLBuffers(GUISystem* guiSystem){

}


void PolygonFilledCommand::excecute(GUISystem* guiSystem){

}

void PolygonFilledCommand::setOpenGLBuffers(GUISystem* guiSystem){

}

void PolylineCommand::excecute(GUISystem* guiSystem){

}

void PolylineCommand::setOpenGLBuffers(GUISystem* guiSystem){

}

void TextCommand::excecute(GUISystem* guiSystem){

}

void TextCommand::setOpenGLBuffers(GUISystem* guiSystem){

}

void ImageCommand::excecute(GUISystem* guiSystem){

}

void ImageCommand::setOpenGLBuffers(GUISystem* guiSystem){

}

void CustomCommand::excecute(GUISystem* guiSystem){

}

void CustomCommand::setOpenGLBuffers(GUISystem* guiSystem){

}

void initializeShaderFromString(unsigned int* program, const char* vertexCode, const char* fragmentCode){
    *program = glCreateProgram();
    GLuint vert_shdr = glCreateShader(GL_VERTEX_SHADER);
    GLuint frag_shdr = glCreateShader(GL_FRAGMENT_SHADER);

    const GLchar *sourceVertex = (const GLchar*) vertexCode;
    glShaderSource(vert_shdr, 1, &sourceVertex, 0);

    const GLchar *sourceFragment = (const GLchar*) fragmentCode;
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

    glAttachShader(*program, vert_shdr);
    glAttachShader(*program, frag_shdr);
    glLinkProgram(*program);
    glGetProgramiv(*program, GL_LINK_STATUS, &status);
    if(!status){
        glGetShaderiv(frag_shdr, GL_INFO_LOG_LENGTH , &blen);
        GLchar* compiler_log = (GLchar*)malloc(blen);
        glGetInfoLogARB(frag_shdr, blen, &slen, compiler_log);
        std::cout << "Linking program has failed: " << compiler_log << std::endl;
        free (compiler_log);
    }
}