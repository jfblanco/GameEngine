#ifndef __ENGINE__UTILS_SHORT_STRING_
#define __ENGINE__UTILS_SHORT_STRING_

	class String;
	class LongString;

	class ShortString {
	
	private:	
		char word[17];
		unsigned int lenght;
		unsigned long hashCode;

	public:
		ShortString();
		~ShortString();

		bool operator==(ShortString);
		bool operator==(const char*);
		void operator=(const char*);
		void concat(ShortString);
		void concat(const char*);
		ShortString operator+(LongString);
		ShortString operator+(String);
		ShortString operator+(ShortString);
		ShortString operator+(const char*);
		ShortString operator+(unsigned int);
		
		ShortString substring(int, int);
		char** split(const char*);
		int size();
		void print();
		unsigned long getHash();
		const char* toChar();
	};

#endif