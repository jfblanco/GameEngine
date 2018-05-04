#include "PrintCommand.h"
#include "../../../Core/interfaces/Input.h"
#include "../../../Core/Core.h"
#include <iostream>

void PrintCommand::keyDown(unsigned int _keyCode){
	std::cout << "You have pressed a key: " << _keyCode << std::endl;
}

void PrintCommand::keyUp(unsigned int _keyCode){
	std::cout << "You have pressed a key: " << _keyCode << std::endl;
}