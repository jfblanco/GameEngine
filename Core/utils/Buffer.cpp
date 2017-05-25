#include "Buffer.h"
#include "Actor.h"
#include "../../Low-Level-Rendering/utils/Mesh.h"
#include "../../Low-Level-Rendering/utils/Material.h"
#include "../../Low-Level-Rendering/utils/Shader.h"
#include "BufferItem.h"
#include <iostream>
#include <cstdint>
#include <cstring>

Buffer::Buffer(){
	lenght = 0;
	currentIndex = 0;
	index[0] = 0;
}
		
Buffer::~Buffer(){

}

BufferItem* Buffer::get(int _index){
	return (BufferItem*) &(buffer[index[_index]]);
}

Actor* Buffer::getActor(int _index){
	return (Actor*) &(buffer[index[_index]]);
}

Actor* Buffer::insert(Actor* _object){	
	int actorSize = sizeof (*_object);
	int memoryLocation = index[lenght];
	int objectLocation = index[lenght];

	std::memcpy(&(buffer[memoryLocation]), _object, actorSize);
	memoryLocation += actorSize;
	
	Actor* auxMesh = (Actor*) &(buffer[objectLocation]);
	lenght++;	
	index[lenght] = memoryLocation;
	delete _object;
	_object = auxMesh;
	_object->id = lenght;
	return _object;
}

BufferItem* Buffer::first(){
	currentIndex = 0;
	if(currentIndex >= lenght)
		return NULL;
	else
		return this->get(currentIndex);
}

BufferItem* Buffer::next(){
	currentIndex++;
	if(currentIndex >= lenght)
		return NULL;
	else
		return this->get(currentIndex);	
}
		
Material* Buffer::getMaterial(int _index){
	return (Material*) &(buffer[index[_index]]);
}

void Buffer::insert(Material* _object){

}

Shader* Buffer::getShader(int _index){
	return (Shader*) &(buffer[index[_index]]);
}

Shader* Buffer::insert(Shader* _object){
	int shaderSize = sizeof (*_object);
	int memoryLocation = index[lenght];
	int objectLocation = index[lenght];

	std::memcpy(&(buffer[memoryLocation]), _object, shaderSize);
	memoryLocation += shaderSize;

	Shader* auxShader = (Shader*) &(buffer[objectLocation]);
	lenght++;	
	index[lenght] = memoryLocation;
	delete _object;
	_object = auxShader;
	_object->id = lenght;
	return _object;
}