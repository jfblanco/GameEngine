#include "LongString.h"
#include <string.h>
#include <iostream>

unsigned long hashLongString(const char*);

LongString::LongString(){
	this->word[0] = '\0';
	this->word[256] = '\0';
	this->lenght = 0;
	this->hashCode = 0;
}

LongString::~LongString(){
	
}

bool LongString::operator==(LongString _string){
	return (this->lenght == _string.size()) && (this->hashCode == _string.getHash());
}

bool LongString::operator==(const char* _string){
	if(_string != NULL){
		int size = strlen(_string);
		unsigned long hashcode = hashLongString(_string);
		return (this->lenght == size) && (this->hashCode == hashcode);	
	}else{
		return false;	
	}
}

void LongString::operator=(const char* _string){
	if(_string != NULL){
		word[0] = _string[0];word[1] = _string[1];word[2] = _string[2];word[3] = _string[3];word[4] = _string[4];
		word[5] = _string[5];word[6] = _string[6];word[7] = _string[7];word[8] = _string[8];word[9] = _string[9];
		word[10] = _string[10];word[11] = _string[11];word[12] = _string[12];word[13] = _string[13];word[14] = _string[14];
		word[15] = _string[15];word[16] = _string[16];word[17] = _string[17];word[18] = _string[18];word[19] = _string[19];
		word[20] = _string[20];word[21] = _string[21];word[22] = _string[22];word[23] = _string[23];word[24] = _string[24];
		word[25] = _string[25];word[26] = _string[26];word[27] = _string[27];word[28] = _string[28];word[29] = _string[29];
		word[30] = _string[30];word[31] = _string[31];word[32] = _string[32];word[33] = _string[33];word[34] = _string[34];
		word[35] = _string[35];word[36] = _string[36];word[37] = _string[37];word[38] = _string[38];word[39] = _string[39];
		word[40] = _string[40];word[41] = _string[41];word[42] = _string[42];word[43] = _string[43];word[44] = _string[44];
		word[45] = _string[45];word[46] = _string[46];word[47] = _string[47];word[48] = _string[48];word[49] = _string[49];
		word[50] = _string[50];word[51] = _string[51];word[52] = _string[52];word[53] = _string[53];word[54] = _string[54];
		word[55] = _string[55];word[56] = _string[56];word[57] = _string[57];word[58] = _string[58];word[59] = _string[59];
		word[60] = _string[60];word[61] = _string[61];word[62] = _string[62];word[63] = _string[63];word[64] = _string[64];
		word[65] = _string[65];word[66] = _string[66];word[67] = _string[67];word[68] = _string[68];word[69] = _string[69];
		word[70] = _string[70];word[71] = _string[71];word[72] = _string[72];word[73] = _string[73];word[74] = _string[74];
		word[75] = _string[75];word[76] = _string[76];word[77] = _string[77];word[78] = _string[78];word[79] = _string[79];
		word[80] = _string[80];word[81] = _string[81];word[82] = _string[82];word[83] = _string[83];word[84] = _string[84];
		word[85] = _string[85];word[86] = _string[86];word[87] = _string[87];word[88] = _string[88];word[89] = _string[89];
		word[90] = _string[90];word[91] = _string[91];word[92] = _string[92];word[93] = _string[93];word[94] = _string[94];
		word[95] = _string[95];word[96] = _string[96];word[97] = _string[97];word[98] = _string[98];word[99] = _string[99];
		word[100] = _string[100];word[101] = _string[101];word[102] = _string[102];word[103] = _string[103];word[104] = _string[104];
		word[105] = _string[105];word[106] = _string[106];word[107] = _string[107];word[108] = _string[108];word[109] = _string[109];
		word[110] = _string[110];word[111] = _string[111];word[112] = _string[112];word[113] = _string[113];word[114] = _string[114];
		word[115] = _string[115];word[116] = _string[116];word[117] = _string[117];word[118] = _string[118];word[119] = _string[119];
		word[120] = _string[120];word[121] = _string[121];word[122] = _string[122];word[123] = _string[123];word[124] = _string[124];
		word[125] = _string[125];word[126] = _string[126];word[127] = _string[127];word[128] = _string[128];word[129] = _string[129];
		word[130] = _string[130];word[131] = _string[131];word[132] = _string[132];word[133] = _string[133];word[134] = _string[134];
		word[135] = _string[135];word[136] = _string[136];word[137] = _string[137];word[138] = _string[138];word[139] = _string[139];
		word[140] = _string[140];word[141] = _string[141];word[142] = _string[142];word[143] = _string[143];word[144] = _string[144];
		word[145] = _string[145];word[146] = _string[146];word[147] = _string[147];word[148] = _string[148];word[149] = _string[149];
		word[150] = _string[150];word[151] = _string[151];word[152] = _string[152];word[153] = _string[153];word[154] = _string[154];
		word[155] = _string[155];word[156] = _string[156];word[157] = _string[157];word[158] = _string[158];word[159] = _string[159];
		word[160] = _string[160];word[161] = _string[161];word[162] = _string[162];word[163] = _string[163];word[164] = _string[164];
		word[165] = _string[165];word[166] = _string[166];word[167] = _string[167];word[168] = _string[168];word[169] = _string[169];
		word[170] = _string[170];word[171] = _string[171];word[172] = _string[172];word[173] = _string[173];word[174] = _string[174];
		word[175] = _string[175];word[176] = _string[176];word[177] = _string[177];word[178] = _string[178];word[179] = _string[179];
		word[180] = _string[180];word[181] = _string[181];word[182] = _string[182];word[183] = _string[183];word[184] = _string[184];
		word[185] = _string[185];word[186] = _string[186];word[187] = _string[187];word[188] = _string[188];word[189] = _string[189];
		word[190] = _string[190];word[191] = _string[191];word[192] = _string[192];word[193] = _string[193];word[194] = _string[194];
		word[195] = _string[195];word[196] = _string[196];word[197] = _string[197];word[198] = _string[198];word[199] = _string[199];
		word[200] = _string[200];word[201] = _string[201];word[202] = _string[202];word[203] = _string[203];word[204] = _string[204];
		word[205] = _string[205];word[206] = _string[206];word[207] = _string[207];word[208] = _string[208];word[209] = _string[209];
		word[210] = _string[210];word[211] = _string[211];word[212] = _string[212];word[213] = _string[213];word[214] = _string[214];
		word[215] = _string[215];word[216] = _string[216];word[217] = _string[217];word[218] = _string[218];word[219] = _string[219];
		word[220] = _string[220];word[221] = _string[221];word[222] = _string[222];word[223] = _string[223];word[224] = _string[224];
		word[225] = _string[225];word[226] = _string[226];word[227] = _string[227];word[228] = _string[228];word[229] = _string[229];
		word[230] = _string[230];word[231] = _string[231];word[232] = _string[232];word[233] = _string[233];word[234] = _string[234];
		word[235] = _string[235];word[236] = _string[236];word[237] = _string[237];word[238] = _string[238];word[239] = _string[239];
		word[240] = _string[240];word[241] = _string[241];word[242] = _string[242];word[243] = _string[243];word[244] = _string[244];
		word[245] = _string[245];word[246] = _string[246];word[247] = _string[247];word[248] = _string[248];word[249] = _string[249];
		word[250] = _string[250];word[251] = _string[251];word[252] = _string[252];word[253] = _string[253];word[254] = _string[254];
		word[255] = _string[255];
		this->lenght = strlen(word);
		this->hashCode = hashLongString(word);
	}
}

const char* LongString::operator+(const char* _string){
	if(_string != NULL){
		int stringSize = strlen(_string);
		for(int i = this->lenght; i < 256 && i < this->lenght + stringSize; i++){
			word[i] = _string[i - this->lenght];
		}
		word[this->lenght + stringSize] = '\0';
		word[256] = '\0';
		this->lenght = strlen(word);
		this->hashCode = hashLongString(word);
	}
	return word;	
}

void LongString::concat(const char* _string){
	this->operator+(_string);
}

LongString LongString::operator+(LongString _string){
	LongString resu = LongString();
	resu = this->operator+(_string.toChar());
	return resu;
}

void LongString::concat(LongString _string){
	this->operator+(_string.toChar());
}

LongString LongString::substring(int _from, int _to){
	LongString resu = LongString();
	char* newstring = new char[256];
	for(int i = _from; i < 256 && i < _to;i++){
		newstring[i-_from] = this->word[i];
	}
	if(_to < 256){
		newstring[_to+1] = '\0';
	}		
	newstring[256] = '\0';
	resu = resu + newstring;
	return resu;
}

char** LongString::split(const char* _character){
	char** resu = new char*[256];
	char* pch;
	pch = strtok(this->word, _character);
	resu[0] = pch;
	int i =0;
	while(pch != NULL){
		resu[i] = pch;
		pch = strtok(NULL, _character);
		i++;
	}
	return resu;
}

int LongString::size(){
	return this->lenght;
}


unsigned long LongString::getHash(){
	return this->hashCode;
}

const char* LongString::toChar(){
	return word;
}

void LongString::print(){
	std::cout << word << " [s: " << this->lenght << "] [h: " << this->hashCode << "]" << std::endl;
}

unsigned long hashLongString(const char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c;

    return hash;
}