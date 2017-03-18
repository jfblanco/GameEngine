#ifndef __ENGINE__UTILS_SHADER_
#define __ENGINE__UTILS_SHADER_

	#include "Material.h"
	#include "ShortString.h"

	struct Shader{
		unsigned int id;
		ShortString tag;
		unsigned int vertexShaderId;
		unsigned int fragmentShaderId;		
		unsigned int programShaderId;		
		Material* material;
	};

#endif