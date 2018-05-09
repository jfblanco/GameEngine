/*
* author: Albanesi Roberto
* e-mail: beto0607@gmail.com
* 
* 
* This class read and save Key-Value pairs in a text file.
* You can define the file in runtime using "setFile" (Default file indicated in PERSISTEN_DATA_FILE).
* It is a Singleton.
* 
* The data will be stored as text using the following format:
* -First line: quantity of Key-Value
* -Second line: Keys, separated by two whitespaces
* -Third line: Pair of indexes for values, separated by one whitespaces between pair and undersocore between parts. 
*              First value corresponds with start line and second value corresponds with finish line.Correlative with the 2nd line
* -From fourth line: Values
*/

#include <fstream>
#include <iostream>

#define PERSISTENT_DATA_FILE ".Persistent.Data"
class PersistentData
{

public:
	//Magnament
	void 	setFile(const char* _newFile);
	void 	configureObject();
	void 	onExit();

	//Integer
	void 	setInteger	(const char* _key, int _value);
	int 	getInteger	(const char* _key);
	int 	getInteger	(const char* _key, int _defaultValue);//if _key doesn't exist, returns _defaulValue
	//Long
	void	setLong		(const char* _key, long _value);
	long 	getLong		(const char* _key);
	long 	getLong		(const char* _key, long _defaulValue);

	//Float
	void 	setFloat	(const char* _key, float _value);
	float 	getFloat	(const char* _key);
	float 	getFloat	(const char* _key, float _defaulValue);
	//Double
	void 	setDouble	(const char* _key, double _value);
	double 	getDouble	(const char* _key);
	double 	getDouble	(const char* _key, double _defaulValue);

	//Char
	void	setChar		(const char* _key, char _value);
	char 	getChar		(const char* _key);
	char 	getChar		(const char* _key, char _defaulValue);
	//Char array
	void	setCharArray(const char* _key, char* _value);
	char* 	getCharArray(const char* _key);
	char* 	getCharArray(const char* _key, char* _defaulValue);

	static	PersistentData&	getInstance(){
		static PersistentData instance;
		return instance;
	};
private:
	void kaka();


	PersistentData(PersistentData const&);
	void operator=(PersistentData const&);

	

	PersistentData(){};

	const char* filePath = PERSISTENT_DATA_FILE;//Relative Path to data file

	std::fstream fileObject;//File object


	long keyCounter;//Amount of key-value in this file; First line

	struct data{
		const char* key; //Key in the 2nd line
		int keyLength; 
		long startLine; long finishLine; //Value interval [startLine, finishLine)
	};
	
};