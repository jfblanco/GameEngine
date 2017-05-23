#include "Camera.h"
#include <iostream>

Camera::Camera(){

}

Camera::~Camera(){
	
}

void Camera::lookAt(Vector3 position, Vector3 viewPoint, Vector3 up){
	Vector3 viewDirection = viewPoint - position;
	viewDirection.normalize();
	
	up.normalize();
	Vector3 left = up.cross(viewDirection);
	left.normalize();
	
	Vector3 newUp = viewDirection.cross(left);

	this->viewMatrix[0][0] = left.x(); this->viewMatrix[0][1] = newUp.x(); this->viewMatrix[0][2] = viewDirection.x(); this->viewMatrix[0][3] = position.x();
	this->viewMatrix[1][0] = left.y(); this->viewMatrix[1][1] = newUp.y(); this->viewMatrix[1][2] = viewDirection.y(); this->viewMatrix[1][3] = position.y();
	this->viewMatrix[2][0] = left.z(); this->viewMatrix[2][1] = newUp.z(); this->viewMatrix[2][2] = viewDirection.z(); this->viewMatrix[2][3] = position.z();
	this->viewMatrix[3][0] = 0.0;	 this->viewMatrix[3][1] = 0.0; 	   this->viewMatrix[3][2] = 0.0;   this->viewMatrix[3][3] = 1.0;
}

void Camera::print(){
	this->viewMatrix.print();
}

Matrix4x4 Camera::getViewMatrix(){
	return this->viewMatrix;
}

float* Camera::getViewMatrixAsPointer(){
	return this->viewMatrix.toFloatPointer();
}