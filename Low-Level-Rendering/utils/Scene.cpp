#include "Scene.h"
#include "Shader.h"
#include "Mesh.h"
#include "../renderingPipe/ShaderStrategy.h"
#include "../../Core/utils/BufferItem.h"
#include "../../Core/events/TickEventInterface.h"
#include <iostream>

Scene::Scene(){
	shadersCount = 0;
	ticksCount = 1;
}

Scene::~Scene(){

}

Mesh* Scene::addMesh(Mesh* _mesh){
	return this->buffer.insert(_mesh);
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

void Scene::sendTickEvent(unsigned int _tick){
	this->bufferItem = buffer.first();
	while(this->bufferItem != NULL){
		if(bufferItem->type == MESH && this->tickIndex[this->bufferItem->id] != 0){
			this->tickevents[this->tickIndex[this->bufferItem->id]]->excecute((Mesh*)bufferItem, _tick);
		}
		bufferItem = buffer.next();
	}
}

void Scene::shaderContextSwitch(Shader* _shader){
	this->actualShaderStrategy = this->shaders[this->shadersIndex[_shader->id]];
	this->actualShader = _shader;
}

void Scene::addMeshToTickEventManager(Mesh* _mesh, TickTimeEventInterface* _tickTimeEvent){
	this->tickevents[ticksCount] = _tickTimeEvent;
	this->tickIndex[_mesh->id] = this->ticksCount;
	ticksCount++;
}