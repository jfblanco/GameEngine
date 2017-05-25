#ifndef __ENGINE__UTILS_BUFFER_
#define __ENGINE__UTILS_BUFFER_

	class Mesh;
	class Actor;
	class BufferItem;
	class Material;
	class Shader;

	class Buffer {
	
	private:
		int currentIndex;
		int lenght;	
		int index[100];
		unsigned char buffer[1048576];

	public:
		Buffer();
		~Buffer();

		BufferItem* get(int);

		BufferItem* first();
		BufferItem* next();

		Actor* getActor(int);
		Actor* insert(Actor*);
		
		Shader* getShader(int);
		Shader* insert(Shader*);
		
		Material* getMaterial(int);
		void insert(Material*);
	};
#endif