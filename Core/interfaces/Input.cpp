#include "Input.h"
#include <SDL.h>

Input::Input(){

}

Input::~Input(){
	
}

void Input::init(){

}

void Input::checkInput(){
	
}

void Input::addShutDownFunction(int key, ShutDownInputCommand* function){

}

void Input::addKeyBoardFunction(int key, KeyBoardInputCommand* function){

}

void Input::addMouseFunction(int key, MouseInputCommand* function){

}

void Input::addJoyStickFunction(int key, JoyStickInputCommand* function){

}

void Input::addControllerFunction(int key, ControllerInputCommand* function){

}

void ShutDownInputNullCommand::shutDownEvent(){
	
}

void KeyBoardInputNullCommand::keyDown(unsigned int){
	
}

void KeyBoardInputNullCommand::keyUp(unsigned int){
	
}

void MouseInputNullCommand::leftClick(){
	
}

void MouseInputNullCommand::rightClick(){
	
}

void MouseInputNullCommand::leftUp(){
	
}

void MouseInputNullCommand::rightUp(){
	
}

void MouseInputNullCommand::middleClick(){
	
}

void MouseInputNullCommand::mouseMove(unsigned int, unsigned int){
	
}

void MouseInputNullCommand::wheelMove(unsigned int){
	
}