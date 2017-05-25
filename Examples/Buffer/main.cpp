#include <iostream>
#include "../../Low-Level-Rendering/utils/Shader.h"
#include "../../Core/utils/Actor.h"
#include "../../Core/utils/Buffer.h"
#include "../../Core/utils/Vector3.h"

void printShaderInfo(BufferItem*);
void printMeshInfo(BufferItem*);

int main(int argc, char** args){
	Actor* actor = new Actor();
	actor->id = 1;
	actor->tag = "first";
	actor->type = ACTOR;
	actor->vertexArrayObject = 1;
	actor->vertexBuffer = 11;
	actor->vertexColorBuffer = 12;
	actor->vertexDiffuseBuffer = 13;
	actor->vertexSpecularBuffer = 14;
	actor->normalBuffer = 15;
	actor->textMapBuffer = 16;
	actor->indexBuffer = 17;
	actor->faceCount = 8;
	
	Actor* actor1 = new Actor();	
	actor1->id = 2;
	actor1->tag = "second";	
	actor1->type = ACTOR;	
	actor1->vertexArrayObject = 2;
	actor1->vertexBuffer = 21;
	actor1->vertexColorBuffer = 22;
	actor1->vertexDiffuseBuffer = 23;
	actor1->vertexSpecularBuffer = 24;
	actor1->normalBuffer = 25;
	actor1->textMapBuffer = 26;
	actor1->indexBuffer = 27;
	actor1->faceCount = 8;	

	Actor* actor2 = new Actor();
	actor2->id = 3;
	actor2->tag = "thirdth";	
	actor2->type = ACTOR;
	actor2->vertexArrayObject = 3;
	actor2->vertexBuffer = 31;
	actor2->vertexColorBuffer = 32;
	actor2->vertexDiffuseBuffer = 33;
	actor2->vertexSpecularBuffer = 34;
	actor2->normalBuffer = 35;
	actor2->textMapBuffer = 36;
	actor2->indexBuffer = 37;
	actor2->faceCount = 8;
	
	Actor* actor3 = new Actor();
	actor3->id = 4;
	actor3->tag = "fourth";	
	actor3->type = ACTOR;
	actor3->vertexArrayObject = 4;
	actor3->vertexBuffer = 41;
	actor3->vertexColorBuffer = 42;
	actor3->vertexDiffuseBuffer = 43;
	actor3->vertexSpecularBuffer = 44;
	actor3->normalBuffer = 45;
	actor3->textMapBuffer = 46;
	actor3->indexBuffer = 47;
	actor3->faceCount = 8;
	
	Actor* actor4 = new Actor();
	actor4->id = 5;
	actor4->tag = "fifth";
	actor4->type = ACTOR;
	actor4->vertexArrayObject = 5;
	actor4->vertexBuffer = 51;
	actor4->vertexColorBuffer = 52;
	actor4->vertexDiffuseBuffer = 53;
	actor4->vertexSpecularBuffer = 54;
	actor4->normalBuffer = 55;
	actor4->textMapBuffer = 56;
	actor4->indexBuffer = 57;
	actor4->faceCount = 8;
	
	Shader* shader1 = new Shader();
	
	shader1->id = 1;
	shader1->tag = "shaderTest";
	shader1->type = SHADER;
	shader1->vertexShaderId = 1;
	shader1->fragmentShaderId = 11;		
	shader1->programShaderId = 111;

	Shader* shader2 = new Shader();

	shader2->id = 2;
	shader2->tag = "crazyShader";
	shader2->type = SHADER;
	shader2->vertexShaderId = 2;
	shader2->fragmentShaderId = 22;		
	shader2->programShaderId = 222;

	Buffer buffer;

	buffer.insert(shader1);
	buffer.insert(actor3);
	buffer.insert(actor2);
	buffer.insert(actor1);
	buffer.insert(shader2);
	buffer.insert(actor);
	buffer.insert(actor4);

	BufferItem* bufferItem;
	
	bufferItem = buffer.first();
	while(bufferItem != NULL){
		if(bufferItem->type == ACTOR)
			printMeshInfo(bufferItem);
		if(bufferItem->type == SHADER)
			printShaderInfo(bufferItem);
		bufferItem = buffer.next();	
	}	
}

void printShaderInfo(BufferItem* _bufferItem){
	Shader* newShader = (Shader*) _bufferItem;

	std::cout << "{SHADER} ID: " << newShader->id << " Tag: " << newShader->tag.toChar() << 
	             " Program: ["  << newShader->programShaderId  << "]" << 
	             " Vertex: ["   << newShader->vertexShaderId   << "]" << 
	             " Fragment: [" << newShader->fragmentShaderId << "]" <<
	std::endl; 
}

void printMeshInfo(BufferItem* _bufferItem){
	Actor* actor = (Actor*) _bufferItem;
	std::cout << "{ACTOR} ID: " << actor->id << 
				 " Tag: " << actor->tag.toChar() << 
				 " VAO: " << actor->vertexArrayObject << 
				 " Vertex Buffer: " << actor->vertexBuffer << 
				 " Vertex Color Buffer: " << actor->vertexColorBuffer << 
				 " Vertex Diffuse Buffer: " << actor->vertexDiffuseBuffer << 
				 " Vertex Specular Buffer: " << actor->vertexSpecularBuffer << 
				 " Normal Buffer: " << actor->normalBuffer << 
				 " Texture UVMap Buffer: " << actor->textMapBuffer << 
				 " Index Buffer: " << actor->indexBuffer << 
				 " Faces: " << actor->faceCount << std::endl;
		
}