#include "SimpleShader.h"
#include "../ShaderStrategy.h"
#include "../../utils/Shader.h"
#include "../../utils/Mesh.h"
#include <SDL.h>
#include <glew.h>
#include <iostream>

SimpleShader::SimpleShader(Shader* _shader):ShaderStrategy(){
	vertexAttributePosition = glGetAttribLocation(_shader->programShaderId,"vertexPosition");
	if(vertexAttributePosition == -1)
		std::cout << "\033[1;31m[ERROR]:\033[0m" << " vertexAttributePosition was not finded into Shader Object" << std::endl;
}

SimpleShader::~SimpleShader(){

}

void SimpleShader::excecute(Shader* _shader, Mesh* _mesh){
	glUseProgram(_shader->programShaderId);
	glBindVertexArray(_mesh->vertexArrayObject);
	glBindBuffer(GL_ARRAY_BUFFER, _mesh->vertexBuffer);
	glVertexAttribPointer(vertexAttributePosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, _mesh->faceCount);
}