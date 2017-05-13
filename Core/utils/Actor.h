#ifndef __ENGINE__UTILS_ACTOR_
#define __ENGINE__UTILS_ACTOR_

	#include "../../Low-Level-Rendering/utils/Mesh.h"
	#include "../../Low-Level-Rendering/utils/Shader.h"
	#include "Matrix4x4.h"
	#include "BufferItem.h"

	struct Actor : BufferItem{
		Matrix4x4 rotationAndTranslation;
		Mesh* mesh;
		Shader* shader;
	};

#endif