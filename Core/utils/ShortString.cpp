#include "ShortString.h"
#include "String.h"
#include "LongString.h"
#include <string.h>
#include <iostream>
#include <string>
#include "../../Debugging/ConsoleOutput.h"

unsigned long hash(const char*);

ShortString::ShortString(){
	this->word[0] = '\0';
	this->word[16] = '\0';
	this->lenght = 0;
	this->hashCode = 0;
}

ShortString::~ShortString(){
	
}

bool ShortString::operator==(ShortString _string){
	return (this->lenght == _string.size()) && (this->hashCode == _string.getHash());
}

bool ShortString::operator==(const char* _string){
	if(_string != NULL){
		int size = strlen(_string);
		unsigned long hashcode = hash(_string);
		return (this->lenght == size) && (this->hashCode == hashcode);	
	}else{
		return false;	
	}
}

void ShortString::operator=(const char* _string){
	if(_string != NULL){
		word[0] = _string[0];word[1] = _string[1];word[2] = _string[2];word[3] = _string[3];word[4] = _string[4];
		word[5] = _string[5];word[6] = _string[6];word[7] = _string[7];word[8] = _string[8];word[9] = _string[9];
		word[10] = _string[10];word[11] = _string[11];word[12] = _string[12];word[13] = _string[13];word[14] = _string[14];
		word[15] = _string[15];
		this->lenght = strlen(word);
		this->hashCode = hash(word);
	}
}

ShortString ShortString::operator+(const char* _string){
	if(_string != NULL){
		int stringSize = strlen(_string);
		for(int i = this->lenght; i < 16 && i < this->lenght + stringSize; i++){
			word[i] = _string[i - this->lenght];
		}
		word[this->lenght + stringSize] = '\0';
		word[16] = '\0';
		this->lenght = strlen(word);
		this->hashCode = hash(word);
	}
	return (*this);
}

ShortString ShortString::operator+(LongString _string){
	this->operator+(_string.toChar());
	return (*this);
}

ShortString ShortString::operator+(String _string){
	this->operator+(_string.toChar());
	return *this;
}

ShortString ShortString::operator+(ShortString _string){
	this->operator+(_string.toChar());
	return *this;
}

void ShortString::concat(const char* _string){
	this->operator+(_string);
}

void ShortString::concat(ShortString _string){
	this->operator+(_string.toChar());
}


ShortString ShortString::operator+(unsigned int _uint){
	std::string s = std::to_string(_uint);
	this->operator+(s.c_str());
	return *this;
}

ShortString ShortString::substring(int _from, int _to){
	ShortString resu = ShortString();
	char* newstring = new char[16];
	for(int i = _from; i < 16 && i < _to;i++){
		newstring[i-_from] = this->word[i];
	}
	if(_to < 16){
		newstring[_to+1] = '\0';
	}		
	newstring[16] = '\0';
	resu = resu + newstring;
	return resu;
}

char** ShortString::split(const char* _character){
	char** resu = new char*[16];
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

int ShortString::size(){
	return this->lenght;
}


unsigned long ShortString::getHash(){
	return this->hashCode;
}

const char* ShortString::toChar(){
	return word;
}

void ShortString::print(){
	String message;
	message = message + word + " [s: " + this->lenght + "] [h: " + this->hashCode + "]";
	ConsoleOutput::getInstance()->info(&message);
}

unsigned long hash(const char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c;

    return hash;
}