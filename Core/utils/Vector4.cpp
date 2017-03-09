#include "Vector4.h"
#include <math.h>

Vector4::Vector4(){
	this->vector[0] = 0.0;
	this->vector[1] = 0.0;
	this->vector[2] = 0.0;
	this->vector[3] = 0.0;
}

Vector4::Vector4(float x, float y, float z, float w){
	this->vector[0] = x;
	this->vector[1] = y;
	this->vector[2] = z;
	this->vector[3] = w;
}

Vector4::~Vector4(){
	
}

Vector4 Vector4::operator*(const float _scalar){
	this->vector[0] *= _scalar;
	this->vector[1] *= _scalar;
	this->vector[2] *= _scalar;
	this->vector[3] *= _scalar;
	return *this;
}

Vector4 Vector4::operator*(const double _scalar){
	this->vector[0] *= _scalar;
	this->vector[1] *= _scalar;
	this->vector[2] *= _scalar;
	this->vector[3] *= _scalar;
	return *this;
}

Vector4 Vector4::operator+(Vector4 _vector){
	this->vector[0] += _vector.x();
	this->vector[1] += _vector.y();
	this->vector[2] += _vector.z();
	this->vector[3] += _vector.w();
	return *this;
}

Vector4 Vector4::operator-(Vector4 _vector){
	this->vector[0] -= _vector.x();
	this->vector[1] -= _vector.y();
	this->vector[2] -= _vector.z();
	this->vector[3] -= _vector.w();
	return *this;
}

float Vector4::magnitude(){
	return sqrt(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2) + pow(vector[3], 2));
}

void Vector4::normalize(){
	float magnitude  = this->magnitude();
	if(magnitude != 0.0){
		float reciprocal = 1 / magnitude;
		this->vector[0] *= reciprocal;
		this->vector[1] *= reciprocal;
		this->vector[2] *= reciprocal;
		this->vector[3] *= reciprocal;
	}
}

float Vector4::dot(Vector4 _vector){
	return (this->vector[0] * _vector.x()) + (this->vector[1] * _vector.y()) + (this->vector[2] * _vector.z()) + (this->vector[3] * _vector.w());
}

Vector4 Vector4::lerp(Vector4 _vector, float _scalar){
	Vector4 result;
	result.x((1.0 - _scalar) * this->vector[0] + _scalar * _vector.x());
	result.y((1.0 - _scalar) * this->vector[1] + _scalar * _vector.y());
	result.z((1.0 - _scalar) * this->vector[2] + _scalar * _vector.z());
	result.w((1.0 - _scalar) * this->vector[3] + _scalar * _vector.w());
	return result;
}

float Vector4::x(){
	return this->vector[0];
}

float Vector4::y(){
	return this->vector[1];
}

float Vector4::z(){
	return this->vector[2];
}

float Vector4::w(){
	return this->vector[3];
}

void Vector4::x(float _x){
	this->vector[0] = _x;
}
		
void Vector4::y(float _y){
	this->vector[1] = _y;
}

void Vector4::z(float _z){
	this->vector[2] = _z;
}

void Vector4::w(float _w){
	this->vector[3] = _w;
}