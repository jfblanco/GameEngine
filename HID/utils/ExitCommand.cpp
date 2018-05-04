#include "ExitCommand.h"
#include "../../Core/interfaces/Input.h"
#include "../../Core/Core.h"

void ExitCommand::shutDownEvent(){
	Core::getInstance()->stop();
}