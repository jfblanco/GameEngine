#include "MeshFactory.h"
#include "Mesh.h"
#include "../../Core/utils/Vector3.h"
#include <glew.h>

void fillVector(Vector3*,float,int);

MeshFactory::MeshFactory(){

}

MeshFactory::~MeshFactory(){

}

Mesh* MeshFactory::createCube(const char* _tag){
	Mesh* resu = new Mesh();
	resu->tag = _tag;
	resu->type = MESH;
	resu->vertexCount = 8;
	resu->vertexColorCount = 8;
	resu->diffuseVertexColorCount = 8;
	resu->specularVertexColorCount = 8;
	resu->normalCount = 8;
	resu->textureMapCount = 8;
	resu->faceCount = 12;
	resu->vertexs = new Vector3[8];
	resu->vertexColors = new Vector3[8];
	resu->diffuses = new Vector3[8];
	resu->speculars = new Vector3[8];
	resu->normals = new Vector3[8];
	resu->textures = new Vector3[8];
	resu->faces = new unsigned int[36];

	resu->vertexs[0].x(100.0);resu->vertexs[0].y(-100.0);resu->vertexs[0].z(-100.0);
	resu->vertexs[1].x(100.0);resu->vertexs[1].y(-100.0);resu->vertexs[1].z(100.0);
	resu->vertexs[2].x(-100.0);resu->vertexs[2].y(-100.0);resu->vertexs[2].z(100.0);
	resu->vertexs[3].x(-100.0);resu->vertexs[3].y(-100.0);resu->vertexs[3].z(-100.0);
	resu->vertexs[4].x(100.0);resu->vertexs[4].y(100.0);resu->vertexs[4].z(-100.0);
	resu->vertexs[5].x(100.0);resu->vertexs[5].y(100.0);resu->vertexs[5].z(100.0);
	resu->vertexs[6].x(-100.0);resu->vertexs[6].y(100.0);resu->vertexs[6].z(100.0);
	resu->vertexs[7].x(-100.0);resu->vertexs[7].y(100.0);resu->vertexs[7].z(-100.0);

	fillVector(resu->vertexColors, 0.5, 8);
	fillVector(resu->diffuses, 0.5, 8);
	fillVector(resu->speculars, 0.5, 8);
	fillVector(resu->normals, 0.5, 8);
	fillVector(resu->textures, 0.5, 8);

	resu->faces[0] = 2;resu->faces[1] = 4;resu->faces[2] = 1;
	resu->faces[3] = 8;resu->faces[4] = 6;resu->faces[5] = 5;
	resu->faces[6] = 5;resu->faces[7] = 2;resu->faces[8] = 1;
	resu->faces[9] = 6;resu->faces[10] = 3;resu->faces[11] = 2;
	resu->faces[12] = 3;resu->faces[13] = 8;resu->faces[14] = 4;
	resu->faces[15] = 1;resu->faces[16] = 8;resu->faces[17] = 5;
	resu->faces[18] = 2;resu->faces[19] = 3;resu->faces[20] = 4;
	resu->faces[21] = 8;resu->faces[22] = 7;resu->faces[23] = 6;
	resu->faces[24] = 5;resu->faces[25] = 6;resu->faces[26] = 2;
	resu->faces[27] = 6;resu->faces[28] = 7;resu->faces[29] = 3;
	resu->faces[30] = 3;resu->faces[31] = 7;resu->faces[32] = 8;
	resu->faces[33] = 1;resu->faces[34] = 4;resu->faces[35] = 8;

	glCreateVertexArrays(1, &resu->vertexArrayObject);
	glBindVertexArray(resu->vertexArrayObject);

	glGenBuffers(1, &resu->vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float),resu->vertexs, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->vertexColorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->vertexColorBuffer);
	glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float),resu->vertexColors, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->vertexDiffuseBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->vertexDiffuseBuffer);
	glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float),resu->diffuses, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->vertexSpecularBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->vertexSpecularBuffer);
	glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float),resu->speculars, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float),resu->normals, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->textMapBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->textMapBuffer);
	glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float),resu->textures, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, resu->indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 36 * sizeof(unsigned int), resu->faces, GL_STATIC_DRAW);

	return resu;
}
		
Mesh* MeshFactory::createLine(const char*){

}
		
Mesh* MeshFactory::createPlane(const char* _tag){
	Mesh* resu = new Mesh();
	resu->tag = _tag;
	resu->type = MESH;
	resu->vertexCount = 4;
	resu->vertexColorCount = 4;
	resu->diffuseVertexColorCount = 4;
	resu->specularVertexColorCount = 4;
	resu->normalCount = 4;
	resu->textureMapCount = 4;
	resu->faceCount = 2;
	resu->vertexs = new Vector3[4];
	resu->vertexColors = new Vector3[4];
	resu->diffuses = new Vector3[4];
	resu->speculars = new Vector3[4];
	resu->normals = new Vector3[4];
	resu->textures = new Vector3[4];
	resu->faces = new unsigned int[6];

	resu->vertexs[0].x(-100.0);resu->vertexs[0].y(-100.0);resu->vertexs[0].z(0.0);
	resu->vertexs[1].x(100.0);resu->vertexs[1].y(-100.0);resu->vertexs[1].z(0.0);
	resu->vertexs[2].x(-100.0);resu->vertexs[2].y(100.0);resu->vertexs[2].z(0.0);
	resu->vertexs[3].x(100.0);resu->vertexs[3].y(100.0);resu->vertexs[3].z(0.0);

	fillVector(resu->vertexColors, 0.5, 4);
	fillVector(resu->diffuses, 0.5, 4);
	fillVector(resu->speculars, 0.5, 4);
	fillVector(resu->normals, 0.5, 4);
	fillVector(resu->textures, 0.5, 4);

	resu->faces[0] = 1;resu->faces[1] = 2;resu->faces[2] = 0;
	resu->faces[3] = 1;resu->faces[4] = 3;resu->faces[5] = 2;

	glCreateVertexArrays(1, &resu->vertexArrayObject);
	glBindVertexArray(resu->vertexArrayObject);

	glGenBuffers(1, &resu->vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), resu->vertexs, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->vertexColorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->vertexColorBuffer);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), resu->vertexColors, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->vertexDiffuseBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->vertexDiffuseBuffer);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), resu->diffuses, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->vertexSpecularBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->vertexSpecularBuffer);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), resu->speculars, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), resu->normals, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->textMapBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->textMapBuffer);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), resu->textures, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, resu->indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), resu->faces, GL_STATIC_DRAW);

	return resu;
}

Mesh* MeshFactory::createSphere(const char*){

}
		
Mesh* MeshFactory::createTourus(const char*){

}

void fillVector(Vector3* vector, float value, int count){
	for(int i=0;i<count;i++){
		vector[i].x(value);vector[i].y(value);vector[i].z(value);
	}
}