#ifndef __ENGINE__UTILS_CAMERA_
#define __ENGINE__UTILS_CAMERA_

	#include "../../Core/utils/Matrix4x4.h"
	#include "../../Core/utils/Vector3.h"
	
	class Camera {
		
		private:
			Matrix4x4 viewMatrix; 

		public:
			Camera();
			~Camera();
			void lookAt(Vector3 position, Vector3 viewPoint, Vector3 up);	
			Matrix4x4 getViewMatrix();
			float* getViewMatrixAsPointer();
			void print();
	};

#endif