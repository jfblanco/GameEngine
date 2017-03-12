#ifndef __ENGINE__UTILS_MATRIX_4_4_
#define __ENGINE__UTILS_MATRIX_4_4_

	class Vector4;

	class Matrix4x4 {
	
	private:	
		float matrix[16];

	public:
		Matrix4x4();
		~Matrix4x4();

		float* operator[](const int&);
		Matrix4x4 operator*(Matrix4x4);
		Vector4 operator*(Vector4);
		Matrix4x4 inverse();
		Matrix4x4 transpose();
		void translationMatrix(float, float, float);
		void rotationX(float);
		void rotationY(float);
		void rotationZ(float);
		void rotationMatrix(float,float,float);
		void scaleMatrix(float);
		void scaleMatrix(float,float,float);
		void print();
	};

#endif