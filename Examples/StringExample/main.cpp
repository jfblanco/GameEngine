#include <iostream>
#include "../../Core/utils/ShortString.h"
#include "../../Core/utils/String.h"
#include "../../Core/utils/LongString.h"

int main(int argc, char** args){
	ShortString shortstring = ShortString();
	ShortString shortstringcomparator = ShortString();

	if(shortstring == shortstringcomparator)
		std::cout << "\033[38;5;2mOK:\033[0m String initialization zero is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m String initialization zero is not working" << std::endl;

	shortstring = "test";
	if(shortstring == "test")
		std::cout << "\033[38;5;2mOK:\033[0m ShortString operator equals: const char is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m ShortString operator equals: const char is not working" << std::endl;

	shortstring = "abcdefghijklmnopqrstuvwxyz";
	if(shortstring == "abcdefghijklmnop")
		std::cout << "\033[38;5;2mOK:\033[0m ShortString operator equals: String longer than 16 is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m ShortString operator equals: String longer than 16 is not working" << std::endl;

	shortstring = "operator equals";
	shortstringcomparator = shortstring;
	if(shortstringcomparator == "operator equals")
		std::cout << "\033[38;5;2mOK:\033[0m ShortString operator equals: ShortString is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m ShortString operator equals: ShortString is not working" << std::endl;

	shortstring = "this";
	shortstring = shortstring + " is";
	shortstring = shortstring + "";
	shortstring = shortstring + "";
	shortstring = shortstring + "";
	shortstring = shortstring + "";
	shortstring = shortstring + " a Concatenation";
	if(shortstring == "this is a Concat")
		std::cout << "\033[38;5;2mOK:\033[0m ShortString operator plus: const char is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m ShortString operator plus: const char is not working" << std::endl;

	shortstring = "1234567890";
	shortstringcomparator = "0987654321";
	shortstring.concat(shortstringcomparator);
	if(shortstring == "1234567890098765")
		std::cout << "\033[38;5;2mOK:\033[0m ShortString operator concat: ShortString is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m ShortString operator concat: ShortString is not working" << std::endl;

	shortstring = "11111";
	shortstringcomparator = "22222";
	ShortString stringConcat = ShortString();
	stringConcat = shortstring + shortstringcomparator;
	if(stringConcat == "1111122222")
		std::cout << "\033[38;5;2mOK:\033[0m ShortString operator plus: ShortString is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m ShortString operator plus: ShortString is not working" << std::endl;

	shortstring = "123 ";
	shortstring.concat("it's okay!!");
	if(shortstring == "123 it's okay!!")
		std::cout << "\033[38;5;2mOK:\033[0m ShortString operator concat: const char* is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m ShortString operator concat: const char* is not working" << std::endl;


	shortstring = "test";
	shortstring.concat(NULL);
	if(shortstring == "test")
		std::cout << "\033[38;5;2mOK:\033[0m ShortString operator concat: NULL is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m ShortString operator concat: NULL is not working" << std::endl;

	shortstring = "test";
	shortstring = shortstring + NULL;
	if(shortstring == "test")
		std::cout << "\033[38;5;2mOK:\033[0m ShortString operator plus: NULL is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m ShortString operator plus: NULL is not working" << std::endl;		

	shortstring = "11111";
	ShortString auxstring;
	stringConcat = shortstring + auxstring;
	if(stringConcat == "11111")
		std::cout << "\033[38;5;2mOK:\033[0m ShortString operator plus: ShortString is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m ShortString operator plus: ShortString is not working" << std::endl;

	shortstring = "aaaa123456aaaaaabbbbbbbbbbbbbbbb";
	shortstringcomparator = shortstring.substring(4,10);
	if(shortstringcomparator == "123456")
		std::cout << "\033[38;5;2mOK:\033[0m ShortString operator substring: ShortString is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m ShortString operator substring: ShortString is not working" << std::endl;

	String string = String();
	string = "I'm an String, My size is 64B lenght, this phrase should fix";
	if(string == "I'm an String, My size is 64B lenght, this phrase should fix")
		std::cout << "\033[38;5;2mOK:\033[0m ShortString operator substring: ShortString is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m ShortString operator substring: ShortString is not working" << std::endl;

	LongString longstring = LongString();
	longstring = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum";
	if(longstring == "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in")
		std::cout << "\033[38;5;2mOK:\033[0m ShortString operator substring: ShortString is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m ShortString operator substring: ShortString is not working" << std::endl;
}