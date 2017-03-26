#ifndef __ENGINE__UTILS_ACTOR_
#define __ENGINE__UTILS_ACTOR_

	#include "Mesh.h"
	#include "Shader.h"
	#include "Matrix4x4.h"
	#include "BufferItem.h"

	struct Actor : BufferItem{
		Matrix4x4 rotationAndTranslation;
		Mesh* mesh;
		Shader* shader;
	};

#endif