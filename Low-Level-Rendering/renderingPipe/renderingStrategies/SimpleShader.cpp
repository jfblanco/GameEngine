#include "SimpleShader.h"
#include "../ShaderStrategy.h"
#include "../../utils/Shader.h"
#include "../../../Core/utils/Actor.h"
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

	modelMatrix = glGetUniformLocation(_shader->programShaderId,"modelMatrix");
	if(modelMatrix == -1)
		std::cout << "\033[1;31m[ERROR]:\033[0m" << " modelMatrix was not finded into Shader Object" << std::endl;

	viewMatrix = glGetUniformLocation(_shader->programShaderId,"viewCustomMatrix");
	if(viewMatrix == -1)
		std::cout << "\033[1;31m[ERROR]:\033[0m" << " viewCustomMatrix was not finded into Shader Object" << std::endl;

	vertexAttributeColor = glGetAttribLocation(_shader->programShaderId,"vertexColor");
	if(vertexAttributeColor == -1)
		std::cout << "\033[1;31m[ERROR]:\033[0m" << " vertexAttributeColor was not finded into Shader Object" << std::endl;

	this->projectionMatrix.perspectiveMatrix(45.0f, 800.0f/600.0f, 0.1f, 2000.0f);
	//this->projectionMatrix.orthoMatrix(0.0f, 800.0f, 0.0f, 600.0f, -100.0f, 100.0f);
	Vector3* position = new Vector3(0.0,0.0,-2.0);
	Vector3* point = new Vector3(0.0,0.0,0.0);
	Vector3* up = new Vector3(0.0,1.0,0.0);
	this->camera.lookAt(*position,*point,*up);
	delete position;
	delete point;
	delete up;
}

SimpleShader::~SimpleShader(){

}

void SimpleShader::excecute(Shader* _shader, Actor* _actor){
	glUseProgram(_shader->programShaderId);
	glBindVertexArray(_actor->vertexArrayObject);
	
	glUniformMatrix4fv(projectionMatrixUniformPosition, 1, GL_FALSE, this->projectionMatrix.toFloatPointer());
	glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, _actor->modelMatrix.toFloatPointer());
	glUniformMatrix4fv(viewMatrix, 1, GL_FALSE, this->camera.getViewMatrixAsPointer());
	
	glBindBuffer(GL_ARRAY_BUFFER, _actor->vertexBuffer);
	glVertexAttribPointer(vertexAttributePosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(vertexAttributePosition);

	glBindBuffer(GL_ARRAY_BUFFER, _actor->vertexColorBuffer);
	glVertexAttribPointer(vertexAttributeColor, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(vertexAttributeColor);
	
	glBindBuffer(GL_ARRAY_BUFFER, _actor->indexBuffer);
	//glDrawArrays(GL_TRIANGLE_STRIP, 0, 12);
	glDrawElements(GL_TRIANGLES, _actor->faceCount, GL_UNSIGNED_INT, 0);
}