#ifndef __ENGINE__UTILS_MESH_
#define __ENGINE__UTILS_MESH_

	#include "Vector3.h"
	#include "ShortString.h"
	#include "BufferItem.h"

	struct Mesh : BufferItem{
		unsigned int vertexCount = 0;
		unsigned int normalCount = 0;
		unsigned int faceCount = 0;
		unsigned int textureMapCount = 0;
		Vector3* vertexs; 
		Vector3* normals; 
		Vector3* textures; 
		unsigned int* faces; 
	};

#endif