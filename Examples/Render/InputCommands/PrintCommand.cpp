#include "PrintCommand.h"
#include "../../../Core/interfaces/Input.h"
#include "../../../Core/Core.h"
#include <iostream>

void PrintCommand::excecute(){
	std::cout << "You have pressed a key!" << std::endl;
}