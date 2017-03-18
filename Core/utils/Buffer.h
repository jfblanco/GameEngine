#ifndef __ENGINE__UTILS_BUFFER_
#define __ENGINE__UTILS_BUFFER_

	template <typename T>
	class Buffer {
	
	private:
		int lenght;	
		int index[100];
		unsigned char buffer[1048576];

	public:
		Buffer();
		~Buffer();

		T* get(int);
		void insert(T*);
	};
#endif