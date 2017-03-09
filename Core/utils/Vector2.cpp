#include "Vector2.h"
#include <math.h>

Vector2::Vector2(){
	this->vector[0] = 0.0;
	this->vector[1] = 0.0;
} 

Vector2::Vector2(float x, float y){
	this->vector[0] = x;
	this->vector[1] = y;
}

Vector2::~Vector2(){
	
}

Vector2 Vector2::operator*(const float& _scalar){
	this->vector[0] *= _scalar;
	this->vector[1] *= _scalar;
	return *this;
}

Vector2 Vector2::operator*(const double& _scalar){
	this->vector[0] *= _scalar;
	this->vector[1] *= _scalar;
	return *this;
}

Vector2 Vector2::operator+(Vector2 _vector){
	this->vector[0] += _vector.x();
	this->vector[1] += _vector.y();
	return *this;	
}

Vector2 Vector2::operator-(Vector2 _vector){
	this->vector[0] -= _vector.x();
	this->vector[1] -= _vector.y();
	return *this;
}

float Vector2::magnitude(){
	return (float) sqrt(pow(vector[0], 2) + pow(vector[1], 2));
}

void Vector2::normalize(){
	float magnitude  = this->magnitude();
	if(magnitude != 0.0){
		float reciprocal = 1 / magnitude;
		this->vector[0] *= reciprocal;
		this->vector[1] *= reciprocal;
	}
}

float Vector2::dot(Vector2 _vector){
	return (this->vector[0] * _vector.x()) + (this->vector[1] * _vector.y());
}

Vector2 Vector2::lerp(Vector2 _vector, float _scalar){
	Vector2 result;
	result.x((1.0 - _scalar) * this->vector[0] + _scalar * _vector.x());
	result.y((1.0 - _scalar) * this->vector[1] + _scalar * _vector.y());
	return result;
}

float Vector2::x(){
	return this->vector[0];
}

float Vector2::y(){
	return this->vector[1];
}

void Vector2::x(float _x){
	this->vector[0] = _x;
}
		
void Vector2::y(float _y){
	this->vector[1] = _y;
}