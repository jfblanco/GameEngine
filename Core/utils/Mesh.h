#ifndef __ENGINE__UTILS_MESH_
#define __ENGINE__UTILS_MESH_

	#include "Vector3.h"
	#include "ShortString.h"

	struct Mesh{
		unsigned int id;
		ShortString tag;
		unsigned int vertex_count;
		unsigned int normal_count;
		unsigned int face_count;
		unsigned int texture_map_count;
		Vector3* vertexs; 
		Vector3* normals; 
		Vector3* textures; 
		unsigned int* faces; 
	};

#endif