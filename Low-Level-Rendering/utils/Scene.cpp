#include "Scene.h"
#include "Shader.h"
#include "Mesh.h"
#include "../renderingPipe/ShaderStrategy.h"
#include "../../Core/utils/BufferItem.h"
#include <iostream>

Scene::Scene(){
	shadersCount = 0;
}

Scene::~Scene(){

}

void Scene::addMesh(Mesh* _mesh){
	this->buffer.insert(_mesh);
}

void Scene::addShader(Shader* _shader, ShaderStrategy* _shaderStrategy){
	_shader = buffer.insert(_shader);
	this->shaders[shadersCount] = _shaderStrategy;
	this->shadersIndex[_shader->id] = this->shadersCount;
	shadersCount++;
}

void Scene::renderScene(){
	this->bufferItem = buffer.first();
	while(this->bufferItem != NULL){
		if(bufferItem->type == SHADER){
			this->shaderContextSwitch((Shader*)bufferItem);
		}
		else{
			this->actualShaderStrategy->excecute(this->actualShader, (Mesh*)bufferItem);
		}
		bufferItem = buffer.next();
	}
}

void Scene::shaderContextSwitch(Shader* _shader){
	this->actualShaderStrategy = this->shaders[this->shadersIndex[_shader->id]];
	this->actualShader = _shader;
}
