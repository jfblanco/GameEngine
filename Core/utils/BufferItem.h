#ifndef __ENGINE__UTILS_BUFFER_ITEM__
#define __ENGINE__UTILS_BUFFER_ITEM__
	
	#include "ShortString.h"

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
	};

#endif