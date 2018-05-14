#include "PrintCommand.h"
#include "../../../Core/interfaces/Input.h"
#include "../../../Core/Core.h"
#include "../../../Core/utils/String.h"
#include "../../../Debugging/ConsoleOutput.h"
#include <iostream>

void PrintCommand::keyDown(unsigned int _keyCode){
	String message;
	message = message + "You have pressed a key: " + _keyCode;
	ConsoleOutput::getInstance()->info(&message);
}

void PrintCommand::keyUp(unsigned int _keyCode){
	String message;
	message = message + "You have released a key: " + _keyCode;
	ConsoleOutput::getInstance()->info(&message);
}