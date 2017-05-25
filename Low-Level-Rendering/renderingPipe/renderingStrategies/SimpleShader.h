#ifndef __ENGINE__SDL_RENDER_PIPE_SHADERS_SIMPLE__
#define __ENGINE__SDL_RENDER_PIPE_SHADERS_SIMPLE__

	#include "../ShaderStrategy.h"
	#include "../../../Core/utils/Matrix4x4.h"
	#include "../../utils/Camera.h"

	class SimpleShader : public ShaderStrategy{
	
	public:
		SimpleShader(Shader*);
		~SimpleShader();

		void excecute(Shader*, Actor*);

	private:
		int vertexAttributePosition, vertexAttributeColor, projectionMatrixUniformPosition, modelMatrix, viewMatrix;	
		Matrix4x4 projectionMatrix;
		Camera camera;
	};

#endif