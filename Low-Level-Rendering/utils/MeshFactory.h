#ifndef __ENGINE__LOWLEVELRENDERING_UTILS_MESHFACTORY__
#define __ENGINE__LOWLEVELRENDERING_UTILS_MESHFACTORY__

	class Mesh;
	class Actor;

	class MeshFactory {
	
	private:	
		Mesh* cube;
		Mesh* line;
		Mesh* plane;
		Mesh* sphere;
		Mesh* tourus;

		Mesh* createCube();
		Mesh* createLine();
		Mesh* createPlane();
		Mesh* createSphere();
		Mesh* createTourus();
		
	public:
		MeshFactory();
		~MeshFactory();

		Actor* createCube(const char*);
		Actor* createLine(const char*);
		Actor* createPlane(const char*);
		Actor* createSphere(const char*);
		Actor* createTourus(const char*);
	};

#endif