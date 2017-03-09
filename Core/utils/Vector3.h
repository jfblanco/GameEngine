#ifndef __ENGINE__UTILS_VECTOR_3_
#define __ENGINE__UTILS_VECTOR_3_

	class Vector3 {
	
	private:	
		float vector[3];

	public:
		Vector3();
		Vector3(float,float,float);
		~Vector3();

		float x();
		float y();
		float z();

		void x(float);
		void y(float);
		void z(float);
		float magnitude();
		void normalize();
		float dot(Vector3);
		Vector3 cross(Vector3);
		Vector3 lerp(Vector3, float);
		
		Vector3 operator*(const float);
		Vector3 operator*(const double);
		Vector3 operator+(Vector3);
		Vector3 operator-(Vector3);
	};

#endif