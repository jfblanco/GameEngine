#include <iostream>
#include "../../Low-Level-Rendering/utils/Mesh.h"
#include "../../Low-Level-Rendering/utils/Shader.h"
#include "../../Core/utils/Actor.h"
#include "../../Core/utils/Buffer.h"
#include "../../Core/utils/Vector3.h"

void printShaderInfo(BufferItem*);
void printMeshInfo(BufferItem*);

int main(int argc, char** args){
	Mesh* mesh = new Mesh();
	mesh->id = 1;
	mesh->tag = "first";
	mesh->type = MESH;
	mesh->vertexCount = 4;
	mesh->vertexs = new Vector3[4];
	mesh->vertexs[0].x(-1.0);mesh->vertexs[0].y(1.0);mesh->vertexs[0].z(0.0);
	mesh->vertexs[1].x(1.0);mesh->vertexs[1].y(1.0);mesh->vertexs[1].z(0.0);
	mesh->vertexs[2].x(1.0);mesh->vertexs[2].y(-1.0);mesh->vertexs[2].z(0.0);
	mesh->vertexs[3].x(-1.0);mesh->vertexs[3].y(-1.0);mesh->vertexs[3].z(0.0);

	Mesh* mesh1 = new Mesh();	
	mesh1->id = 2;
	mesh1->tag = "second";	
	mesh1->type = MESH;	
	mesh1->vertexCount = 4;
	mesh1->vertexs = new Vector3[4];
	mesh1->vertexs[0].x(-1.0);mesh1->vertexs[0].y(1.0);mesh1->vertexs[0].z(0.0);
	mesh1->vertexs[1].x(1.0);mesh1->vertexs[1].y(1.0);mesh1->vertexs[1].z(0.0);
	mesh1->vertexs[2].x(1.0);mesh1->vertexs[2].y(-1.0);mesh1->vertexs[2].z(0.0);
	mesh1->vertexs[3].x(-1.0);mesh1->vertexs[3].y(-1.0);mesh1->vertexs[3].z(0.0);

	Mesh* mesh2 = new Mesh();
	mesh2->id = 3;
	mesh2->tag = "thirdth";	
	mesh2->type = MESH;
	mesh2->vertexCount = 4;	
	mesh2->vertexs = new Vector3[4];
	mesh2->vertexs[0].x(-1.0);mesh2->vertexs[0].y(1.0);mesh2->vertexs[0].z(0.0);
	mesh2->vertexs[1].x(1.0);mesh2->vertexs[1].y(1.0);mesh2->vertexs[1].z(0.0);
	mesh2->vertexs[2].x(1.0);mesh2->vertexs[2].y(-1.0);mesh2->vertexs[2].z(0.0);
	mesh2->vertexs[3].x(-1.0);mesh2->vertexs[3].y(-1.0);mesh2->vertexs[3].z(0.0);

	Mesh* mesh3 = new Mesh();
	mesh3->id = 4;
	mesh3->tag = "fourth";	
	mesh3->type = MESH;
	mesh3->vertexCount = 4;
	mesh3->vertexs = new Vector3[4];
	mesh3->vertexs[0].x(-1.0);mesh3->vertexs[0].y(1.0);mesh3->vertexs[0].z(0.0);
	mesh3->vertexs[1].x(1.0);mesh3->vertexs[1].y(1.0);mesh3->vertexs[1].z(0.0);
	mesh3->vertexs[2].x(1.0);mesh3->vertexs[2].y(-1.0);mesh3->vertexs[2].z(0.0);
	mesh3->vertexs[3].x(-1.0);mesh3->vertexs[3].y(-1.0);mesh3->vertexs[3].z(0.0);

	Mesh* mesh4 = new Mesh();
	mesh4->id = 5;
	mesh4->tag = "fifth";
	mesh4->type = MESH;
	mesh4->vertexCount = 10;
	mesh4->vertexs = new Vector3[10];	
	mesh4->vertexs[0].x(1.0);mesh4->vertexs[0].y(11.0);mesh4->vertexs[0].z(111.0);
	mesh4->vertexs[1].x(2.0);mesh4->vertexs[1].y(22.0);mesh4->vertexs[1].z(222.0);
	mesh4->vertexs[2].x(3.0);mesh4->vertexs[2].y(-33.0);mesh4->vertexs[2].z(333.0);
	mesh4->vertexs[3].x(-4.0);mesh4->vertexs[3].y(-44.0);mesh4->vertexs[3].z(444.0);
	mesh4->vertexs[4].x(-5.0);mesh4->vertexs[4].y(55.0);mesh4->vertexs[4].z(555.0);
	mesh4->vertexs[5].x(6.0);mesh4->vertexs[5].y(66.0);mesh4->vertexs[5].z(666.0);
	mesh4->vertexs[6].x(7.0);mesh4->vertexs[6].y(-77.0);mesh4->vertexs[6].z(777.0);
	mesh4->vertexs[7].x(-8.0);mesh4->vertexs[7].y(-88.0);mesh4->vertexs[7].z(888.0);	
	mesh4->vertexs[8].x(9.0);mesh4->vertexs[8].y(-99.0);mesh4->vertexs[8].z(999.0);
	mesh4->vertexs[9].x(-10.0);mesh4->vertexs[9].y(-100.0);mesh4->vertexs[9].z(1000.0);

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
	buffer.insert(shader2);
	buffer.insert(mesh3);
	buffer.insert(mesh2);
	buffer.insert(mesh1);
	buffer.insert(mesh);
	buffer.insert(mesh4);

	BufferItem* bufferItem;
	
	bufferItem = buffer.first();
	while(bufferItem != NULL){
		if(bufferItem->type == MESH)
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
	Mesh* newMesh = (Mesh*) _bufferItem;
	
	if(newMesh->id == 5)
		std::cout << "{MESH} ID: " << newMesh->id << " Tag: " << newMesh->tag.toChar() << "    V0[" << newMesh->vertexs[0].x() << "," << newMesh->vertexs[0].y() << "," << newMesh->vertexs[0].z() << "]" 
		                                                                            << " V1[" << newMesh->vertexs[1].x() << "," << newMesh->vertexs[1].y() << "," << newMesh->vertexs[1].z() << "]" 
		                                                                            << " V2[" << newMesh->vertexs[2].x() << "," << newMesh->vertexs[2].y() << "," << newMesh->vertexs[2].z() << "]"
		                                                                            << " V3[" << newMesh->vertexs[3].x() << "," << newMesh->vertexs[3].y() << "," << newMesh->vertexs[3].z() << "]"
		                                                                            << " V4[" << newMesh->vertexs[4].x() << "," << newMesh->vertexs[4].y() << "," << newMesh->vertexs[4].z() << "]"
		                                                                            << " V5[" << newMesh->vertexs[5].x() << "," << newMesh->vertexs[5].y() << "," << newMesh->vertexs[5].z() << "]"
		                                                                            << " V6[" << newMesh->vertexs[6].x() << "," << newMesh->vertexs[6].y() << "," << newMesh->vertexs[6].z() << "]"
		                                                                            << " V7[" << newMesh->vertexs[7].x() << "," << newMesh->vertexs[7].y() << "," << newMesh->vertexs[7].z() << "]" 
		                                                                            << " V8[" << newMesh->vertexs[8].x() << "," << newMesh->vertexs[8].y() << "," << newMesh->vertexs[8].z() << "]"
		                                                                            << " V9[" << newMesh->vertexs[9].x() << "," << newMesh->vertexs[9].y() << "," << newMesh->vertexs[9].z() << "]" << std::endl;
	else
		std::cout << "{MESH} ID: " << newMesh->id << " Tag: " << newMesh->tag.toChar() << "    V0[" << newMesh->vertexs[0].x() << "," << newMesh->vertexs[0].y() << "," << newMesh->vertexs[0].z() << "]" << " V1[" << newMesh->vertexs[1].x() << "," << newMesh->vertexs[1].y() << "," << newMesh->vertexs[1].z() << "]" << " V2[" << newMesh->vertexs[2].x() << "," << newMesh->vertexs[2].y() << "," << newMesh->vertexs[2].z() << "]" << "V3[" << newMesh->vertexs[3].x() << "," << newMesh->vertexs[3].y() << "," << newMesh->vertexs[3].z() << "]" << std::endl;
		
}