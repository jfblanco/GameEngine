#include "Matrix4x4.h"
#include <iostream>

Matrix4x4::Matrix4x4(){
	matrix[0]=1.0;matrix[1]=0.0;matrix[2]=0.0;matrix[3]=0.0;
	matrix[4]=0.0;matrix[5]=1.0;matrix[6]=0.0;matrix[7]=0.0;
	matrix[8]=0.0;matrix[9]=0.0;matrix[10]=1.0;matrix[11]=0.0;
	matrix[12]=0.0;matrix[13]=0.0;matrix[14]=0.0;matrix[15]=1.0;
}

Matrix4x4::~Matrix4x4(){
	
}

float* Matrix4x4::operator[](const int& _position){
	return (matrix + (_position * 4));
}

Matrix4x4 Matrix4x4::operator*(Matrix4x4 _matrix){
	Matrix4x4 resu;
	resu[0][0] = matrix[0] * _matrix[0][0] + matrix[1] * _matrix[1][0] + matrix[2] * _matrix[2][0] + matrix[3] * _matrix[3][0];
	resu[0][1] = matrix[0] * _matrix[0][1] + matrix[1] * _matrix[1][1] + matrix[2] * _matrix[2][1] + matrix[3] * _matrix[3][1];
	resu[0][2] = matrix[0] * _matrix[0][2] + matrix[1] * _matrix[1][2] + matrix[2] * _matrix[2][2] + matrix[3] * _matrix[3][2];
	resu[0][3] = matrix[0] * _matrix[0][3] + matrix[1] * _matrix[1][3] + matrix[2] * _matrix[2][3] + matrix[3] * _matrix[3][3];

	resu[1][0] = matrix[4] * _matrix[0][0] + matrix[5] * _matrix[1][0] + matrix[6] * _matrix[2][0] + matrix[7] * _matrix[3][0];
	resu[1][1] = matrix[4] * _matrix[0][1] + matrix[5] * _matrix[1][1] + matrix[6] * _matrix[2][1] + matrix[7] * _matrix[3][1];
	resu[1][2] = matrix[4] * _matrix[0][2] + matrix[5] * _matrix[1][2] + matrix[6] * _matrix[2][2] + matrix[7] * _matrix[3][2];
	resu[1][3] = matrix[4] * _matrix[0][3] + matrix[5] * _matrix[1][3] + matrix[6] * _matrix[2][3] + matrix[7] * _matrix[3][3];
	
	resu[2][0] = matrix[8] * _matrix[0][0] + matrix[9] * _matrix[1][0] + matrix[10] * _matrix[2][0] + matrix[11] * _matrix[3][0];
	resu[2][1] = matrix[8] * _matrix[0][1] + matrix[9] * _matrix[1][1] + matrix[10] * _matrix[2][1] + matrix[11] * _matrix[3][1];
	resu[2][2] = matrix[8] * _matrix[0][2] + matrix[9] * _matrix[1][2] + matrix[10] * _matrix[2][2] + matrix[11] * _matrix[3][2];
	resu[2][3] = matrix[8] * _matrix[0][3] + matrix[9] * _matrix[1][3] + matrix[10] * _matrix[2][3] + matrix[11] * _matrix[3][3];

	resu[3][0] = matrix[12] * _matrix[0][0] + matrix[13] * _matrix[1][0] + matrix[14] * _matrix[2][0] + matrix[15] * _matrix[3][0];
	resu[3][1] = matrix[12] * _matrix[0][1] + matrix[13] * _matrix[1][1] + matrix[14] * _matrix[2][1] + matrix[15] * _matrix[3][1];
	resu[3][2] = matrix[12] * _matrix[0][2] + matrix[13] * _matrix[1][2] + matrix[14] * _matrix[2][2] + matrix[15] * _matrix[3][2];
	resu[3][3] = matrix[12] * _matrix[0][3] + matrix[13] * _matrix[1][3] + matrix[14] * _matrix[2][3] + matrix[15] * _matrix[3][3];
	return resu;
}

Matrix4x4 Matrix4x4::inverse(){

}

Matrix4x4 Matrix4x4::transpose(){
	Matrix4x4 resu;
	resu[0][0] = matrix[0];
	resu[0][1] = matrix[4];
	resu[0][2] = matrix[8];
	resu[0][3] = matrix[12];

	resu[1][0] = matrix[1];
	resu[1][1] = matrix[5];
	resu[1][2] = matrix[9];
	resu[1][3] = matrix[13];
	
	resu[2][0] = matrix[2];
	resu[2][1] = matrix[6];
	resu[2][2] = matrix[10];
	resu[2][3] = matrix[14];

	resu[3][0] = matrix[3];
	resu[3][1] = matrix[7];
	resu[3][2] = matrix[11];
	resu[3][3] = matrix[15];
	return resu;
}

void Matrix4x4::print(){
	std::cout << matrix[0] << " - " << matrix[1] << " - " << matrix[2] << " - " << matrix[3] << std::endl;
	std::cout << matrix[4] << " - " << matrix[5] << " - " << matrix[6] << " - " << matrix[7] << std::endl;
	std::cout << matrix[8] << " - " << matrix[9] << " - " << matrix[10] << " - " << matrix[11] << std::endl;
	std::cout << matrix[12] << " - " << matrix[13] << " - " << matrix[14] << " - " << matrix[15] << std::endl;
}