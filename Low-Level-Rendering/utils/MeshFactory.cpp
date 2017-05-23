#include "MeshFactory.h"
#include "Mesh.h"
#include "../../Core/utils/Vector3.h"
#include <glew.h>
#include <iostream>

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

	fillVector(resu->vertexColors, 0.5, 8);
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
	resu->faceCount = 6;
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

Mesh* MeshFactory::createSphere(const char* _tag){
	Mesh* resu = new Mesh();
	resu->tag = _tag;
	resu->type = MESH;
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
	resu->faces = new unsigned int[80 * 3];

	0.262869,-0.809012,-0.525738,
	0.850648,0.000000,-0.525736,
	0.425323,0.309011,-0.850654,
	-0.525730,0.000000,-0.850652,
	-0.688189,-0.499997,-0.525736,
	-0.162456,0.499995,-0.850654,
	-0.688189,0.499997,-0.525736,
	0.262869,0.809012,-0.525738,
	0.951058,-0.309013,0.000000,
	0.951058,0.309013,0.000000,
	0.000000,-1.000000,0.000000,
	0.587786,-0.809017,0.000000,
	-0.951058,-0.309013,0.000000,
	-0.587786,-0.809017,0.000000,
	-0.587786,0.809017,0.000000,
	-0.951058,0.309013,0.000000,
	0.587786,0.809017,0.000000,0.000000,1.000000,0.000000,
	0.688189,-0.499997,0.525736,-0.262869,-0.809012,0.525738,-0.850648,0.000000,0.525736,-0.262869,0.809012,0.525738,
	0.688189,0.499997,0.525736,0.162456,-0.499995,0.850654,0.525730,0.000000,0.850652,-0.425323,-0.309011,0.850654,
	-0.425323,0.309011,0.850654,0.162456,0.499995,0.850654

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
	resu->vertexs[11].x(0.0);resu->vertexs[11].y(0.0);resu->vertexs[11].z(1.0);
	resu->vertexs[12].x(-16.2456);resu->vertexs[12].y(-49.9995);resu->vertexs[12].z(-85.0654);
	resu->vertexs[13].x(42.5323);resu->vertexs[13].y(-30.9011);resu->vertexs[13].z(-85.0654);
	resu->vertexs[14].x();resu->vertexs[14].y(100.0);resu->vertexs[14].z(0.0);
	resu->vertexs[15].x();resu->vertexs[15].y(100.0);resu->vertexs[15].z(0.0);
	resu->vertexs[16].x();resu->vertexs[16].y(100.0);resu->vertexs[16].z(0.0);
	resu->vertexs[17].x();resu->vertexs[17].y(100.0);resu->vertexs[17].z(0.0);
	resu->vertexs[18].x();resu->vertexs[18].y(100.0);resu->vertexs[18].z(0.0);
	resu->vertexs[19].x();resu->vertexs[19].y(100.0);resu->vertexs[19].z(0.0);
	resu->vertexs[20].x();resu->vertexs[20].y(-100.0);resu->vertexs[20].z(0.0);
	resu->vertexs[21].x();resu->vertexs[21].y(-100.0);resu->vertexs[21].z(0.0);
	resu->vertexs[22].x();resu->vertexs[22].y(100.0);resu->vertexs[22].z(0.0);
	resu->vertexs[23].x();resu->vertexs[23].y(100.0);resu->vertexs[23].z(0.0);
	resu->vertexs[24].x();resu->vertexs[24].y(100.0);resu->vertexs[24].z(0.0);
	resu->vertexs[25].x();resu->vertexs[25].y(100.0);resu->vertexs[25].z(0.0);
	resu->vertexs[26].x();resu->vertexs[26].y(100.0);resu->vertexs[26].z(0.0);
	resu->vertexs[27].x();resu->vertexs[27].y(100.0);resu->vertexs[27].z(0.0);
	resu->vertexs[28].x();resu->vertexs[28].y(100.0);resu->vertexs[28].z(0.0);
	resu->vertexs[29].x();resu->vertexs[29].y(100.0);resu->vertexs[29].z(0.0);
	resu->vertexs[30].x();resu->vertexs[30].y(-100.0);resu->vertexs[30].z(0.0);
	resu->vertexs[31].x();resu->vertexs[31].y(-100.0);resu->vertexs[31].z(0.0);
	resu->vertexs[32].x();resu->vertexs[32].y(100.0);resu->vertexs[32].z(0.0);
	resu->vertexs[33].x();resu->vertexs[33].y(100.0);resu->vertexs[33].z(0.0);
	resu->vertexs[34].x();resu->vertexs[34].y(100.0);resu->vertexs[34].z(0.0);
	resu->vertexs[35].x();resu->vertexs[35].y(100.0);resu->vertexs[35].z(0.0);
	resu->vertexs[36].x();resu->vertexs[36].y(100.0);resu->vertexs[36].z(0.0);
	resu->vertexs[37].x();resu->vertexs[37].y(100.0);resu->vertexs[37].z(0.0);
	resu->vertexs[38].x();resu->vertexs[38].y(100.0);resu->vertexs[38].z(0.0);
	resu->vertexs[39].x();resu->vertexs[39].y(100.0);resu->vertexs[39].z(0.0);
	resu->vertexs[40].x();resu->vertexs[40].y(-100.0);resu->vertexs[40].z(0.0);
	resu->vertexs[41].x();resu->vertexs[41].y(-100.0);resu->vertexs[41].z(0.0);
	resu->vertexs[42].x();resu->vertexs[42].y(100.0);resu->vertexs[42].z(0.0);
	
	fillVector(resu->vertexColors, 0.5, 42);
	fillVector(resu->diffuses, 0.5, 42);
	fillVector(resu->speculars, 0.5, 42);
	fillVector(resu->normals, 0.5, 42);
	fillVector(resu->textures, 0.5, 42);

	resu->faces[1] = 1;resu->faces[2] = 2;resu->faces[3] = 0;
	resu->faces[4] = 1;resu->faces[5] = 2;resu->faces[6] = 0;
	resu->faces[7] = 1;resu->faces[8] = 2;resu->faces[9] = 0;
	resu->faces[10] = 1;resu->faces[11] = 2;resu->faces[12] = 0;
	resu->faces[13] = 1;resu->faces[14] = 2;resu->faces[15] = 0;
	resu->faces[16] = 1;resu->faces[17] = 2;resu->faces[18] = 0;
	resu->faces[19] = 1;resu->faces[20] = 2;resu->faces[21] = 0;
	resu->faces[22] = 1;resu->faces[23] = 2;resu->faces[24] = 0;
	resu->faces[25] = 1;resu->faces[26] = 2;resu->faces[27] = 0;
	resu->faces[28] = 1;resu->faces[29] = 3;resu->faces[30] = 2;
	resu->faces[31] = 1;resu->faces[32] = 2;resu->faces[33] = 0;
	resu->faces[34] = 1;resu->faces[35] = 2;resu->faces[36] = 0;
	resu->faces[37] = 1;resu->faces[38] = 2;resu->faces[39] = 0;
	resu->faces[40] = 1;resu->faces[41] = 2;resu->faces[42] = 0;
	resu->faces[43] = 1;resu->faces[44] = 2;resu->faces[45] = 0;
	resu->faces[46] = 1;resu->faces[47] = 2;resu->faces[48] = 0;
	resu->faces[49] = 1;resu->faces[50] = 2;resu->faces[51] = 0;
	resu->faces[52] = 1;resu->faces[53] = 2;resu->faces[54] = 0;
	resu->faces[55] = 1;resu->faces[56] = 2;resu->faces[57] = 0;
	resu->faces[58] = 1;resu->faces[59] = 3;resu->faces[60] = 2;
	resu->faces[61] = 1;resu->faces[62] = 2;resu->faces[63] = 0;
	resu->faces[64] = 1;resu->faces[65] = 2;resu->faces[66] = 0;
	resu->faces[67] = 1;resu->faces[68] = 2;resu->faces[69] = 0;
	resu->faces[70] = 1;resu->faces[71] = 2;resu->faces[72] = 0;
	resu->faces[73] = 1;resu->faces[74] = 2;resu->faces[75] = 0;
	resu->faces[76] = 1;resu->faces[77] = 2;resu->faces[78] = 0;
	resu->faces[79] = 1;resu->faces[80] = 2;resu->faces[81] = 0;
	resu->faces[82] = 1;resu->faces[83] = 2;resu->faces[84] = 0;
	resu->faces[85] = 1;resu->faces[86] = 2;resu->faces[87] = 0;
	resu->faces[88] = 1;resu->faces[89] = 3;resu->faces[90] = 2;
	resu->faces[91] = 1;resu->faces[92] = 2;resu->faces[93] = 0;
	resu->faces[94] = 1;resu->faces[95] = 2;resu->faces[96] = 0;
	resu->faces[97] = 1;resu->faces[98] = 2;resu->faces[99] = 0;
	resu->faces[100] = 1;resu->faces[102] = 2;resu->faces[103] = 0;
	resu->faces[104] = 1;resu->faces[105] = 2;resu->faces[106] = 0;
	resu->faces[107] = 1;resu->faces[108] = 2;resu->faces[109] = 0;
	resu->faces[110] = 1;resu->faces[111] = 2;resu->faces[112] = 0;
	resu->faces[113] = 1;resu->faces[114] = 2;resu->faces[115] = 0;
	resu->faces[116] = 1;resu->faces[117] = 2;resu->faces[118] = 0;
	resu->faces[119] = 1;resu->faces[120] = 2;resu->faces[121] = 0;
	resu->faces[122] = 1;resu->faces[123] = 2;resu->faces[124] = 0;
	resu->faces[125] = 1;resu->faces[126] = 2;resu->faces[127] = 0;
	resu->faces[128] = 1;resu->faces[129] = 3;resu->faces[130] = 2;
	resu->faces[131] = 1;resu->faces[132] = 2;resu->faces[133] = 0;
	resu->faces[134] = 1;resu->faces[135] = 2;resu->faces[136] = 0;
	resu->faces[137] = 1;resu->faces[138] = 2;resu->faces[139] = 0;
	resu->faces[140] = 1;resu->faces[141] = 2;resu->faces[142] = 0;
	resu->faces[143] = 1;resu->faces[144] = 2;resu->faces[145] = 0;
	resu->faces[146] = 1;resu->faces[147] = 2;resu->faces[148] = 0;
	resu->faces[149] = 1;resu->faces[150] = 2;resu->faces[151] = 0;
	resu->faces[152] = 1;resu->faces[153] = 2;resu->faces[154] = 0;
	resu->faces[155] = 1;resu->faces[156] = 2;resu->faces[157] = 0;
	resu->faces[158] = 1;resu->faces[159] = 3;resu->faces[160] = 2;
	resu->faces[161] = 1;resu->faces[162] = 2;resu->faces[163] = 0;
	resu->faces[164] = 1;resu->faces[165] = 2;resu->faces[166] = 0;
	resu->faces[167] = 1;resu->faces[168] = 2;resu->faces[169] = 0;
	resu->faces[170] = 1;resu->faces[171] = 2;resu->faces[172] = 0;
	resu->faces[173] = 1;resu->faces[174] = 2;resu->faces[175] = 0;
	resu->faces[176] = 1;resu->faces[177] = 2;resu->faces[178] = 0;
	resu->faces[179] = 1;resu->faces[180] = 2;resu->faces[181] = 0;
	resu->faces[182] = 1;resu->faces[183] = 2;resu->faces[184] = 0;
	resu->faces[185] = 1;resu->faces[186] = 2;resu->faces[187] = 0;
	resu->faces[188] = 1;resu->faces[189] = 3;resu->faces[190] = 2;
	resu->faces[191] = 1;resu->faces[192] = 2;resu->faces[193] = 0;
	resu->faces[194] = 1;resu->faces[195] = 2;resu->faces[196] = 0;
	resu->faces[197] = 1;resu->faces[198] = 2;resu->faces[199] = 0;
	resu->faces[201] = 1;resu->faces[202] = 2;resu->faces[203] = 0;
	resu->faces[204] = 1;resu->faces[205] = 2;resu->faces[206] = 0;
	resu->faces[207] = 1;resu->faces[208] = 2;resu->faces[209] = 0;
	resu->faces[210] = 1;resu->faces[211] = 2;resu->faces[212] = 0;
	resu->faces[213] = 1;resu->faces[214] = 2;resu->faces[215] = 0;
	resu->faces[216] = 1;resu->faces[217] = 2;resu->faces[218] = 0;
	resu->faces[219] = 1;resu->faces[220] = 2;resu->faces[221] = 0;
	resu->faces[222] = 1;resu->faces[223] = 2;resu->faces[224] = 0;
	resu->faces[225] = 1;resu->faces[226] = 2;resu->faces[227] = 0;
	resu->faces[228] = 1;resu->faces[229] = 3;resu->faces[230] = 2;
	resu->faces[231] = 1;resu->faces[232] = 2;resu->faces[233] = 0;
	resu->faces[234] = 1;resu->faces[235] = 2;resu->faces[236] = 0;
	resu->faces[237] = 1;resu->faces[238] = 2;resu->faces[239] = 0;

	glCreateVertexArrays(1, &resu->vertexArrayObject);
	glBindVertexArray(resu->vertexArrayObject);

	glGenBuffers(1, &resu->vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, 42 * 3 * sizeof(float), resu->vertexs, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->vertexColorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->vertexColorBuffer);
	glBufferData(GL_ARRAY_BUFFER, 42 * sizeof(float), resu->vertexColors, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->vertexDiffuseBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->vertexDiffuseBuffer);
	glBufferData(GL_ARRAY_BUFFER, 42 * sizeof(float), resu->diffuses, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->vertexSpecularBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->vertexSpecularBuffer);
	glBufferData(GL_ARRAY_BUFFER, 42 * sizeof(float), resu->speculars, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, 42 * sizeof(float), resu->normals, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->textMapBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, resu->textMapBuffer);
	glBufferData(GL_ARRAY_BUFFER, 42 * sizeof(float), resu->textures, GL_STATIC_DRAW);

	glGenBuffers(1, &resu->indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, resu->indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 240 * sizeof(unsigned int), resu->faces, GL_STATIC_DRAW);

	return resu;
}
		
Mesh* MeshFactory::createTourus(const char*){

}

void fillVector(Vector3* vector, float value, int count){
	for(int i=0;i<count;i++){
		vector[i].x(value);vector[i].y(value);vector[i].z(value);
	}
}