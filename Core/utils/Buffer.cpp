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

Mesh* Buffer::getMesh(int _index){
	return (Mesh*) &(buffer[index[_index]]);
}

void Buffer::insert(Mesh* _object){	
	int meshSize = sizeof (*_object);
	int vertexBufferSize = sizeof(Vector3) * _object->vertexCount;
	int vertexColorBufferSize = sizeof(Vector3) * _object->vertexColorCount;
	int vertexDiffuseBufferSize = sizeof(Vector3) * _object->diffuseVertexColorCount;
	int vertexSpecularBufferSize = sizeof(Vector3) * _object->specularVertexColorCount;
	int normalBufferSize = sizeof(Vector3) * _object->normalCount;
	int facesBufferSize = sizeof(Vector3) * _object->faceCount;
	int textureMapBufferSize = sizeof(Vector3) * _object->textureMapCount;

	int memoryLocation = index[lenght];
	int objectLocation = index[lenght];
	int vertexLocation;
	int vertexColorLocation;
	int vertexDiffuseLocation;
	int vertexSpecularLocation;
	int normalLocation;
	int textureLocation;
	int facesLocation;

	std::memcpy(&(buffer[memoryLocation]), _object, meshSize);
	memoryLocation += meshSize;

	std::memcpy(&(buffer[memoryLocation]), _object->vertexs, vertexBufferSize);
	vertexLocation = memoryLocation;
	memoryLocation += vertexBufferSize;

	std::memcpy(&(buffer[memoryLocation]), _object->vertexColors, vertexColorBufferSize);
	vertexColorLocation = memoryLocation;
	memoryLocation += vertexColorBufferSize;

	std::memcpy(&(buffer[memoryLocation]), _object->diffuses, vertexDiffuseBufferSize);
	vertexDiffuseLocation = memoryLocation;
	memoryLocation += vertexDiffuseBufferSize;

	std::memcpy(&(buffer[memoryLocation]), _object->speculars, vertexSpecularBufferSize);
	vertexSpecularLocation = memoryLocation;
	memoryLocation += vertexSpecularBufferSize;
	
	std::memcpy(&(buffer[memoryLocation]), _object->normals, normalBufferSize);
	normalLocation = memoryLocation;
	memoryLocation += normalBufferSize;
	
	std::memcpy(&(buffer[memoryLocation]), _object->textures, textureMapBufferSize);
	textureLocation = memoryLocation;
	memoryLocation += textureMapBufferSize;
	
	std::memcpy(&(buffer[memoryLocation]), _object->faces, facesBufferSize);
	facesLocation = memoryLocation;
	memoryLocation += facesBufferSize;
	
	lenght++;	
	index[lenght] = memoryLocation;

	Mesh* auxMesh = (Mesh*) &(buffer[objectLocation]);
	auxMesh->vertexs = (Vector3*) &(buffer[vertexLocation]);
	auxMesh->vertexColors = (Vector3*) &(buffer[vertexColorLocation]);
	auxMesh->diffuses = (Vector3*) &(buffer[vertexDiffuseLocation]);
	auxMesh->speculars = (Vector3*) &(buffer[vertexDiffuseLocation]);
	auxMesh->normals = (Vector3*) &(buffer[normalLocation]);
	auxMesh->textures = (Vector3*) &(buffer[textureLocation]);
	auxMesh->faces = (unsigned int*) &(buffer[facesLocation]);

	delete _object;
	_object = auxMesh;
	_object->id = lenght;
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

Actor* Buffer::getActor(int _index){
	return (Actor*) &(buffer[index[_index]]);
}

void Buffer::insert(Actor* _object){

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