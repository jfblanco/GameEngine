#ifndef __ENGINE__SDL_RENDER_PIPE_SHADER__
#define __ENGINE__SDL_RENDER_PIPE_SHADER__

	class Shader;
	class Actor;

	class ShaderStrategy {
	
	public:
		ShaderStrategy();
		~ShaderStrategy();

		virtual void excecute(Shader*, Actor*);
	};

#endif