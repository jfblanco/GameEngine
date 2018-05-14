#include <iostream>
#include <initializer_list>
#include "ConsoleOutput.h"
#include "../Core/utils/ShortString.h"
#include "../Core/utils/String.h"
#include "../Core/utils/LongString.h"

ConsoleOutput* ConsoleOutput::instance = new ConsoleOutput();

ConsoleOutput::ConsoleOutput(){

}

ConsoleOutput::~ConsoleOutput(){

}

ConsoleOutput* ConsoleOutput::getInstance(){
	return instance;
}

void ConsoleOutput::info(const char* _message){
	std::cout << "\033[1;34m[INFO]:\033[0m " << _message << std::endl;
}

void ConsoleOutput::info(ShortString* _message){
	std::cout << "\033[1;34m[INFO]:\033[0m " << _message->toChar() << std::endl;
}

void ConsoleOutput::info(String* _message){
	std::cout << "\033[1;34m[INFO]:\033[0m " << _message->toChar() << std::endl;
}

void ConsoleOutput::info(LongString* _message){
	std::cout << "\033[1;34m[INFO]:\033[0m " << _message->toChar() << std::endl;
}

void ConsoleOutput::warning(const char* _message){
	std::cout << "\033[1;33m[WARN]:\033[0m " << _message << std::endl;
}

void ConsoleOutput::warning(ShortString* _message){
	std::cout << "\033[1;33m[WARN]:\033[0m " << _message->toChar() << std::endl;
}

void ConsoleOutput::warning(String* _message){
	std::cout << "\033[1;33m[WARN]:\033[0m " << _message->toChar() << std::endl;
}

void ConsoleOutput::warning(LongString* _message){
	std::cout << "\033[1;33m[WARN]:\033[0m " << _message->toChar() << std::endl;
}

void ConsoleOutput::error(const char* _message){
	std::cout << "\033[1;31m[ERROR]:\033[0m " << _message << std::endl;
}

void ConsoleOutput::error(ShortString* _message){
	std::cout << "\033[1;31m[ERROR]:\033[0m " << _message->toChar() << std::endl;
}

void ConsoleOutput::error(String* _message){
	std::cout << "\033[1;31m[ERROR]:\033[0m " << _message->toChar() << std::endl;
}

void ConsoleOutput::error(LongString* _message){
	std::cout << "\033[1;31m[ERROR]:\033[0m " << _message->toChar() << std::endl;
}

void ConsoleOutput::fatal(const char* _message){
	std::cout << "\033[1;31m[FATAL]:\033[0m " << _message << std::endl;
}

void ConsoleOutput::fatal(ShortString* _message){
	std::cout << "\033[1;31m[FATAL]:\033[0m " << _message->toChar() << std::endl;
}

void ConsoleOutput::fatal(String* _message){
	std::cout << "\033[1;31m[FATAL]:\033[0m " << _message->toChar() << std::endl;
}

void ConsoleOutput::fatal(LongString* _message){
	std::cout << "\033[1;31m[FATAL]:\033[0m " << _message->toChar() << std::endl;
}

void ConsoleOutput::success(const char* _message){
	std::cout << "\033[38;5;2m[SUCCESS]:\033[0m " << _message << std::endl;
}

void ConsoleOutput::success(ShortString* _message){
	std::cout << "\033[38;5;2m[SUCCESS]:\033[0m " << _message->toChar() << std::endl;
}

void ConsoleOutput::success(String* _message){
	std::cout << "\033[38;5;2m[SUCCESS]:\033[0m " << _message->toChar() << std::endl;
}

void ConsoleOutput::success(LongString* _message){
	std::cout << "\033[38;5;2m[SUCCESS]:\033[0m " << _message->toChar() << std::endl;
}