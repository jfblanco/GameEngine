#ifndef __ENGINE__UTILS_MATRIX_3_3_
#define __ENGINE__UTILS_MATRIX_3_3_

	class Matrix3x3 {
	
	private:	
		float matrix[9];

	public:
		Matrix3x3();
		~Matrix3x3();

		float* operator[](const int&);
		Matrix3x3 operator*(Matrix3x3);
		Matrix3x3 inverse();
		Matrix3x3 transpose();
		void print();
	};

#endif