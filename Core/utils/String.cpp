#include "ShortString.h"
#include "String.h"
#include "LongString.h"
#include <string.h>
#include <iostream>
#include <string>
#include "../../Debugging/ConsoleOutput.h"

unsigned long hashString(const char*);

String::String(){	
	this->word[0] = '\0';
	this->word[64] = '\0';
	this->lenght = 0;
	this->hashCode = 0;
}

String::~String(){
	
}

bool String::operator==(String _string){
	return (this->lenght == _string.size()) && (this->hashCode == _string.getHash());
}

bool String::operator==(const char* _string){
	if(_string != NULL){
		int size = strlen(_string);
		unsigned long hashcode = hashString(_string);
		return (this->lenght == size) && (this->hashCode == hashcode);	
	}else{
		return false;	
	}
}

void String::operator=(const char* _string){
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
		word[60] = _string[60];word[61] = _string[61];word[62] = _string[62];word[63] = _string[63];
		this->lenght = strlen(word);
		this->hashCode = hashString(word);
	}
}

String String::operator+(const char* _string){
	if(_string != NULL){
		int stringSize = strlen(_string);
		for(int i = this->lenght; i < 64 && i < this->lenght + stringSize; i++){
			word[i] = _string[i - this->lenght];
		}
		word[this->lenght + stringSize] = '\0';
		word[64] = '\0';
		this->lenght = strlen(word);
		this->hashCode = hashString(word);
	}
	return (*this);	
}

void String::concat(const char* _string){
	this->operator+(_string);
}

String String::operator+(LongString _string){
	this->operator+(_string.toChar());
	return (*this);
}

String String::operator+(String _string){
	this->operator+(_string.toChar());
	return (*this);
}

String String::operator+(ShortString _string){
	this->operator+(_string.toChar());
	return (*this);
}

String String::operator+(unsigned int _uint){
	std::string s = std::to_string(_uint);
	this->operator+(s.c_str());
	return *this;
}

void String::concat(String _string){
	this->operator+(_string.toChar());
}

String String::substring(int _from, int _to){
	String resu = String();
	char* newstring = new char[64];
	for(int i = _from; i < 64 && i < _to;i++){
		newstring[i-_from] = this->word[i];
	}
	if(_to < 64){
		newstring[_to+1] = '\0';
	}		
	newstring[64] = '\0';
	resu = resu + newstring;
	return resu;
}

char** String::split(const char* _character){
	char** resu = new char*[64];
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

int String::size(){
	return this->lenght;
}


unsigned long String::getHash(){
	return this->hashCode;
}

const char* String::toChar(){
	return word;
}

void String::print(){
	LongString message;
	message = message + word + " [s: " + this->lenght + "] [h: " + this->hashCode + "]";
	ConsoleOutput::getInstance()->info(&message);
}

unsigned long hashString(const char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c;

    return hash;
}