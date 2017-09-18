#include "BinaryProperty.h"
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <inttypes.h>
#include <stdint.h>
#include <cstdint>
#include<sstream>



BinaryProperty::BinaryProperty(){
  this->typeCode = (char*)malloc(1);
}
BinaryProperty::~BinaryProperty(){}
void BinaryProperty::setTypeCode(char* buffer){
  memcpy(this->typeCode, buffer, 1);
}

void BinaryProperty::setPrimitiveData(char* buffer, long length){
  this->data = (short*)malloc(length);
  memcpy(&this->data, buffer, length);
}
bool BinaryProperty::isArray(){
  return (
    strcmp(this->typeCode, "f") == 0 || strcmp(this->typeCode, "d") == 0 ||
    strcmp(this->typeCode, "l") == 0 || strcmp(this->typeCode, "b") == 0 ||
    strcmp(this->typeCode, "i") == 0
  );
}

bool BinaryProperty::isPrimitive(){
  return (
    strcmp(this->typeCode, "Y") == 0 || strcmp(this->typeCode, "C") == 0 ||
    strcmp(this->typeCode, "I") == 0 || strcmp(this->typeCode, "F") == 0 ||
    strcmp(this->typeCode, "D") == 0 || strcmp(this->typeCode, "L") == 0
  );
}
long BinaryProperty::getDataLength(){
  if(this->isPrimitive()){
    if(strcmp(this->typeCode, "Y") == 0){return 2;}
    if(strcmp(this->typeCode, "C") == 0){return 1;}
    if(strcmp(this->typeCode, "I") == 0 || strcmp(this->typeCode, "F") == 0)
      {return 4;}
    if(strcmp(this->typeCode, "D") == 0 || strcmp(this->typeCode, "L") == 0)
      {return 8;}
  }else if(this->isArray()){
    return 12;
  }else{
    return 4;
  }
}
void BinaryProperty::setArrayMetaData(char* buffer){
  memcpy(&this->length, &buffer[0], 4);
  memcpy(&this->arrayEncoding, &buffer[4], 4);
  memcpy(&this->arrayCompressedLength, &buffer[8], 4);
  if(this->length == 0){return;}
  this->data = (short*) malloc(this->length);
}
void BinaryProperty::setArrayData(char* buffer){
  if(this->length == 0){return;}
  memcpy(&this->data, &buffer[0], this->length);
}
unsigned long BinaryProperty::getArrayLength(){
  return this->length;
}
void BinaryProperty::setObjectMetaData(char* buffer){
  memcpy(&this->length, buffer, 4);
  if(this->length == 0){return;}
  this->data = (short*) malloc(this->length);
}
void BinaryProperty::setObjectData(char* buffer){
  if(this->length == 0){return;}
  memcpy(&this->data, &buffer[0], this->length);
}
unsigned long BinaryProperty::getObjectLength(){
  return this->length;
}
void BinaryProperty::printProperty(){
  std::cout << "Type code: " << this->typeCode << '\n';
  if(strcmp(this->typeCode, "Y") == 0){
    std::cout << "Data: " << (signed int*)this->data << '\n';
  }else if(strcmp(this->typeCode, "C") == 0){
    std::cout << "Data: " << (bool*)this->data << '\n';
  }else if(strcmp(this->typeCode, "I") == 0){
    std::cout << "Data: " << (long*)this->data << '\n';
  }else if(strcmp(this->typeCode, "F") == 0){
    std::cout << "Data: " << (float*)this->data << '\n';
  }else if(strcmp(this->typeCode, "D") == 0){
    std::cout << "Data: " << (double*)this->data << '\n';
  }else if(strcmp(this->typeCode, "L") == 0){
    std::cout << "Data: " << (signed long long*)this->data << '\n';
  }else if(strcmp(this->typeCode, "S") == 0){
    std::cout << "Data lenght: " << this->length << '\n';
  }else{
    std::cout << "Data: " << this->data << '\n';
  }
  std::cout << '\n';
}
