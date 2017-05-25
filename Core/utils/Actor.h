#ifndef __ENGINE__UTILS_ACTOR_
#define __ENGINE__UTILS_ACTOR_

	#include "BufferItem.h"
	
	class Mesh;

	struct Actor : BufferItem{
		unsigned int vertexArrayObject = 0;
		unsigned int vertexBuffer = 0;
		unsigned int vertexColorBuffer = 0;
		unsigned int vertexDiffuseBuffer = 0;
		unsigned int vertexSpecularBuffer = 0;
		unsigned int normalBuffer = 0;
		unsigned int textMapBuffer = 0;
		unsigned int indexBuffer = 0;
		unsigned int faceCount = 0;
		Mesh* mesh;
	};

#endif