#ifndef __ENGINE__LOWLEVELRENDERING_UTILS_MESHFACTORY__
#define __ENGINE__LOWLEVELRENDERING_UTILS_MESHFACTORY__

	class Mesh;

	class MeshFactory {
	
	private:	
		
	public:
		MeshFactory();
		~MeshFactory();

		Mesh* createCube(const char*);
		Mesh* createLine(const char*);
		Mesh* createPlane(const char*);
		Mesh* createSphere(const char*);
		Mesh* createTourus(const char*);
	};

#endif