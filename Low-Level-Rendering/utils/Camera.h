#ifndef __ENGINE__UTILS_CAMERA_
#define __ENGINE__UTILS_CAMERA_

	#include "../../Core/utils/Vector3.h"
	
	struct Camera {
		Vector3 position; 
		Vector3 focus; 
		Vector3 orientation; 
	};

#endif