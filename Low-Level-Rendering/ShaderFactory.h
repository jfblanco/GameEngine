#ifndef __ENGINE__SDL_SHADER_FACTORY__
#define __ENGINE__SDL_SHADER_FACTORY__

	class Shader;

	class ShaderFactory {
	
	private:	
				
	public:
		ShaderFactory();
		~ShaderFactory();

		Shader* createShader(const char*, const char*, Shader*);
	};

#endif