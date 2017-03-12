#ifndef __ENGINE__CORE_
#define __ENGINE__CORE_

	class Render;
	class Audio;
	class Resources;
	class Input;
	class FrontEnd;
	class Animation;
	class Debug;
	class GamePlay;
	class Network;
	class Physics;
	class Scene;
	class VisualEfects;
	class ArtificialInteligense;

	class Core {
	
	private:	
		Render* render;
		Audio* audio;
		ArtificialInteligense* artificialInteligense;
		Resources* resources;
		Input* input;
		FrontEnd* frontEnd;
		Animation* animation;
		Debug* debug;
		GamePlay* gamePlay;
		Network* netWork;
		Physics* physics;
		Scene* scene;
		VisualEfects* visualEfects;

		bool imAlive = true;

		static Core* instance;

		Core();

	public:
		static Core* getInstance();
		~Core();

		void start();
		void pause();
		
		void begin();
		void stop();
		
		void setRender(Render* render);
		Render* getRender();

		void setAudio(Audio* audio);
		Audio* getAudio();

		void setArtificialInteligense(ArtificialInteligense* artificialInteligense);
		ArtificialInteligense* getArtificialInteligense();

		void setResources(Resources* resources);
		Resources* getResources();

		void setInput(Input* input);
		Input* getInput();

		void setFrontEnd(FrontEnd* frontEnd);
		FrontEnd* getFrontEnd();

		void setAnimation(Animation* animation);
		Animation* getAnimation();

		void setDebug(Debug* debug);
		Debug* getDebug();

		void setGamePlay(GamePlay* render);
		GamePlay* getGamePlay();

		void setNetwork(Network* netWork);
		Network* getNetwork();

		void setPhysics(Physics* physics);
		Physics* getPhysics();

		void setScene(Scene* scene);
		Scene* getScene();

		void setVisualEfects(VisualEfects* visualEfects);
		VisualEfects* getVisualEfects();
	};

#endif