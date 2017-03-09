#ifndef __ENGINE__UTILS_VECTOR_4_
#define __ENGINE__UTILS_VECTOR_4_

	class Vector4 {
	
	private:	
		float vector[4];

	public:
		Vector4();
		Vector4(float,float,float,float);
		~Vector4();

		float x();
		float y();
		float z();
		float w();

		void x(float);
		void y(float);
		void z(float);
		void w(float);
		float magnitude();
		void normalize();
		float dot(Vector4);
		Vector4 lerp(Vector4, float);
		
		Vector4 operator*(const float);
		Vector4 operator*(const double);
		Vector4 operator+(Vector4);
		Vector4 operator-(Vector4);
	};

#endif