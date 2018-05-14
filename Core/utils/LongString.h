#ifndef __ENGINE__UTILS_LONG_STRING_
#define __ENGINE__UTILS_LONG_STRING_

	class ShortString;
	class String;

	class LongString {
	
	private:	
		char word[257];
		unsigned int lenght;
		unsigned long hashCode;

	public:
		LongString();
		~LongString();

		bool operator==(LongString);
		bool operator==(const char*);
		void operator=(const char*);
		void operator=(LongString*);
		void concat(LongString);
		void concat(const char*);
		LongString operator+(String);
		LongString operator+(ShortString);
		LongString operator+(LongString);
		LongString operator+(const char*);
		LongString operator+(unsigned int);
		LongString operator+(unsigned long);
		LongString operator+(float);
		LongString substring(int, int);
		char** split(const char*);
		int size();
		void print();
		unsigned long getHash();
		const char* toChar();
	};

#endif