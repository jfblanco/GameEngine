#ifndef __ENGINE__UTILS_BUFFER_ITEM__
#define __ENGINE__UTILS_BUFFER_ITEM__
	
	#include "ShortString.h"
	#include "Matrix4x4.h"

	enum BufferItemType{
		ACTOR = 1,
		MESH,
		MATERIEAL,
		SHADER
	};

	struct BufferItem{
		unsigned int id;
		ShortString tag;
		BufferItemType type;
		Matrix4x4 modelMatrix;
	};

#endif