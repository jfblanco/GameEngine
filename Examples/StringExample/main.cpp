#include <iostream>
#include "../../Core/utils/ShortString.h"
#include "../../Core/utils/String.h"
#include "../../Core/utils/LongString.h"
#include "../../../Debugging/ConsoleOutput.h"

int main(int argc, char** args){
	ShortString shortstring = ShortString();
	ShortString shortstringcomparator = ShortString();

	if(shortstring == shortstringcomparator)
		ConsoleOutput::getInstance()->success("String initialization zero is working");
	else
		ConsoleOutput::getInstance()->error("String initialization zero is not working");

	shortstring = "test";
	if(shortstring == "test")
		ConsoleOutput::getInstance()->success("ShortString operator equals: const char is working");
	else
		ConsoleOutput::getInstance()->error("ShortString operator equals: const char is not working");

	shortstring = "abcdefghijklmnopqrstuvwxyz";
	if(shortstring == "abcdefghijklmnop")
		ConsoleOutput::getInstance()->success("ShortString operator equals: String longer than 16 is working");
	else
		ConsoleOutput::getInstance()->error("ShortString operator equals: String longer than 16 is not working");

	shortstring = "operator equals";
	shortstringcomparator = shortstring;
	if(shortstringcomparator == "operator equals")
		ConsoleOutput::getInstance()->success("ShortString operator equals: ShortString is working");
	else
		ConsoleOutput::getInstance()->error("ShortString operator equals: ShortString is not working");

	shortstring = "this";
	shortstring = shortstring + " is";
	shortstring = shortstring + "";
	shortstring = shortstring + "";
	shortstring = shortstring + "";
	shortstring = shortstring + "";
	shortstring = shortstring + " a Concatenation";
	if(shortstring == "this is a Concat")
		ConsoleOutput::getInstance()->success("ShortString operator plus: const char is working");
	else
		ConsoleOutput::getInstance()->error("ShortString operator plus: const char is not working");

	shortstring = "1234567890";
	shortstringcomparator = "0987654321";
	shortstring.concat(shortstringcomparator);
	if(shortstring == "1234567890098765")
		ConsoleOutput::getInstance()->success("ShortString operator concat: ShortString is working");
	else
		ConsoleOutput::getInstance()->error("ShortString operator concat: ShortString is not working");

	shortstring = "11111";
	shortstringcomparator = "22222";
	ShortString stringConcat = ShortString();
	stringConcat = shortstring + shortstringcomparator;
	if(stringConcat == "1111122222")
		ConsoleOutput::getInstance()->success("ShortString operator plus: ShortString is working");
	else
		ConsoleOutput::getInstance()->error("ShortString operator plus: ShortString is not working");

	shortstring = "123 ";
	shortstring.concat("it's okay!!");
	if(shortstring == "123 it's okay!!")
		ConsoleOutput::getInstance()->success("ShortString operator concat: const char* is working");
	else
		ConsoleOutput::getInstance()->error("ShortString operator concat: const char* is not working");


	shortstring = "test";
	shortstring.concat(NULL);
	if(shortstring == "test")
		ConsoleOutput::getInstance()->success("ShortString operator concat: NULL is working");
	else
		ConsoleOutput::getInstance()->error("ShortString operator concat: NULL is not working");

	shortstring = "test";
	shortstring = shortstring;
	if(shortstring == "test")
		ConsoleOutput::getInstance()->success("ShortString operator plus: NULL is working");
	else
		ConsoleOutput::getInstance()->error("ShortString operator plus: NULL is not working");	

	shortstring = "11111";
	ShortString auxstring;
	stringConcat = shortstring + auxstring;
	if(stringConcat == "11111")
		ConsoleOutput::getInstance()->success("ShortString operator plus: ShortString is working");
	else
		ConsoleOutput::getInstance()->error("ShortString operator plus: ShortString is not working");

	shortstring = "aaaa123456aaaaaabbbbbbbbbbbbbbbb";
	shortstringcomparator = shortstring.substring(4,10);
	if(shortstringcomparator == "123456")
		ConsoleOutput::getInstance()->success("ShortString operator substring: ShortString is working");
	else
		ConsoleOutput::getInstance()->error("ShortString operator substring: ShortString is not working");

	String string = String();
	string = "I'm an String, My size is 64B lenght, this phrase should fix";
	if(string == "I'm an String, My size is 64B lenght, this phrase should fix")
		ConsoleOutput::getInstance()->success("ShortString operator substring: ShortString is working");
	else
		ConsoleOutput::getInstance()->error("ShortString operator substring: ShortString is not working");

	LongString longstring = LongString();
	longstring = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";
	if(longstring == "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.")
		ConsoleOutput::getInstance()->success("ShortString operator substring: ShortString is working");
	else
		ConsoleOutput::getInstance()->error("ShortString operator substring: ShortString is not working");
}