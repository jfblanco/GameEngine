#include <iostream>
#include <iomanip> 
#include <bitset>
#include <math.h> 
#include "../../Core/utils/Matrix3x3.h"
#include "../../Core/utils/Matrix4x4.h"

bool cmpf(float,float);

int main(int argc, char** args){

	Matrix3x3 matrix3;
	Matrix3x3 matrix3r;
	Matrix3x3 resu3x3;

	Matrix4x4 matrix4;
	Matrix4x4 matrix4r;
	Matrix4x4 resu4x4;

	matrix3[0][0] = 6.0;matrix3[0][1] = 1.0;matrix3[0][2] = 5.0;
	matrix3[1][0] = 2.0;matrix3[1][1] = 2.0;matrix3[1][2] = 4.0;
	matrix3[2][0] = 8.0;matrix3[2][1] = 3.0;matrix3[2][2] = 7.0;

	matrix3r[0][0] = 1.0;matrix3r[0][1] = 2.0;matrix3r[0][2] = 3.0;
	matrix3r[1][0] = 4.0;matrix3r[1][1] = 5.0;matrix3r[1][2] = 6.0;
	matrix3r[2][0] = 7.0;matrix3r[2][1] = 8.0;matrix3r[2][2] = 9.0;

	matrix4[0][0] = 11.0;matrix4[0][1] = 12.0;matrix4[0][2] = 13.0;matrix4[0][3] = 13.0;
	matrix4[1][0] = 24.0;matrix4[1][1] = 25.0;matrix4[1][2] = 26.0;matrix4[1][3] = 13.0;
	matrix4[2][0] = 37.0;matrix4[2][1] = 38.0;matrix4[2][2] = 39.0;matrix4[2][3] = 13.0;
	matrix4[3][0] = 40.0;matrix4[3][1] = 44.0;matrix4[3][2] = 47.0;matrix4[3][3] = -13.0;

	matrix4r[0][0] = 13.0;matrix4r[0][1] = 12.0;matrix4r[0][2] = 5.0;matrix4r[0][3] = 4.0;
	matrix4r[1][0] = 14.0;matrix4r[1][1] = 11.0;matrix4r[1][2] = 6.0;matrix4r[1][3] = 3.0;
	matrix4r[2][0] = 15.0;matrix4r[2][1] = 10.0;matrix4r[2][2] = 7.0;matrix4r[2][3] = 2.0;
	matrix4r[3][0] = 16.0;matrix4r[3][1] = 9.0;matrix4r[3][2] = 8.0;matrix4r[3][3] = 1.0;
	
	resu3x3 = matrix3 * matrix3r;
	
	if(resu3x3[0][0] == 45.0 && resu3x3[0][1] == 57.0 && resu3x3[0][2] == 69.0 &&
	   resu3x3[1][0] == 38.0 && resu3x3[1][1] == 46.0 && resu3x3[1][2] == 54.0 &&
	   resu3x3[2][0] == 69.0 && resu3x3[2][1] == 87.0 && resu3x3[2][2] == 105.0)
		std::cout << "\033[38;5;2mOK:\033[0m Matrix3x3 multiplication is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m Matrix3x3 multiplication is not working" << std::endl;

	resu3x3 = matrix3.transpose();

	if(resu3x3[0][0] == 6.0 && resu3x3[0][1] == 2.0 && resu3x3[0][2] == 8.0 &&
	   resu3x3[1][0] == 1.0 && resu3x3[1][1] == 2.0 && resu3x3[1][2] == 3.0 &&
	   resu3x3[2][0] == 5.0 && resu3x3[2][1] == 4.0 && resu3x3[2][2] == 7.0)
		std::cout << "\033[38;5;2mOK:\033[0m Matrix3x3 transpose is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m Matrix3x3 transpose is not working" << std::endl;

	matrix3[0][0] = 1.0;matrix3[0][1] = 0.0;matrix3[0][2] = 0.0;
	matrix3[1][0] = 0.0;matrix3[1][1] = 1.0;matrix3[1][2] = -1.0;
	matrix3[2][0] = 0.0;matrix3[2][1] = 1.0;matrix3[2][2] = 1.0;

	resu3x3 = matrix3.inverse();

	if(resu3x3[0][0] == 1.0 && resu3x3[0][1] == 0.0 && resu3x3[0][2] == 0.0 &&
	   resu3x3[1][0] == 0.0 && resu3x3[1][1] == 0.5 && resu3x3[1][2] == 0.5 &&
	   resu3x3[2][0] == 0.0 && resu3x3[2][1] == -0.5 && resu3x3[2][2] == 0.5)
		std::cout << "\033[38;5;2mOK:\033[0m Matrix3x3 inverse is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m Matrix3x3 inverse is not working" << std::endl;

	matrix3[0][0] = 1.0;matrix3[0][1] = 2.0;matrix3[0][2] = 3.0;
	matrix3[1][0] = 4.0;matrix3[1][1] = 5.0;matrix3[1][2] = 6.0;
	matrix3[2][0] = 7.0;matrix3[2][1] = 8.0;matrix3[2][2] = 9.0;

	resu3x3 = matrix3.inverse();

	if(resu3x3[0][0] == 1.0 && resu3x3[0][1] == 0.0 && resu3x3[0][2] == 0.0 &&
	   resu3x3[1][0] == 0.0 && resu3x3[1][1] == 1.0 && resu3x3[1][2] == 0.0 &&
	   resu3x3[2][0] == 0.0 && resu3x3[2][1] == 0.0 && resu3x3[2][2] == 1.0)
		std::cout << "\033[38;5;2mOK:\033[0m Matrix3x3 inverse with determinant zero is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m Matrix3x3 inverse with determinant zero is not working" << std::endl;

	resu4x4 = matrix4 * matrix4r;

	if(resu4x4[0][0] == 714.0 && resu4x4[0][1] == 511.0 && resu4x4[0][2] == 322.0 && resu4x4[0][3] == 119.0 &&
	   resu4x4[1][0] == 1260.0 && resu4x4[1][1] == 940.0 && resu4x4[1][2] == 556.0 && resu4x4[1][3] == 236.0 &&
	   resu4x4[2][0] == 1806.0 && resu4x4[2][1] == 1369.0 && resu4x4[2][2] == 790.0 && resu4x4[2][3] == 353.0 &&
	   resu4x4[3][0] == 1633.0 && resu4x4[3][1] == 1317.0 && resu4x4[3][2] == 689.0 && resu4x4[3][3] == 373.0)
		std::cout << "\033[38;5;2mOK:\033[0m Matrix4x4 multiplication is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m Matrix4x4 multiplication is not working" << std::endl;

	resu4x4 = matrix4.transpose();

	if(resu4x4[0][0] == 11.0 && resu4x4[0][1] == 24.0 && resu4x4[0][2] == 37.0 && resu4x4[0][3] == 40.0 &&
	   resu4x4[1][0] == 12.0 && resu4x4[1][1] == 25.0 && resu4x4[1][2] == 38.0 && resu4x4[1][3] == 44.0 &&
	   resu4x4[2][0] == 13.0 && resu4x4[2][1] == 26.0 && resu4x4[2][2] == 39.0 && resu4x4[2][3] == 47.0 &&
	   resu4x4[3][0] == 13.0 && resu4x4[3][1] == 13.0 && resu4x4[3][2] == 13.0 && resu4x4[3][3] == -13.0)
		std::cout << "\033[38;5;2mOK:\033[0m Matrix4x4 transpose is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m Matrix4x4 transpose is not working" << std::endl;

	matrix4[0][0] = 1.0;matrix4[0][1] = 0.0;matrix4[0][2] = 1.0;matrix4[0][3] = 0.0;
	matrix4[1][0] = 0.0;matrix4[1][1] = 1.0;matrix4[1][2] = 0.0;matrix4[1][3] = 0.0;
	matrix4[2][0] = -1.0;matrix4[2][1] = 0.0;matrix4[2][2] = 1.0;matrix4[2][3] = 0.0;
	matrix4[3][0] = 0.0;matrix4[3][1] = 0.0;matrix4[3][2] = 0.0;matrix4[3][3] = 1.0;

	resu4x4 = matrix4.inverse();

	if(resu4x4[0][0] == 0.5 && resu4x4[0][1] == 0.0 && resu4x4[0][2] == -0.5 && resu4x4[0][3] == 0.0 &&
	   resu4x4[1][0] == 0.0 && resu4x4[1][1] == 1.0 && resu4x4[1][2] == 0.0 && resu4x4[1][3] == 0.0 &&
	   resu4x4[2][0] == 0.5 && resu4x4[2][1] == 0.0 && resu4x4[2][2] == 0.5 && resu4x4[2][3] == 0.0 &&
	   resu4x4[3][0] == 0.0 && resu4x4[3][1] == 0.0 && resu4x4[3][2] == 0.0 && resu4x4[3][3] == 1.0)
		std::cout << "\033[38;5;2mOK:\033[0m Matrix4x4 inverse is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m Matrix4x4 inverse is not working" << std::endl;

	matrix4[0][0] = 1.0;matrix4[0][1] = 2.0;matrix4[0][2] = 3.0;matrix4[0][3] = 4.0;
	matrix4[1][0] = 5.0;matrix4[1][1] = 6.0;matrix4[1][2] = 7.0;matrix4[1][3] = 8.0;
	matrix4[2][0] = 9.0;matrix4[2][1] = 10.0;matrix4[2][2] = 11.0;matrix4[2][3] = 12.0;
	matrix4[3][0] = 13.0;matrix4[3][1] = 14.0;matrix4[3][2] = 15.0;matrix4[3][3] = 16.0;

	resu4x4 = matrix4.inverse();

	if(resu4x4[0][0] == 1.0 && resu4x4[0][1] == 0.0 && resu4x4[0][2] == 0.0 && resu4x4[0][3] == 0.0 &&
	   resu4x4[1][0] == 0.0 && resu4x4[1][1] == 1.0 && resu4x4[1][2] == 0.0 && resu4x4[1][3] == 0.0 &&
	   resu4x4[2][0] == 0.0 && resu4x4[2][1] == 0.0 && resu4x4[2][2] == 1.0 && resu4x4[2][3] == 0.0 &&
	   resu4x4[3][0] == 0.0 && resu4x4[3][1] == 0.0 && resu4x4[3][2] == 0.0 && resu4x4[3][3] == 1.0)
		std::cout << "\033[38;5;2mOK:\033[0m Matrix4x4 inverse when determinant is zero is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m Matrix4x4 inverse when determinant is zero is not working" << std::endl;

	resu4x4 = Matrix4x4();
	resu4x4.translationMatrix(50.0, 25.0, 167.0);

	if(resu4x4[0][0] == 1.0 && resu4x4[0][1] == 0.0 && resu4x4[0][2] == 0.0 && resu4x4[0][3] == 0.0 &&
	   resu4x4[1][0] == 0.0 && resu4x4[1][1] == 1.0 && resu4x4[1][2] == 0.0 && resu4x4[1][3] == 0.0 &&
	   resu4x4[2][0] == 0.0 && resu4x4[2][1] == 0.0 && resu4x4[2][2] == 1.0 && resu4x4[2][3] == 0.0 &&
	   resu4x4[3][0] == 50.0 && resu4x4[3][1] == 25.0 && resu4x4[3][2] == 167.0 && resu4x4[3][3] == 1.0)
		std::cout << "\033[38;5;2mOK:\033[0m Matrix4x4 translation matrix is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m Matrix4x4 translation matrix is not working" << std::endl;

	resu4x4 = Matrix4x4();
	resu4x4.rotationX(45.0);

	if(resu4x4[0][0] == 1.0 && resu4x4[0][1] == 0.0 && resu4x4[0][2] == 0.0 && resu4x4[0][3] == 0.0 &&
	   resu4x4[1][0] == 0.0 && resu4x4[1][1] == 0.70710676908493041992 && resu4x4[1][2] == 0.70710676908493041992 && resu4x4[1][3] == 0.0 &&
	   resu4x4[2][0] == 0.0 && resu4x4[2][1] == -0.70710676908493041992 && resu4x4[2][2] == 0.70710676908493041992 && resu4x4[2][3] == 0.0 &&
	   resu4x4[3][0] == 0.0 && resu4x4[3][1] == 0.0 && resu4x4[3][2] == 0.0 && resu4x4[3][3] == 1.0)
		std::cout << "\033[38;5;2mOK:\033[0m Matrix4x4 rotation X matrix is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m Matrix4x4 rotation X matrix is not working" << std::endl;

	resu4x4 = Matrix4x4();
	resu4x4.rotationY(124.0);

	if(cmpf(resu4x4[0][0],-0.559192) && resu4x4[0][1] == 0.0 && cmpf(resu4x4[0][2],-0.829037) && resu4x4[0][3] == 0.0 &&
	   resu4x4[1][0] == 0.0 && resu4x4[1][1] == 1.0 && resu4x4[1][2] == 0.0 && resu4x4[1][3] == 0.0 &&
	   cmpf(resu4x4[2][0],0.829037) && resu4x4[2][1] == 0.0 && cmpf(resu4x4[2][2],-0.559192) && resu4x4[2][3] == 0.0 &&
	   resu4x4[3][0] == 0.0 && resu4x4[3][1] == 0.0 && resu4x4[3][2] == 0.0 && resu4x4[3][3] == 1.0)
		std::cout << "\033[38;5;2mOK:\033[0m Matrix4x4 rotation Y matrix is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m Matrix4x4 rotation Y matrix is not working" << std::endl;

	resu4x4 = Matrix4x4();
	resu4x4.rotationZ(180.0);

	if(cmpf(resu4x4[0][0],-1.0) && cmpf(resu4x4[0][1], 0.0) && resu4x4[0][2] == 0.0 && resu4x4[0][3] == 0.0 &&
	   cmpf(resu4x4[1][0],0.0) && cmpf(resu4x4[1][1],-1.0) && resu4x4[1][2] == 0.0 && resu4x4[1][3] == 0.0 &&
	   resu4x4[2][0] == 0.0&& resu4x4[2][1] == 0.0 && resu4x4[2][2] == 1.0 && resu4x4[2][3] == 0.0 &&
	   resu4x4[3][0] == 0.0 && resu4x4[3][1] == 0.0 && resu4x4[3][2] == 0.0 && resu4x4[3][3] == 1.0)
		std::cout << "\033[38;5;2mOK:\033[0m Matrix4x4 rotation Z matrix is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m Matrix4x4 rotation Z matrix is not working" << std::endl;

	resu4x4 = Matrix4x4();
	resu4x4.rotationMatrix(124.0, 90.0, 341.0);

	if(cmpf(resu4x4[0][0], 0.0)      && cmpf(resu4x4[0][1], 0.0)      && cmpf(resu4x4[0][2],-1.0)      && resu4x4[0][3] == 0.0 &&
	   cmpf(resu4x4[1][0], 0.601815) && cmpf(resu4x4[1][1],-0.798635) && cmpf(resu4x4[1][2],0.0) && resu4x4[1][3] == 0.0 &&
	   cmpf(resu4x4[2][0],-0.798635) && cmpf(resu4x4[2][1],-0.601815) && cmpf(resu4x4[2][2],0.0)  && resu4x4[2][3] == 0.0 &&
	   resu4x4[3][0] == 0.0          && resu4x4[3][1] == 0.0          && resu4x4[3][2] == 0.0          && resu4x4[3][3] == 1.0)
		std::cout << "\033[38;5;2mOK:\033[0m Matrix4x4 rotation Z matrix is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m Matrix4x4 rotation Z matrix is not working" << std::endl;

	resu4x4 = Matrix4x4();
	resu4x4.scaleMatrix(2.0);
	
	if(resu4x4[0][0] == 2.0 && resu4x4[0][1] == 0.0 && resu4x4[0][2] == 0.0 && resu4x4[0][3] == 0.0 &&
	   resu4x4[1][0] == 0.0 && resu4x4[1][1] == 2.0 && resu4x4[1][2] == 0.0 && resu4x4[1][3] == 0.0 &&
	   resu4x4[2][0] == 0.0 && resu4x4[2][1] == 0.0 && resu4x4[2][2] == 2.0 && resu4x4[2][3] == 0.0 &&
	   resu4x4[3][0] == 0.0 && resu4x4[3][1] == 0.0 && resu4x4[3][2] == 0.0 && resu4x4[3][3] == 1.0)
		std::cout << "\033[38;5;2mOK:\033[0m Matrix4x4 scale matrix is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m Matrix4x4 scale matrix is not working" << std::endl;

	resu4x4 = Matrix4x4();
	resu4x4.scaleMatrix(2.0, 3.0, 5.0);
	
	if(resu4x4[0][0] == 2.0 && resu4x4[0][1] == 0.0 && resu4x4[0][2] == 0.0 && resu4x4[0][3] == 0.0 &&
	   resu4x4[1][0] == 0.0 && resu4x4[1][1] == 3.0 && resu4x4[1][2] == 0.0 && resu4x4[1][3] == 0.0 &&
	   resu4x4[2][0] == 0.0 && resu4x4[2][1] == 0.0 && resu4x4[2][2] == 5.0 && resu4x4[2][3] == 0.0 &&
	   resu4x4[3][0] == 0.0 && resu4x4[3][1] == 0.0 && resu4x4[3][2] == 0.0 && resu4x4[3][3] == 1.0)
		std::cout << "\033[38;5;2mOK:\033[0m Matrix4x4 scale with three parameters matrix is working" << std::endl;
	else
		std::cout << "\033[1;31mERROR:\033[0m Matrix4x4 scale matrix three parameters is not working" << std::endl;
}

bool cmpf(float A, float B)
{
	float epsilon = 0.005f;
    return (fabs(A - B) < epsilon);
}