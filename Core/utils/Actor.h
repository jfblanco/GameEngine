#ifndef __ENGINE__UTILS_ACTOR_
#define __ENGINE__UTILS_ACTOR_

	#include "Mesh.h"
	#include "Shader.h"
	#include "Matrix4x4.h"
	#include "ShortString.h"

	struct Actor{
		unsigned int id;
		ShortString tag;
		Matrix4x4 rotationAndTranslation;
		Mesh* mesh;
		Shader* shader;
	};

#endif