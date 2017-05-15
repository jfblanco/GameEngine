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

	projectionMatrixUniformPosition = glGetUniformLocation(_shader->programShaderId,"projectionMatrix");
	if(projectionMatrixUniformPosition == -1)
		std::cout << "\033[1;31m[ERROR]:\033[0m" << " projectionMatrixUniformPosition was not finded into Shader Object" << std::endl;

	positionMatrix = glGetUniformLocation(_shader->programShaderId,"positionMatrix");
	if(positionMatrix == -1)
		std::cout << "\033[1;31m[ERROR]:\033[0m" << " positionMatrix was not finded into Shader Object" << std::endl;

	this->projectionMatrix.orthoMatrix(0.0f, 800.0f, 0.0f, 600.0f, -100.0f, 100.0f);
}

SimpleShader::~SimpleShader(){

}

void SimpleShader::excecute(Shader* _shader, Mesh* _mesh){
	glUseProgram(_shader->programShaderId);
	glBindVertexArray(_mesh->vertexArrayObject);
	
	glUniformMatrix4fv(projectionMatrixUniformPosition, 1, GL_FALSE, this->projectionMatrix.toFloatPointer());
	glUniformMatrix4fv(positionMatrix, 1, GL_FALSE, _mesh->position.toFloatPointer());
	
	glBindBuffer(GL_ARRAY_BUFFER, _mesh->vertexBuffer);
	glVertexAttribPointer(vertexAttributePosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(vertexAttributePosition);
	
	glBindBuffer(GL_ARRAY_BUFFER, _mesh->indexBuffer);
	//glDrawArrays(GL_TRIANGLE_STRIP, 0, 10);
	glDrawElements(GL_TRIANGLES, _mesh->indexBuffer, GL_UNSIGNED_INT, 0);
}