#include "MeshFactory.h"
#include "Mesh.h"
#include "../../Core/utils/Vector3.h"
#include "../../Core/utils/Actor.h"
#include <glew.h>
#include <iostream>

void fillVector(Vector3*,float,int);

MeshFactory::MeshFactory(){	
	this->cube = this->createCube();
	this->line = this->createLine();
	this->plane = this->createPlane();
	this->sphere = this->createSphere();
	this->tourus = this->createTourus();
}

MeshFactory::~MeshFactory(){

}

Mesh* MeshFactory::createCube(){
	Mesh* resu = new Mesh();
	resu->vertexCount = 8;
	resu->vertexColorCount = 8;
	resu->diffuseVertexColorCount = 8;
	resu->specularVertexColorCount = 8;
	resu->normalCount = 8;
	resu->textureMapCount = 8;
	resu->faceCount = 36;
	resu->vertexs = new Vector3[8];
	resu->vertexColors = new Vector3[8];
	resu->diffuses = new Vector3[8];
	resu->speculars = new Vector3[8];
	resu->normals = new Vector3[8];
	resu->textures = new Vector3[8];
	resu->faces = new unsigned int[36];

	resu->vertexs[0].x(100.0);resu->vertexs[0].y(100.0);resu->vertexs[0].z(-100.0);
	resu->vertexs[1].x(100.0);resu->vertexs[1].y(-100.0);resu->vertexs[1].z(-100.0);
	resu->vertexs[2].x(-100.0);resu->vertexs[2].y(-100.0);resu->vertexs[2].z(-100.0);
	resu->vertexs[3].x(-100.0);resu->vertexs[3].y(100.0);resu->vertexs[3].z(-100.0);
	resu->vertexs[4].x(100.0);resu->vertexs[4].y(100.0);resu->vertexs[4].z(100.0);
	resu->vertexs[5].x(100.0);resu->vertexs[5].y(-100.0);resu->vertexs[5].z(100.0);
	resu->vertexs[6].x(-100.0);resu->vertexs[6].y(-100.0);resu->vertexs[6].z(100.0);
	resu->vertexs[7].x(-100.0);resu->vertexs[7].y(100.0);resu->vertexs[7].z(100.0);

	resu->vertexColors[0].x(1.0);resu->vertexColors[0].y(0.0);resu->vertexColors[0].z(0.0);
	resu->vertexColors[1].x(0.0);resu->vertexColors[1].y(1.0);resu->vertexColors[1].z(0.0);
	resu->vertexColors[2].x(0.0);resu->vertexColors[2].y(0.0);resu->vertexColors[2].z(1.0);
	resu->vertexColors[3].x(0.7);resu->vertexColors[3].y(0.0);resu->vertexColors[3].z(0.0);
	resu->vertexColors[4].x(0.0);resu->vertexColors[4].y(7.0);resu->vertexColors[4].z(0.0);
	resu->vertexColors[5].x(0.0);resu->vertexColors[5].y(0.0);resu->vertexColors[5].z(7.0);
	resu->vertexColors[6].x(0.4);resu->vertexColors[6].y(0.0);resu->vertexColors[6].z(0.0);
	resu->vertexColors[7].x(0.0);resu->vertexColors[7].y(0.4);resu->vertexColors[7].z(0.0);

	fillVector(resu->diffuses, 0.5, 8);
	fillVector(resu->speculars, 0.5, 8);
	fillVector(resu->normals, 0.5, 8);
	fillVector(resu->textures, 0.5, 8);

	resu->faces[0] = 1;resu->faces[1] = 3;resu->faces[2] = 0;
	resu->faces[3] = 7;resu->faces[4] = 5;resu->faces[5] = 4;
	resu->faces[6] = 4;resu->faces[7] = 1;resu->faces[8] = 0;
	resu->faces[9] = 5;resu->faces[10] = 2;resu->faces[11] = 1;
	resu->faces[12] = 2;resu->faces[13] = 7;resu->faces[14] = 3;
	resu->faces[15] = 0;resu->faces[16] = 7;resu->faces[17] = 4;
	resu->faces[18] = 1;resu->faces[19] = 2;resu->faces[20] = 3;
	resu->faces[21] = 7;resu->faces[22] = 6;resu->faces[23] = 5;
	resu->faces[24] = 4;resu->faces[25] = 5;resu->faces[26] = 1;
	resu->faces[27] = 5;resu->faces[28] = 6;resu->faces[29] = 2;
	resu->faces[30] = 2;resu->faces[31] = 6;resu->faces[32] = 7;
	resu->faces[33] = 0;resu->faces[34] = 3;resu->faces[35] = 7;

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
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 12 * 3 * sizeof(unsigned int), resu->faces, GL_STATIC_DRAW);

	return resu;
}
		
Mesh* MeshFactory::createLine(){

}
		
Mesh* MeshFactory::createPlane(){
	Mesh* resu = new Mesh();
	resu->vertexCount = 4;
	resu->vertexColorCount = 4;
	resu->diffuseVertexColorCount = 4;
	resu->specularVertexColorCount = 4;
	resu->normalCount = 4;
	resu->textureMapCount = 4;
	resu->faceCount = 6;
	resu->vertexs = new Vector3[4];
	resu->vertexColors = new Vector3[4];
	resu->diffuses = new Vector3[4];
	resu->speculars = new Vector3[4];
	resu->normals = new Vector3[4];
	resu->textures = new Vector3[4];
	resu->faces = new unsigned int[2];

	resu->vertexs[0].x(-100.0);resu->vertexs[0].y(-100.0);resu->vertexs[0].z(0.0);
	resu->vertexs[1].x(100.0);resu->vertexs[1].y(-100.0);resu->vertexs[1].z(0.0);
	resu->vertexs[2].x(-100.0);resu->vertexs[2].y(100.0);resu->vertexs[2].z(0.0);
	resu->vertexs[3].x(100.0);resu->vertexs[3].y(100.0);resu->vertexs[3].z(0.0);

	resu->vertexColors[0].x(1.0);resu->vertexColors[0].y(0.0);resu->vertexColors[0].z(0.0);
	resu->vertexColors[1].x(0.0);resu->vertexColors[1].y(1.0);resu->vertexColors[1].z(0.0);
	resu->vertexColors[2].x(0.0);resu->vertexColors[2].y(0.0);resu->vertexColors[2].z(1.0);
	resu->vertexColors[3].x(1.0);resu->vertexColors[3].y(1.0);resu->vertexColors[3].z(1.0);

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
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 2 * 3 * sizeof(unsigned int), resu->faces, GL_STATIC_DRAW);

	return resu;
}

Mesh* MeshFactory::createSphere(){
	Mesh* resu = new Mesh();
	resu->vertexCount = 42;
	resu->vertexColorCount = 42;
	resu->diffuseVertexColorCount = 42;
	resu->specularVertexColorCount = 42;
	resu->normalCount = 42;
	resu->textureMapCount = 42;
	resu->faceCount = 240;
	resu->vertexs = new Vector3[42];
	resu->vertexColors = new Vector3[42];
	resu->diffuses = new Vector3[42];
	resu->speculars = new Vector3[42];
	resu->normals = new Vector3[42];
	resu->textures = new Vector3[42];
	resu->faces = new unsigned int[240];

	resu->vertexs[0].x(0.0);resu->vertexs[0].y(0.0);resu->vertexs[0].z(-100.0);
	resu->vertexs[1].x(72.3607);resu->vertexs[1].y(-52.5725);resu->vertexs[1].z(-44.7220);
	resu->vertexs[2].x(-27.6388);resu->vertexs[2].y(-85.0649);resu->vertexs[2].z(-44.7220);
	resu->vertexs[3].x(-89.4426);resu->vertexs[3].y(0.0);resu->vertexs[3].z(-44.7216);
	resu->vertexs[4].x(-27.6388);resu->vertexs[4].y(85.0649);resu->vertexs[4].z(-44.7220);
	resu->vertexs[5].x(72.3607);resu->vertexs[5].y(52.5725);resu->vertexs[5].z(-44.7220);
	resu->vertexs[6].x(27.6388);resu->vertexs[6].y(-85.0649);resu->vertexs[6].z(44.7220);
	resu->vertexs[7].x(-72.3607);resu->vertexs[7].y(-52.5725);resu->vertexs[7].z(44.7220);
	resu->vertexs[8].x(-72.3607);resu->vertexs[8].y(52.5725);resu->vertexs[8].z(44.7220);
	resu->vertexs[9].x(27.6388);resu->vertexs[9].y(85.0649);resu->vertexs[9].z(44.7220);
	resu->vertexs[10].x(89.4426);resu->vertexs[10].y(0.0);resu->vertexs[10].z(44.7216);
	resu->vertexs[11].x(0.0);resu->vertexs[11].y(0.0);resu->vertexs[11].z(100.0);
	resu->vertexs[12].x(-16.2456);resu->vertexs[12].y(-49.9995);resu->vertexs[12].z(-85.0654);
	resu->vertexs[13].x(42.5323);resu->vertexs[13].y(-30.9011);resu->vertexs[13].z(-85.0654);
	resu->vertexs[14].x(26.2869);resu->vertexs[14].y(-80.9012);resu->vertexs[14].z(-52.5738);
	resu->vertexs[15].x(85.0648);resu->vertexs[15].y(0.000000);resu->vertexs[15].z(-52.5736);
	resu->vertexs[16].x(42.5323);resu->vertexs[16].y(30.9011);resu->vertexs[16].z(-85.0654);
	resu->vertexs[17].x(-52.5730);resu->vertexs[17].y(0.000000);resu->vertexs[17].z(-85.0652);
	resu->vertexs[18].x(-68.8189);resu->vertexs[18].y(-49.9997);resu->vertexs[18].z(-52.5736);
	resu->vertexs[19].x(-16.2456);resu->vertexs[19].y(49.9995);resu->vertexs[19].z(-85.0654);
	resu->vertexs[20].x(-68.8189);resu->vertexs[20].y(49.9997);resu->vertexs[20].z(-52.5736);
	resu->vertexs[21].x(26.2869);resu->vertexs[21].y(80.9012);resu->vertexs[21].z(-52.5738);
	resu->vertexs[22].x(95.1058);resu->vertexs[22].y(-30.9013);resu->vertexs[22].z(0.000000);
	resu->vertexs[23].x(95.1058);resu->vertexs[23].y(30.9013);resu->vertexs[23].z(0.000000);
	resu->vertexs[24].x(0.000000);resu->vertexs[24].y(-100.000000);resu->vertexs[24].z(0.000000);
	resu->vertexs[25].x(58.7786);resu->vertexs[25].y(-80.9017);resu->vertexs[25].z(0.000000);
	resu->vertexs[26].x(-95.1058);resu->vertexs[26].y(-30.9013);resu->vertexs[26].z(0.000000);
	resu->vertexs[27].x(-58.7786);resu->vertexs[27].y(-80.9017);resu->vertexs[27].z(0.000000);
	resu->vertexs[28].x(-58.7786);resu->vertexs[28].y(80.9017);resu->vertexs[28].z(0.000000);
	resu->vertexs[29].x(-95.1058);resu->vertexs[29].y(30.9013);resu->vertexs[29].z(0.000000);
	resu->vertexs[30].x(58.7786);resu->vertexs[30].y(80.9017);resu->vertexs[30].z(0.000000);
	resu->vertexs[31].x(0.000000);resu->vertexs[31].y(100.000000);resu->vertexs[31].z(0.000000);
	resu->vertexs[32].x(68.8189);resu->vertexs[32].y(-49.9997);resu->vertexs[32].z(52.5736);
	resu->vertexs[33].x(-26.2869);resu->vertexs[33].y(-80.9012);resu->vertexs[33].z(52.5738);
	resu->vertexs[34].x(-85.0648);resu->vertexs[34].y(0.000000);resu->vertexs[34].z(52.5736);
	resu->vertexs[35].x(-26.2869);resu->vertexs[35].y(80.9012);resu->vertexs[35].z(52.5738);
	resu->vertexs[36].x(68.8189);resu->vertexs[36].y(49.9997);resu->vertexs[36].z(52.5736);
	resu->vertexs[37].x(16.2456);resu->vertexs[37].y(-49.9995);resu->vertexs[37].z(85.0654);
	resu->vertexs[38].x(52.5730);resu->vertexs[38].y(0.000000);resu->vertexs[38].z(85.0652);
	resu->vertexs[39].x(-42.5323);resu->vertexs[39].y(-30.9011);resu->vertexs[39].z(85.0654);
	resu->vertexs[40].x(-42.5323);resu->vertexs[40].y(30.9011);resu->vertexs[40].z(85.0654);
	resu->vertexs[41].x(16.2456);resu->vertexs[41].y(49.9995);resu->vertexs[41].z(85.0654);
	
	fillVector(resu->vertexColors, 1.0, 42);

	resu->vertexColors[0].x(1.0);resu->vertexColors[0].y(0.0);resu->vertexColors[0].z(0.0);
	resu->vertexColors[1].x(1.0);resu->vertexColors[1].y(0.0);resu->vertexColors[1].z(0.0);
	resu->vertexColors[2].x(1.0);resu->vertexColors[2].y(0.0);resu->vertexColors[2].z(0.0);
	resu->vertexColors[3].x(1.0);resu->vertexColors[3].y(0.0);resu->vertexColors[3].z(0.0);
	resu->vertexColors[4].x(1.0);resu->vertexColors[4].y(0.0);resu->vertexColors[4].z(0.0);

	fillVector(resu->diffuses, 1.0, 42);
	fillVector(resu->speculars, 1.0, 42);
	fillVector(resu->normals, 1.0, 42);
	fillVector(resu->textures, 1.0, 42);

	resu->faces[0] = 0;resu->faces[1] = 13;resu->faces[2] = 12;
	resu->faces[3] = 1;resu->faces[4] = 13;resu->faces[5] = 15;
	resu->faces[6] = 0;resu->faces[7] = 12;resu->faces[8] = 17;
	resu->faces[9] = 0;resu->faces[10] = 17;resu->faces[11] = 19;
	resu->faces[12] = 0;resu->faces[13] = 19;resu->faces[14] = 16;
	resu->faces[15] = 1;resu->faces[16] = 15;resu->faces[17] = 22;
	resu->faces[18] = 2;resu->faces[19] = 14;resu->faces[20] = 24;
	resu->faces[21] = 3;resu->faces[22] = 18;resu->faces[23] = 26;
	resu->faces[24] = 4;resu->faces[25] = 20;resu->faces[26] = 28;
	resu->faces[27] = 5;resu->faces[28] = 21;resu->faces[29] = 30;
	resu->faces[30] = 1;resu->faces[31] = 22;resu->faces[32] = 25;
	resu->faces[33] = 2;resu->faces[34] = 24;resu->faces[35] = 27;
	resu->faces[36] = 3;resu->faces[37] = 26;resu->faces[38] = 29;
	resu->faces[39] = 4;resu->faces[40] = 28;resu->faces[41] = 31;
	resu->faces[42] = 5;resu->faces[43] = 30;resu->faces[44] = 23;
	resu->faces[45] = 6;resu->faces[46] = 32;resu->faces[47] = 37;
	resu->faces[48] = 7;resu->faces[49] = 33;resu->faces[50] = 39;
	resu->faces[51] = 8;resu->faces[52] = 34;resu->faces[53] = 40;
	resu->faces[54] = 9;resu->faces[55] = 35;resu->faces[56] = 41;
	resu->faces[57] = 10;resu->faces[58] = 36;resu->faces[59] = 38;
	resu->faces[60] = 38;resu->faces[61] = 41;resu->faces[62] = 11;
	resu->faces[63] = 38;resu->faces[64] = 36;resu->faces[65] = 41;
	resu->faces[66] = 36;resu->faces[67] = 9;resu->faces[68] = 41;
	resu->faces[69] = 41;resu->faces[70] = 40;resu->faces[71] = 11;
	resu->faces[72] = 41;resu->faces[73] = 35;resu->faces[74] = 40;
	resu->faces[75] = 35;resu->faces[76] = 8;resu->faces[77] = 40;
	resu->faces[78] = 40;resu->faces[79] = 39;resu->faces[80] = 11;
	resu->faces[81] = 40;resu->faces[82] = 34;resu->faces[83] = 39;
	resu->faces[84] = 34;resu->faces[85] = 7;resu->faces[86] = 39;
	resu->faces[87] = 39;resu->faces[88] = 37;resu->faces[89] = 11;
	resu->faces[90] = 39;resu->faces[91] = 33;resu->faces[92] = 37;
	resu->faces[93] = 33;resu->faces[94] = 6;resu->faces[95] = 37;
	resu->faces[96] = 37;resu->faces[97] = 38;resu->faces[98] = 11;
	resu->faces[99] = 37;resu->faces[100] = 32;resu->faces[101] = 38;
	resu->faces[102] = 32;resu->faces[103] = 10;resu->faces[104] = 38;
	resu->faces[105] = 23;resu->faces[106] = 36;resu->faces[107] = 10;
	resu->faces[108] = 23;resu->faces[109] = 30;resu->faces[110] = 36;
	resu->faces[111] = 30;resu->faces[112] = 9;resu->faces[113] = 36;
	resu->faces[114] = 31;resu->faces[115] = 35;resu->faces[116] = 9;
	resu->faces[117] = 31;resu->faces[118] = 28;resu->faces[119] = 35;
	resu->faces[120] = 28;resu->faces[121] = 8;resu->faces[122] = 35;
	resu->faces[123] = 29;resu->faces[124] = 34;resu->faces[125] = 8;
	resu->faces[126] = 29;resu->faces[127] = 26;resu->faces[128] = 34;
	resu->faces[129] = 26;resu->faces[130] = 7;resu->faces[131] = 34;
	resu->faces[132] = 27;resu->faces[133] = 33;resu->faces[134] = 7;
	resu->faces[135] = 27;resu->faces[136] = 24;resu->faces[137] = 33;
	resu->faces[138] = 24;resu->faces[139] = 6;resu->faces[140] = 33;
	resu->faces[141] = 25;resu->faces[142] = 32;resu->faces[143] = 6;
	resu->faces[144] = 25;resu->faces[145] = 22;resu->faces[146] = 32;
	resu->faces[147] = 22;resu->faces[148] = 10;resu->faces[149] = 32;
	resu->faces[150] = 30;resu->faces[151] = 31;resu->faces[152] = 9;
	resu->faces[153] = 30;resu->faces[154] = 21;resu->faces[155] = 31;
	resu->faces[156] = 21;resu->faces[157] = 4;resu->faces[158] = 31;
	resu->faces[159] = 28;resu->faces[160] = 29;resu->faces[161] = 8;
	resu->faces[162] = 28;resu->faces[163] = 20;resu->faces[164] = 29;
	resu->faces[165] = 20;resu->faces[166] = 3;resu->faces[167] = 29;
	resu->faces[168] = 26;resu->faces[169] = 27;resu->faces[170] = 7;
	resu->faces[171] = 26;resu->faces[172] = 18;resu->faces[173] = 27;
	resu->faces[174] = 18;resu->faces[175] = 2;resu->faces[176] = 27;
	resu->faces[177] = 24;resu->faces[178] = 25;resu->faces[179] = 6;
	resu->faces[180] = 24;resu->faces[181] = 14;resu->faces[182] = 25;
	resu->faces[183] = 14;resu->faces[184] = 1;resu->faces[185] = 25;
	resu->faces[186] = 22;resu->faces[187] = 23;resu->faces[188] = 10;
	resu->faces[189] = 22;resu->faces[190] = 15;resu->faces[191] = 23;
	resu->faces[192] = 15;resu->faces[193] = 5;resu->faces[194] = 23;
	resu->faces[195] = 16;resu->faces[196] = 21;resu->faces[197] = 5;
	resu->faces[198] = 16;resu->faces[199] = 19;resu->faces[200] = 21;
	resu->faces[201] = 19;resu->faces[202] = 4;resu->faces[203] = 21;
	resu->faces[204] = 19;resu->faces[205] = 20;resu->faces[206] = 4;
	resu->faces[207] = 19;resu->faces[208] = 17;resu->faces[209] = 20;
	resu->faces[210] = 17;resu->faces[211] = 3;resu->faces[212] = 20;
	resu->faces[213] = 17;resu->faces[214] = 18;resu->faces[215] = 3;
	resu->faces[216] = 17;resu->faces[217] = 12;resu->faces[218] = 18;
	resu->faces[219] = 12;resu->faces[220] = 2;resu->faces[221] = 18;
	resu->faces[222] = 15;resu->faces[223] = 16;resu->faces[224] = 5;
	resu->faces[225] = 15;resu->faces[226] = 13;resu->faces[227] = 16;
	resu->faces[228] = 13;resu->faces[229] = 0;resu->faces[230] = 16;
	resu->faces[231] = 12;resu->faces[232] = 14;resu->faces[233] = 2;
	resu->faces[234] = 12;resu->faces[235] = 13;resu->faces[236] = 14;
	resu->faces[237] = 13;resu->faces[238] = 1;resu->faces[239] = 14;	

	glCreateVertexArrays(1, &resu->vertexArrayObject);
	glBindVertexArray(resu->vertexArrayObject);

	glGenBuffers(1, &resu->vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, 42 * 3 * sizeof(float), resu->vertexs, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->vertexColorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->vertexColorBuffer);
	glBufferData(GL_ARRAY_BUFFER, 42 * 3 * sizeof(float), resu->vertexColors, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->vertexDiffuseBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->vertexDiffuseBuffer);
	glBufferData(GL_ARRAY_BUFFER, 42 * 3 * sizeof(float), resu->diffuses, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->vertexSpecularBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->vertexSpecularBuffer);
	glBufferData(GL_ARRAY_BUFFER, 42 * 3 * sizeof(float), resu->speculars, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, 42 * 3 * sizeof(float), resu->normals, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->textMapBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->textMapBuffer);
	glBufferData(GL_ARRAY_BUFFER, 42 * 3 * sizeof(float), resu->textures, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, resu->indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 240 * sizeof(unsigned int), resu->faces, GL_STATIC_DRAW);

	return resu;
}
		
Mesh* MeshFactory::createTourus(){

}

void fillVector(Vector3* vector, float value, int count){
	for(int i=0;i<count;i++){
		vector[i].x(value);vector[i].y(value);vector[i].z(value);
	}
}


Actor* MeshFactory::createCube(const char* _tag){
	Actor* resu = new Actor();
	resu->tag = _tag;
	resu->type = ACTOR;
	resu->vertexArrayObject = this->cube->vertexArrayObject;
	resu->vertexBuffer = this->cube->vertexBuffer;
	resu->vertexColorBuffer = this->cube->vertexColorBuffer;
	resu->vertexDiffuseBuffer = this->cube->vertexDiffuseBuffer;
	resu->vertexSpecularBuffer = this->cube->vertexSpecularBuffer;
	resu->normalBuffer = this->cube->normalBuffer;
	resu->textMapBuffer = this->cube->textMapBuffer;
	resu->indexBuffer = this->cube->indexBuffer;
	resu->faceCount = this->cube->faceCount;
	resu->mesh = this->cube;
	return resu;
}

Actor* MeshFactory::createLine(const char* _tag){
	Actor* resu = new Actor();
	resu->tag = _tag;
	resu->type = ACTOR;
	resu->vertexArrayObject = this->line->vertexArrayObject;
	resu->vertexBuffer = this->line->vertexBuffer;
	resu->vertexColorBuffer = this->line->vertexColorBuffer;
	resu->vertexDiffuseBuffer = this->line->vertexDiffuseBuffer;
	resu->vertexSpecularBuffer = this->line->vertexSpecularBuffer;
	resu->normalBuffer = this->line->normalBuffer;
	resu->textMapBuffer = this->line->textMapBuffer;
	resu->indexBuffer = this->line->indexBuffer;
	resu->faceCount = this->line->faceCount;
	resu->mesh = this->line;
	return resu;
}

Actor* MeshFactory::createPlane(const char* _tag){
	Actor* resu = new Actor();
	resu->tag = _tag;
	resu->type = ACTOR;
	resu->vertexArrayObject = this->plane->vertexArrayObject;
	resu->vertexBuffer = this->plane->vertexBuffer;
	resu->vertexColorBuffer = this->plane->vertexColorBuffer;
	resu->vertexDiffuseBuffer = this->plane->vertexDiffuseBuffer;
	resu->vertexSpecularBuffer = this->plane->vertexSpecularBuffer;
	resu->normalBuffer = this->plane->normalBuffer;
	resu->textMapBuffer = this->plane->textMapBuffer;
	resu->indexBuffer = this->plane->indexBuffer;
	resu->faceCount = this->plane->faceCount;
	resu->mesh = this->plane;
	return resu;
}

Actor* MeshFactory::createSphere(const char* _tag){
	Actor* resu = new Actor();
	resu->tag = _tag;
	resu->type = ACTOR;
	resu->vertexArrayObject = this->sphere->vertexArrayObject;
	resu->vertexBuffer = this->sphere->vertexBuffer;
	resu->vertexColorBuffer = this->sphere->vertexColorBuffer;
	resu->vertexDiffuseBuffer = this->sphere->vertexDiffuseBuffer;
	resu->vertexSpecularBuffer = this->sphere->vertexSpecularBuffer;
	resu->normalBuffer = this->sphere->normalBuffer;
	resu->textMapBuffer = this->sphere->textMapBuffer;
	resu->indexBuffer = this->sphere->indexBuffer;
	resu->faceCount = this->sphere->faceCount;
	resu->mesh = this->sphere;
	return resu;
}

Actor* MeshFactory::createTourus(const char* _tag){
	Actor* resu = new Actor();
	resu->tag = _tag;
	resu->type = MESH;
	resu->vertexArrayObject = this->tourus->vertexArrayObject;
	resu->vertexBuffer = this->tourus->vertexBuffer;
	resu->vertexColorBuffer = this->tourus->vertexColorBuffer;
	resu->vertexDiffuseBuffer = this->tourus->vertexDiffuseBuffer;
	resu->vertexSpecularBuffer = this->tourus->vertexSpecularBuffer;
	resu->normalBuffer = this->tourus->normalBuffer;
	resu->textMapBuffer = this->tourus->textMapBuffer;
	resu->indexBuffer = this->tourus->indexBuffer;
	resu->faceCount = this->tourus->faceCount;
	resu->mesh = this->tourus;
	return resu;
}