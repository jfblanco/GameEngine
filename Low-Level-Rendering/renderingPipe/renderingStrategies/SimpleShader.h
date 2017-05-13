#ifndef __ENGINE__SDL_RENDER_PIPE_SHADERS_SIMPLE__
#define __ENGINE__SDL_RENDER_PIPE_SHADERS_SIMPLE__

	#include "../ShaderStrategy.h"

	class SimpleShader : public ShaderStrategy{
	
	public:
		SimpleShader(Shader*);
		~SimpleShader();

		void excecute(Shader*, Mesh*);

	private:
		int vertexAttributePosition;	
	};

#endif