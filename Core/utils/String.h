#ifndef __ENGINE__UTILS_STRING_
#define __ENGINE__UTILS_STRING_

	class ShortString;
	class LongString;

	class String {
	
	private:	
		char word[65];
		unsigned int lenght;
		unsigned long hashCode;

	public:
		String();
		~String();

		bool operator==(String);
		bool operator==(const char*);
		void operator=(const char*);
		void concat(String);
		void concat(const char*);
		String operator+(ShortString);
		String operator+(String);
		String operator+(LongString);
		String operator+(const char*);
		String operator+(unsigned int);

		String substring(int, int);
		char** split(const char*);
		int size();
		void print();
		unsigned long getHash();
		const char* toChar();
	};

#endif