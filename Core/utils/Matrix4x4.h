#ifndef __ENGINE__UTILS_MATRIX_4_4_
#define __ENGINE__UTILS_MATRIX_4_4_

	class Matrix4x4 {
	
	private:	
		float matrix[16];

	public:
		Matrix4x4();
		~Matrix4x4();

		float* operator[](const int&);
		Matrix4x4 operator*(Matrix4x4);
		Matrix4x4 inverse();
		Matrix4x4 transpose();
		void print();
	};

#endif