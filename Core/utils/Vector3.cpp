#include "Vector3.h"
#include <math.h>

Vector3::Vector3(){
	this->vector[0] = 0.0;
	this->vector[1] = 0.0;
	this->vector[2] = 0.0;
}

Vector3::Vector3(float x, float y, float z){
	this->vector[0] = x;
	this->vector[1] = y;
	this->vector[2] = z;
}

Vector3::~Vector3(){
	
}

Vector3 Vector3::operator*(const float _scalar){
	this->vector[0] *= _scalar;
	this->vector[1] *= _scalar;
	this->vector[2] *= _scalar;
	return *this;
}

Vector3 Vector3::operator*(const double _scalar){
	this->vector[0] *= _scalar;
	this->vector[1] *= _scalar;
	this->vector[2] *= _scalar;
	return *this;
}

Vector3 Vector3::operator+(Vector3 _vector){
	this->vector[0] += _vector.x();
	this->vector[1] += _vector.y();
	this->vector[2] += _vector.z();
	return *this;
}

Vector3 Vector3::operator-(Vector3 _vector){
	this->vector[0] -= _vector.x();
	this->vector[1] -= _vector.y();
	this->vector[2] -= _vector.z();
	return *this;
}

float Vector3::magnitude(){
	return sqrt(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2));
}

void Vector3::normalize(){
	float magnitude  = this->magnitude();
	if(magnitude != 0.0){
		float reciprocal = 1 / magnitude;
		this->vector[0] *= reciprocal;
		this->vector[1] *= reciprocal;
		this->vector[2] *= reciprocal;
	}
}

float Vector3::dot(Vector3 _vector){
	return (this->vector[0] * _vector.x()) + (this->vector[1] * _vector.y()) + (this->vector[2] * _vector.z());
}

Vector3 Vector3::cross(Vector3 _vector){
	Vector3 result;
	result.x(this->vector[1] * _vector.z() - this->vector[2] * _vector.y());
	result.y(this->vector[2] * _vector.x() - this->vector[0] * _vector.z());
	result.z(this->vector[0] * _vector.y() - this->vector[1] * _vector.x());
	return result;
}

Vector3 Vector3::lerp(Vector3 _vector, float _scalar){
	Vector3 result;
	result.x((1.0 - _scalar) * this->vector[0] + _scalar * _vector.x());
	result.y((1.0 - _scalar) * this->vector[1] + _scalar * _vector.y());
	result.z((1.0 - _scalar) * this->vector[2] + _scalar * _vector.z());
	return result;
}

float Vector3::x(){
	return this->vector[0];
}

float Vector3::y(){
	return this->vector[1];
}

float Vector3::z(){
	return this->vector[2];
}

void Vector3::x(float _x){
	this->vector[0] = _x;
}
		
void Vector3::y(float _y){
	this->vector[1] = _y;
}

void Vector3::z(float _z){
	this->vector[2] = _z;
}