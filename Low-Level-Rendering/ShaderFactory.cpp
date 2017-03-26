#include "ShaderFactory.h"
#include "../Core/utils/Shader.h"
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <glew.h>

unsigned long getFileLength(std::ifstream&);
char* readFile(const char*, int*);


ShaderFactory::ShaderFactory(){

}

ShaderFactory::~ShaderFactory(){

}

Shader* ShaderFactory::createShader(const char* _vertexShader, const char* _fragmentShader, Shader* _shader){
    int vertexShaderStringLenght;
    int fragmentShaderStringLenght;
    int success = 0;
    int blen = 0;
    int linked;    
    GLsizei slen = 0;

    char* vertexShaderStringCode = readFile(_vertexShader, &vertexShaderStringLenght);
    char* fragmentShaderStringCode = readFile(_fragmentShader, &fragmentShaderStringLenght);

    _shader->vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    _shader->fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(_shader->vertexShaderId, 1, &vertexShaderStringCode, &vertexShaderStringLenght);
    glShaderSource(_shader->fragmentShaderId, 1, &fragmentShaderStringCode, &fragmentShaderStringLenght);

    glCompileShader(_shader->vertexShaderId);
    glGetShaderiv(_shader->vertexShaderId, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderiv(_shader->vertexShaderId, GL_INFO_LOG_LENGTH , &blen);
        GLchar* compiler_log = (GLchar*)malloc(blen);
        glGetInfoLogARB(_shader->vertexShaderId, blen, &slen, compiler_log);
        std::cout << "Vertex Shader Compilation has failed: " << compiler_log << std::endl;
        free (compiler_log);
    }

    glCompileShader(_shader->fragmentShaderId);
    glGetShaderiv(_shader->fragmentShaderId, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderiv(_shader->fragmentShaderId, GL_INFO_LOG_LENGTH , &blen);
        GLchar* compiler_log = (GLchar*)malloc(blen);
        glGetInfoLogARB(_shader->fragmentShaderId, blen, &slen, compiler_log);
        std::cout << "Fragment Shader Compilation has failed: " << compiler_log << std::endl;
        free (compiler_log);
    }

    _shader->programShaderId = glCreateProgram();

    glAttachShader(_shader->programShaderId, _shader->vertexShaderId);
    glAttachShader(_shader->programShaderId, _shader->fragmentShaderId);

    glLinkProgram(_shader->programShaderId);   

    glGetProgramiv(_shader->programShaderId, GL_LINK_STATUS, &linked);
    if (!linked)
    {
       glGetProgramiv(_shader->programShaderId, GL_INFO_LOG_LENGTH , &blen);
       GLchar* compiler_log = (GLchar*)malloc(blen);
       glGetInfoLogARB(_shader->programShaderId, blen, &slen, compiler_log);
       std::cout << "Linking Shader Compilation has failed: " << compiler_log << std::endl;
       free (compiler_log);
    }
}

char* readFile(const char* _file, int* lenght){
    std::ifstream file;
    file.open(_file, std::ios::in);
    *lenght = getFileLength(file);

    if(*lenght == 0)
        return new char[1]{' '};
    else{
        char* ShaderSource = new char[*lenght];
        unsigned int i=0;
        while (file.good())
        {
            ShaderSource[i] = file.get();
            i++;
        }
        ShaderSource[i-1] = '\0';
        return ShaderSource;
    }
}

unsigned long getFileLength(std::ifstream& file)
{
    if(!file.good()) 
        return 0;    
    unsigned long pos=file.tellg();
    file.seekg(0,std::ios::end);
    unsigned long len = file.tellg();
    file.seekg(std::ios::beg);    
    return len;
}