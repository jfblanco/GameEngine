#ifndef __ENGINE__UTILS_RENDERABLE_MESH_
#define __ENGINE__UTILS_RENDERABLE_MESH_

	#include "../../Core/utils/Vector3.h"
	#include "../../Core/utils/ShortString.h"
	#include "../../Core/utils/BufferItem.h"

	class Mesh {
		public:
			unsigned int vertexArrayObject = 0;
			unsigned int vertexBuffer = 0;
			unsigned int vertexColorBuffer = 0;
			unsigned int vertexDiffuseBuffer = 0;
			unsigned int vertexSpecularBuffer = 0;
			unsigned int normalBuffer = 0;
			unsigned int textMapBuffer = 0;
			unsigned int indexBuffer = 0;
			unsigned int vertexCount = 0;
			unsigned int vertexColorCount = 0;
			unsigned int diffuseVertexColorCount = 0;
			unsigned int specularVertexColorCount = 0;
			unsigned int normalCount = 0;
			unsigned int faceCount = 0;
			unsigned int textureMapCount = 0;
			Vector3* vertexs; 
			Vector3* normals; 
			Vector3* vertexColors;
			Vector3* diffuses;
			Vector3* speculars;
			Vector3* textures; 		
			unsigned int* faces;

			Mesh();
			~Mesh();	
	};

#endif