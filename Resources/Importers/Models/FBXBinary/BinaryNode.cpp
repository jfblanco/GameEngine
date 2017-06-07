#include "BinaryNode.h"
#include "BinaryProperty.h"
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <inttypes.h>
#include <stdint.h>
#include <cstdint>
#include <vector>

BinaryNode::BinaryNode(){
}

BinaryNode::~BinaryNode(){

}
unsigned long BinaryNode::getPropertiesLength(){
  return this->numProperties;
}
void BinaryNode::setStaticInfoFromBuffer(char* buffer){
  memcpy(&this->endOffset, &buffer[0], 4);
  memcpy(&this->numProperties, &buffer[4], 4);
  memcpy(&this->propertyListLen, &buffer[8], 4);
  memcpy(&this->nameLen, &buffer[12], 1);
  this->nodeName = (char*) malloc(this->getNameLength());
}
void BinaryNode::setNodeName(char* name){
  memcpy(this->nodeName, name, this->getNameLength());
}
int BinaryNode::getNameLength(){
  return (int)this->nameLen;
}
void BinaryNode::printNode(){
  std::cout << "---------------------------" << '\n';
  std::cout << "End Offset: "<< this->endOffset << '\n';
  std::cout << "Number Properties: "<< this->numProperties << '\n';
  std::cout << "Property List length: "<< this->propertyListLen << '\n';
  std::cout << "Name length: "<< this->getNameLength() << '\n';
  std::cout << "Node Name: "<< this->nodeName << '\n';
  std::cout <<  '\n';
}
void BinaryNode::addProperty(BinaryProperty* prop){
  this->properties.push_back(prop);
  prop->printProperty();
}
