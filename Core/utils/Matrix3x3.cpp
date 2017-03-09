#include "Matrix3x3.h"
#include <iostream>

Matrix3x3::Matrix3x3(){
	matrix[0]=1.0;matrix[1]=0.0;matrix[2]=0.0;
	matrix[3]=0.0;matrix[4]=1.0;matrix[5]=0.0;
	matrix[6]=0.0;matrix[7]=0.0;matrix[8]=1.0;
}

Matrix3x3::~Matrix3x3(){
	
}

float* Matrix3x3::operator[](const int& _position){
	return (matrix + (_position * 3));
}

Matrix3x3 Matrix3x3::operator*(Matrix3x3 _matrix){
	Matrix3x3 resu;
	resu[0][0] = matrix[0] * _matrix[0][0] + matrix[1] * _matrix[1][0] + matrix[2] * _matrix[2][0];
	resu[0][1] = matrix[0] * _matrix[0][1] + matrix[1] * _matrix[1][1] + matrix[2] * _matrix[2][1];
	resu[0][2] = matrix[0] * _matrix[0][2] + matrix[1] * _matrix[1][2] + matrix[2] * _matrix[2][2];

	resu[1][0] = matrix[3] * _matrix[0][0] + matrix[4] * _matrix[1][0] + matrix[5] * _matrix[2][0];
	resu[1][1] = matrix[3] * _matrix[0][1] + matrix[4] * _matrix[1][1] + matrix[5] * _matrix[2][1];
	resu[1][2] = matrix[3] * _matrix[0][2] + matrix[4] * _matrix[1][2] + matrix[5] * _matrix[2][2];
	
	resu[2][0] = matrix[6] * _matrix[0][0] + matrix[7] * _matrix[1][0] + matrix[8] * _matrix[2][0];
	resu[2][1] = matrix[6] * _matrix[0][1] + matrix[7] * _matrix[1][1] + matrix[8] * _matrix[2][1];
	resu[2][2] = matrix[6] * _matrix[0][2] + matrix[7] * _matrix[1][2] + matrix[8] * _matrix[2][2];
	return resu;
}


Matrix3x3 Matrix3x3::inverse(){

}

Matrix3x3 Matrix3x3::transpose(){
	Matrix3x3 resu;
	resu[0][0] = matrix[0];
	resu[0][1] = matrix[3];
	resu[0][2] = matrix[6];

	resu[1][0] = matrix[1];
	resu[1][1] = matrix[4];
	resu[1][2] = matrix[7];
	
	resu[2][0] = matrix[2];
	resu[2][1] = matrix[5];
	resu[2][2] = matrix[8];
	return resu;
}

void Matrix3x3::print(){
	std::cout << matrix[0] << " - " << matrix[1] << " - " << matrix[2] << std::endl;
	std::cout << matrix[3] << " - " << matrix[4] << " - " << matrix[5] << std::endl;
	std::cout << matrix[6] << " - " << matrix[7] << " - " << matrix[8] << std::endl;
}