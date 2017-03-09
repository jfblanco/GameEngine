#ifndef __ENGINE__UTILS_VECTOR_2_
#define __ENGINE__UTILS_VECTOR_2_

	class Vector2 {
	
	private:	
		float vector[2];

	public:
		Vector2();
		Vector2(float,float);
		~Vector2();

		float x();
		float y();

		void x(float);
		void y(float);
		float magnitude();
		void normalize();
		float dot(Vector2);
		Vector2 lerp(Vector2, float);

		Vector2 operator*(const float&);
		Vector2 operator*(const double&);
		Vector2 operator+(Vector2);
		Vector2 operator-(Vector2);
	};

#endif