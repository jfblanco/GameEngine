#ifndef __ENGINE__UTILS_STRING_
#define __ENGINE__UTILS_STRING_

	class String {
	
	private:	
		char word[65];
		int lenght;
		unsigned long hashCode;

	public:
		String();
		~String();

		bool operator==(String);
		bool operator==(const char*);
		void operator=(const char*);
		void concat(String);
		void concat(const char*);
		String operator+(String);
		const char* operator+(const char*);
		String substring(int, int);
		char** split(const char*);
		int size();
		void print();
		unsigned long getHash();
		const char* toChar();
	};

#endif