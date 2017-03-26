#ifndef __ENGINE__UTILS_SHADER_
#define __ENGINE__UTILS_SHADER_

	#include "Material.h"
	#include "BufferItem.h"

	struct Shader : BufferItem {
		unsigned int vertexShaderId;
		unsigned int fragmentShaderId;		
		unsigned int programShaderId;		
		Material* material;
	};

#endif