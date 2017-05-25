#ifndef __ENGINE__LOWLEVELRENDERING_UTILS_SCENE__
#define __ENGINE__LOWLEVELRENDERING_UTILS_SCENE__

	#include "Camera.h"
	#include "../../Core/utils/Buffer.h"

	class Actor;	
	class ShaderStrategy;	
	class Shader;
	class TickTimeEventInterface;

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
		int tickIndex[100];
		TickTimeEventInterface* tickevents[20];
		int ticksCount;
		Actor* actualActor;

		void shaderContextSwitch(Shader*);
	public:
		Scene();
		~Scene();

		Actor* addActor(Actor*);
		void addShader(Shader*, ShaderStrategy*);
		void addActorToTickEventManager(Actor*, TickTimeEventInterface*);
		void renderScene();
		void sendTickEvent(unsigned int);
	};

#endif