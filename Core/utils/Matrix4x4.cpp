#include "Matrix4x4.h"
#include "Vector4.h"
#include <iostream>
#include <iomanip>
#include <math.h> 
#include <cmath> 

#define PI 3.14159265

Matrix4x4::Matrix4x4(){
	matrix[0]=1.0;matrix[1]=0.0;matrix[2]=0.0;matrix[3]=0.0;
	matrix[4]=0.0;matrix[5]=1.0;matrix[6]=0.0;matrix[7]=0.0;
	matrix[8]=0.0;matrix[9]=0.0;matrix[10]=1.0;matrix[11]=0.0;
	matrix[12]=0.0;matrix[13]=0.0;matrix[14]=0.0;matrix[15]=1.0;
}

Matrix4x4::~Matrix4x4(){
	
}

float* Matrix4x4::toFloatPointer(){
	return matrix;
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

Vector4 Matrix4x4::operator*(Vector4 _vector){
	Vector4 resu = Vector4();
	resu.x(_vector.x() * matrix[0] + _vector.x() * matrix[4] + _vector.x() * matrix[8] + _vector.x() * matrix[12]);
	resu.y(_vector.y() * matrix[1] + _vector.y() * matrix[5] + _vector.y() * matrix[9] + _vector.y() * matrix[13]);
	resu.z(_vector.z() * matrix[2] + _vector.z() * matrix[6] + _vector.z() * matrix[10] + _vector.z() * matrix[14]);
	resu.w(_vector.w() * matrix[3] + _vector.w() * matrix[7] + _vector.w() * matrix[11] + _vector.w() * matrix[15]);
	return resu;
}

Matrix4x4 Matrix4x4::inverse(){

    Matrix4x4 resu;
    float det = 0.0;

    resu[0][0] = matrix[5] * matrix[10] * matrix[15] - matrix[5] * matrix[11] * matrix[14] - matrix[9] * matrix[6] * matrix[15] + 
                 matrix[9] * matrix[7]  * matrix[14] + matrix[13] * matrix[6]  * matrix[11] - matrix[13] * matrix[7]  * matrix[10];

    resu[1][0] = -matrix[4]  * matrix[10] * matrix[15] + matrix[4]  * matrix[11] * matrix[14] + matrix[8]  * matrix[6]  * matrix[15] - 
	              matrix[8]  * matrix[7]  * matrix[14] - matrix[12] * matrix[6]  * matrix[11] + matrix[12] * matrix[7]  * matrix[10];

    resu[2][0] = matrix[4]  * matrix[9] * matrix[15] - matrix[4]  * matrix[11] * matrix[13] - matrix[8]  * matrix[5] * matrix[15] + 
	             matrix[8]  * matrix[7] * matrix[13] + matrix[12] * matrix[5] * matrix[11] -  matrix[12] * matrix[7] * matrix[9];

    resu[3][0] = -matrix[4]  * matrix[9] * matrix[14] + matrix[4]  * matrix[10] * matrix[13] + matrix[8]  * matrix[5] * matrix[14] - 
	              matrix[8]  * matrix[6] * matrix[13] - matrix[12] * matrix[5] * matrix[10] +  matrix[12] * matrix[6] * matrix[9];

    resu[0][1] = -matrix[1]  * matrix[10] * matrix[15] + matrix[1]  * matrix[11] * matrix[14] + matrix[9]  * matrix[2] * matrix[15] - 
	              matrix[9]  * matrix[3] * matrix[14] -  matrix[13] * matrix[2] * matrix[11] +  matrix[13] * matrix[3] * matrix[10];

    resu[1][1] = matrix[0]  * matrix[10] * matrix[15] -  matrix[0]  * matrix[11] * matrix[14] - matrix[8]  * matrix[2] * matrix[15] + 
	             matrix[8]  * matrix[3] * matrix[14] +   matrix[12] * matrix[2] * matrix[11] -  matrix[12] * matrix[3] * matrix[10];

    resu[2][1] = -matrix[0]  * matrix[9] * matrix[15] +  matrix[0]  * matrix[11] * matrix[13] + matrix[8]  * matrix[1] * matrix[15] - 
	              matrix[8]  * matrix[3] * matrix[13] -  matrix[12] * matrix[1] * matrix[11] +  matrix[12] * matrix[3] * matrix[9];

    resu[3][1] = matrix[0]  * matrix[9] * matrix[14] -  matrix[0]  * matrix[10] * matrix[13] -  matrix[8]  * matrix[1] * matrix[14] + 
              	 matrix[8]  * matrix[2] * matrix[13] + matrix[12] * matrix[1] * matrix[10] - matrix[12] * matrix[2] * matrix[9];

    resu[0][2] = matrix[1]  * matrix[6] * matrix[15] - matrix[1]  * matrix[7] * matrix[14] - matrix[5]  * matrix[2] * matrix[15] + 
             	 matrix[5]  * matrix[3] * matrix[14] + matrix[13] * matrix[2] * matrix[7] - matrix[13] * matrix[3] * matrix[6];

    resu[1][2] = -matrix[0]  * matrix[6] * matrix[15] + matrix[0]  * matrix[7] * matrix[14] + matrix[4]  * matrix[2] * matrix[15] - 
              	 matrix[4]  * matrix[3] * matrix[14] - matrix[12] * matrix[2] * matrix[7] + matrix[12] * matrix[3] * matrix[6];

    resu[2][2] = matrix[0]  * matrix[5] * matrix[15] - matrix[0]  * matrix[7] * matrix[13] - matrix[4]  * matrix[1] * matrix[15] + 
                 matrix[4]  * matrix[3] * matrix[13] + matrix[12] * matrix[1] * matrix[7] - matrix[12] * matrix[3] * matrix[5];

    resu[3][2] = -matrix[0]  * matrix[5] * matrix[14] + matrix[0]  * matrix[6] * matrix[13] + matrix[4]  * matrix[1] * matrix[14] - 
               	 matrix[4]  * matrix[2] * matrix[13] - matrix[12] * matrix[1] * matrix[6] + matrix[12] * matrix[2] * matrix[5];

    resu[0][3] = -matrix[1] * matrix[6] * matrix[11] + matrix[1] * matrix[7] * matrix[10] + matrix[5] * matrix[2] * matrix[11] - 
              	 matrix[5] * matrix[3] * matrix[10] - matrix[9] * matrix[2] * matrix[7] + matrix[9] * matrix[3] * matrix[6];

    resu[1][3] = matrix[0] * matrix[6] * matrix[11] - matrix[0] * matrix[7] * matrix[10] - matrix[4] * matrix[2] * matrix[11] + 
                 matrix[4] * matrix[3] * matrix[10] + matrix[8] * matrix[2] * matrix[7] - matrix[8] * matrix[3] * matrix[6];

    resu[2][3] = -matrix[0] * matrix[5] * matrix[11] + matrix[0] * matrix[7] * matrix[9] + matrix[4] * matrix[1] * matrix[11] - 
                 matrix[4] * matrix[3] * matrix[9] - matrix[8] * matrix[1] * matrix[7] + matrix[8] * matrix[3] * matrix[5];

    resu[3][3] = matrix[0] * matrix[5] * matrix[10] - matrix[0] * matrix[6] * matrix[9] - matrix[4] * matrix[1] * matrix[10] + 
                 matrix[4] * matrix[2] * matrix[9] + matrix[8] * matrix[1] * matrix[6] - matrix[8] * matrix[2] * matrix[5];

    det = matrix[0] * resu[0][0] + matrix[1] * resu[1][0] + matrix[2] * resu[2][0] + matrix[3] * resu[3][0];

    if (det != 0.0){
    	det = 1.0 / det;

	    for (int i = 0; i < 4; i++)
	    	for (int j = 0; j < 4; j++) 
	        	resu[i][j] = resu[i][j] * det;	
    }else{
    	resu = Matrix4x4();
    }    

    return resu;
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


void Matrix4x4::translationMatrix(float _x, float _y, float _z){
	matrix[0] = 1.0;matrix[1] = 0.0;matrix[2] = 0.0;matrix[3] = 0.0;
	matrix[4] = 0.0;matrix[5] = 1.0;matrix[6] = 0.0;matrix[7] = 0.0;
	matrix[8] = 0.0;matrix[9] = 0.0;matrix[10] = 1.0;matrix[11] = 0.0;
	matrix[12] = _x;matrix[13] = _y;matrix[14] = _z;matrix[15] = 1.0;
}

void Matrix4x4::rotationX(float _pitch){
	float radian = (_pitch * PI) / 180; 
	float sinOfAngle = sin(radian);
	float cosOfAngle = cos(radian);

	matrix[0]  = 1.0;matrix[1]  = 0.0;matrix[2]  = 0.0;matrix[3]  = 0.0;
	matrix[4]  = 0.0;matrix[5]  = cosOfAngle;matrix[6]  = sinOfAngle;matrix[7]  = 0.0;
	matrix[8]  = 0.0;matrix[9]  = -sinOfAngle;matrix[10] = cosOfAngle;matrix[11] = 0.0;
	matrix[12] = 0.0;matrix[13] = 0.0;matrix[14] = 0.0;matrix[15] = 1.0;
}

void Matrix4x4::rotationY(float _yaw){
	float radian = (_yaw * PI) / 180; 
	float sinOfAngle = sin(radian);
	float cosOfAngle = cos(radian);

	matrix[0]  = cosOfAngle;matrix[1]  = 0.0;matrix[2]  = -sinOfAngle;matrix[3]  = 0.0;
	matrix[4]  = 0.0;matrix[5]  = 1.0;matrix[6]  = 0.0;matrix[7]  = 0.0;
	matrix[8]  = sinOfAngle;matrix[9]  = 0.0;matrix[10] = cosOfAngle;matrix[11] = 0.0;
	matrix[12] = 0.0;matrix[13] = 0.0;matrix[14] = 0.0;matrix[15] = 1.0;
}

void Matrix4x4::rotationZ(float _roll){
	float radian = (_roll * PI) / 180; 
	float sinOfAngle = sin(radian);
	float cosOfAngle = cos(radian);

	matrix[0]  = cosOfAngle;matrix[1]  = sinOfAngle;matrix[2]  = 0.0;matrix[3]  = 0.0;
	matrix[4]  = -sinOfAngle;matrix[5]  = cosOfAngle;matrix[6]  = 0.0;matrix[7]  = 0.0;
	matrix[8]  = 0.0;matrix[9]  = 0.0;matrix[10] = 1.0;matrix[11] = 0.0;
	matrix[12] = 0.0;matrix[13] = 0.0;matrix[14] = 0.0;matrix[15] = 1.0;
}

void Matrix4x4::rotationMatrix(float _pitch,float _yall,float _roll){
	Matrix4x4 pitch = Matrix4x4();
	pitch.rotationX(_pitch);
	Matrix4x4 yall = Matrix4x4();
	yall.rotationY(_yall);
	Matrix4x4 roll = Matrix4x4();
	roll.rotationZ(_roll);

	Matrix4x4 resu = pitch * yall * roll;

	matrix[0]= resu[0][0];matrix[1]=resu[0][1];matrix[2]=resu[0][2];matrix[3]=resu[0][3];
	matrix[4]= resu[1][0];matrix[5]=resu[1][1];matrix[6]=resu[1][2];matrix[7]=resu[1][3];
	matrix[8]= resu[2][0];matrix[9]=resu[2][1];matrix[10]=resu[2][2];matrix[11]=resu[2][3];
	matrix[12]=resu[3][0];matrix[13]=resu[3][1];matrix[14]=resu[3][2];matrix[15]=resu[3][3];
}

void Matrix4x4::scaleMatrix(float _size){
	matrix[0]= _size; matrix[1]= 0.0;   matrix[2]=0.0;    matrix[3]=0.0;
	matrix[4]= 0.0;   matrix[5]= _size; matrix[6]=0.0;    matrix[7]=0.0;
	matrix[8]= 0.0;   matrix[9]= 0.0;   matrix[10]=_size; matrix[11]=0.0;
	matrix[12]=0.0;   matrix[13]=0.0;   matrix[14]=0.0;   matrix[15]=1.0;	
}

void Matrix4x4::scaleMatrix(float _x,float _y,float _z){
	matrix[0]= _x;  matrix[1]= 0.0; matrix[2]=0.0;  matrix[3]=0.0;
	matrix[4]= 0.0; matrix[5]= _y;  matrix[6]=0.0;  matrix[7]=0.0;
	matrix[8]= 0.0; matrix[9]= 0.0; matrix[10]=_z;  matrix[11]=0.0;
	matrix[12]=0.0; matrix[13]=0.0; matrix[14]=0.0; matrix[15]=1.0;
}

void Matrix4x4::print(){
	std::cout << std::setprecision(20) << matrix[0] << " - " << matrix[1] << " - " << matrix[2] << " - " << matrix[3] << std::endl;
	std::cout << std::setprecision(20) << matrix[4] << " - " << matrix[5] << " - " << matrix[6] << " - " << matrix[7] << std::endl;
	std::cout << std::setprecision(20) << matrix[8] << " - " << matrix[9] << " - " << matrix[10] << " - " << matrix[11] << std::endl;
	std::cout << std::setprecision(20) << matrix[12] << " - " << matrix[13] << " - " << matrix[14] << " - " << matrix[15] << std::endl;
}


void Matrix4x4::orthoMatrix(float left, float right, float top ,float bottom, float near ,float far){
	matrix[0]= 2 / (right - left);  matrix[1]= 0.0; 				matrix[2]= 0.0;         				matrix[3]=  0.0;
	matrix[4]= 0.0; 				matrix[5]= 2 / (top - bottom);  matrix[6]= 0.0;         				matrix[7]=  0.0;
	matrix[8]= 0.0; 				matrix[9]= 0.0; 				matrix[10]= -(2 / (far - near));   		matrix[11]= ((far+near)/(far-near));
	matrix[12]=0.0;					matrix[13]=0.0;					matrix[14]= 0.0;						matrix[15]= 1.0;
}

void Matrix4x4::frustumMatrix(float left, float right, float top ,float bottom, float near ,float far){
	float height = top - bottom;
	float width = right - left;

	float w = width / 2;
	float h = height / 2;

	matrix[0]=  near/w; matrix[1]=  0.0; 	matrix[2]= 0.0;  matrix[3]= 0.0;

	matrix[4]=  0.0;  	matrix[5]= near/h;  matrix[6]= 0.0;  matrix[7]=  -((2 * far * near)/(far-near));
	
	matrix[8]=  0.0;  	matrix[9]=  0.0; 	matrix[10]= -((far+near)/(far-near));  matrix[11]= 0.0;
	
	matrix[12]= 0.0;  	matrix[13]= 0.0; 	matrix[14]= -1.0;	 matrix[15]= 0.0;
}

void Matrix4x4::perspectiveMatrix(float fovy, float aspect, float n,float f){
	
	float radians = (fovy * 0.5f) * 0.01745329252;
	float q = 1.0f / tan(radians);
    float A = q / aspect;
    float B = (n + f) / (n - f);
    float C = (2.0f * n * f) / (n - f);

    matrix[0]=    A; 	matrix[1]=  0.0;  matrix[2]= 0.0;  matrix[3]= 0.0;

	matrix[4]=  0.0;  	matrix[5]=    q;  matrix[6]= 0.0;  matrix[7]=  0.0;
	
	matrix[8]=  0.0;  	matrix[9]=  0.0;  matrix[10]=  B;  matrix[11]= -1.0;
	
	matrix[12]= 0.0;  	matrix[13]= 0.0;  matrix[14]=  C; matrix[15]= 0.0;
}