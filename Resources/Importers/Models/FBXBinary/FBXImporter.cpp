#include "FBXImporter.h"
#include "BinaryNode.h"
#include "BinaryProperty.h"
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <inttypes.h>
#include <stdint.h>
#include <cstdint>


FBXImporter::FBXImporter(){

}

FBXImporter::~FBXImporter(){

}

void FBXImporter::importFromBynary(const char * fileName){
  this->fileBuffer = new char[1024];

  this->file.open(fileName, std::ios::in);
  this->file.seekg(23);
  //FBX File Version
  this->file.read(this->fileBuffer, 3);
  memcpy(&this->version, this->fileBuffer, 3);
  std::cout << "FBX Version: " << this->version << "\n";

  this->file.seekg(27);

  //FBX Root Node
  // BinaryNode* rootNode = new BinaryNode();
  // this->loadNode(rootNode);
  int i = 0;
  while(!this->file.eof()) {
    BinaryNode* secondNode = new BinaryNode();
    this->loadNode(secondNode);
    i++;
  }

  this->file.close();
}
void FBXImporter::loadNode(BinaryNode* node){

  node->setStaticInfoFromBuffer(this->readFromFile(13));

  node->setNodeName(this->readFromFile(node->getNameLength()));

  node->printNode();

  this->loadProperties(node);


}

void FBXImporter::loadProperties(BinaryNode* node){
  //std::cout << "loadProperties: "<< i << '\n';
  for (int i = 0; i < (int)node->getPropertiesLength() && i <10; i++) {
    node->addProperty(this->loadProperty());
  }
}

BinaryProperty* FBXImporter::loadProperty(){
  BinaryProperty* prop = new BinaryProperty();
  prop->setTypeCode(this->readFromFile(1));
  long length = prop->getDataLength();

  if(prop->isPrimitive()){
    prop->setPrimitiveData(this->readFromFile(length), length);
  }else if(prop->isArray()){
    char* aux = this->readFromFile(length);
    prop->setArrayMetaData(aux);//this->readFromFile(length));
    prop->setArrayData(this->readFromFile(prop->getArrayLength()));
  }else{
    prop->setObjectMetaData(this->readFromFile(length));
    prop->setObjectData(this->readFromFile(prop->getObjectLength()));
  }
  return prop;
}
char* FBXImporter::readFromFile(long length){
  this->file.read(this->fileBuffer, length);
  return this->fileBuffer;
}
