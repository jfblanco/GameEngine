#ifndef __ENGINE__UTILS_LONG_STRING_
#define __ENGINE__UTILS_LONG_STRING_

	class LongString {
	
	private:	
		char word[257];
		int lenght;
		unsigned long hashCode;

	public:
		LongString();
		~LongString();

		bool operator==(LongString);
		bool operator==(const char*);
		void operator=(const char*);
		void concat(LongString);
		void concat(const char*);
		LongString operator+(LongString);
		const char* operator+(const char*);
		LongString substring(int, int);
		char** split(const char*);
		int size();
		void print();
		unsigned long getHash();
		const char* toChar();
	};

#endif