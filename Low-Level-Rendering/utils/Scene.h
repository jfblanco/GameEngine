#ifndef __ENGINE__LOWLEVELRENDERING_UTILS_SCENE__
#define __ENGINE__LOWLEVELRENDERING_UTILS_SCENE__

	#include "Camera.h"
	#include "../../Core/utils/Buffer.h"

	class Mesh;	
	class ShaderStrategy;	
	class Shader;	

	class Scene {
	
	private:	
		Camera camera;
		Buffer buffer;	
		BufferItem* bufferItem;
		int shadersIndex[100];
		ShaderStrategy* shaders[20];
		int shadersCount;
		ShaderStrategy* actualShaderStrategy;
		Shader* actualShader;

		void shaderContextSwitch(Shader*);
	public:
		Scene();
		~Scene();

		void addMesh(Mesh*);
		void addShader(Shader*, ShaderStrategy*);
		void renderScene();
	};

#endif