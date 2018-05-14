#include <iostream>
#include <iomanip> 
#include <bitset>
#include "../../Core/utils/Vector2.h"
#include "../../Core/utils/Vector3.h"
#include "../../Core/utils/Vector4.h"
#include "../../Debugging/ConsoleOutput.h"

int main(int argc, char** args){
	Vector2 v2;
	Vector3 v3;
	
	Vector2 v2r;
	Vector3 v3r;

	Vector4 v4;
	Vector4 v4r;

	v2.x(1.5f);
	v2.y(14.3f);
	v2r = v2 * 2.0f;
	if(v2r.x() == 3.0f && v2r.y() == 28.6f)
    	ConsoleOutput::getInstance()->success("Vector2 scalar multiplication is working");
	else
    	ConsoleOutput::getInstance()->error("Vector2 scalar multiplication is not working");

	v2.x(10.0f);
	v2.y(20.0f);
	v2r.x(11.0f);
	v2r.y(22.0f);
	v2 + v2r;
	if(v2.x() == 21.0f && v2.y() == 42.0f)
    	ConsoleOutput::getInstance()->success("Vector2 addition is working");
	else
    	ConsoleOutput::getInstance()->error("Vector2 addition is not working");

	v2.x(11.0f);
	v2.y(22.0f);
	v2r.x(10.0f);
	v2r.y(20.0f);
	v2 - v2r;
	if(v2.x() == 1.0f && v2.y() == 2.0f)
    	ConsoleOutput::getInstance()->success("Vector2 substraction is working");
	else
    	ConsoleOutput::getInstance()->error("Vector2 substraction is not working");

	v2.x(45.0f);
	v2.y(84.0f);
	if(v2.magnitude() == 95.29428f)
    	ConsoleOutput::getInstance()->success("Vector2 magnitude is working");
	else
    	ConsoleOutput::getInstance()->error("Vector2 magnitude is not working");

	v2.x(5.0f);
	v2.y(3.0f);
	v2.normalize();
	if(v2.x() == 0.85749298f && v2.y() == 0.51449579f)
    	ConsoleOutput::getInstance()->success("Vector2 normalization is working");
	else
    	ConsoleOutput::getInstance()->error("Vector2 normalization is not working");

	v2.x(4.0f);
	v2.y(8.0f);
	v2r.x(5.0f);
	v2r.y(3.0f);	
	if(v2.dot(v2r) == 44.0 && v2r.dot(v2) == 44.0)
    	ConsoleOutput::getInstance()->success("Vector2 dot product is working");
	else
    	ConsoleOutput::getInstance()->error("Vector2 dot product is not working");

	v2.x(4.0f);
	v2.y(8.0f);
	v2r.x(5.0f);
	v2r.y(3.0f);	
	Vector2 lerp2 = v2.lerp(v2r, 0.33);
	if(lerp2.x() == 4.33f && lerp2.y() == 6.35f)
    	ConsoleOutput::getInstance()->success("Vector2 LERP is working");
	else
    	ConsoleOutput::getInstance()->error("Vector2 LERP is not working");

	v3.x(4.7f);
	v3.y(5.9f);
	v3.z(12.3f);
	v3r = v3 * 5.0f;
	if(v3r.x() == 23.5f && v3r.y() == 29.5f && v3r.z() == 61.5f)
    	ConsoleOutput::getInstance()->success("Vector3 scalar multiplication is working");
	else
    	ConsoleOutput::getInstance()->error("Vector3 scalar multiplication is not working");

	v3.x(10.0f);
	v3.y(20.0f);
	v3.z(30.0f);
	v3r.x(11.0f);
	v3r.y(22.0f);
	v3r.z(33.0f);
	v3 + v3r;
	if(v3.x() == 21.0f && v3.y() == 42.0f && v3.z() == 63.0f)
    	ConsoleOutput::getInstance()->success("Vector3 addition is working");
	else
    	ConsoleOutput::getInstance()->error("Vector3 addition is not working");

	v3.x(10.0f);
	v3.y(20.0f);
	v3.z(30.0f);
	v3r.x(11.0f);
	v3r.y(22.0f);
	v3r.z(33.0f);
	v3r - v3;
	if(v3r.x() == 1.0f && v3r.y() == 2.0f && v3r.z() == 3.0f)
    	ConsoleOutput::getInstance()->success("Vector3 substraction is working");
	else
    	ConsoleOutput::getInstance()->error("Vector3 substraction is not working");

	v3.x(11.0f);
	v3.y(22.0f);
	v3.z(33.0f);
	if(v3.magnitude() == 41.15823f)
    	ConsoleOutput::getInstance()->success("Vector3 magnitude is working");
	else
    	ConsoleOutput::getInstance()->error("Vector3 magnitude is not working");

	v3.x(7.0f);
	v3.y(6.0f);
	v3.z(4.0f);
	v3.normalize();
	if(v3.x() == 0.696526050568f && v3.y() == 0.597022354603f && v3.z() == 0.398014903069f)
    	ConsoleOutput::getInstance()->success("Vector3 normalization is working");
	else
    	ConsoleOutput::getInstance()->error("Vector3 normalization is not working");

	v3.x(2.0f);
	v3.y(23.0f);
	v3.z(18.0f);
	v3r.x(45.0f);
	v3r.y(6.0f);	
	v3r.z(81.0f);	
	if(v3r.dot(v3) == 1686.0 && v3.dot(v3r) == 1686.0)
    	ConsoleOutput::getInstance()->success("Vector3 dot product is working");
	else
    	ConsoleOutput::getInstance()->error("Vector3 dot product is not working");

	v3.x(2.0f);
	v3.y(23.0f);
	v3.z(18.0f);
	v3r.x(45.0f);
	v3r.y(6.0f);	
	v3r.z(81.0f);	
	Vector3 cross = v3.cross(v3r);
	Vector3 conmutativeCross = v3r.cross(v3);
	if(cross.x() == 1755.0f && cross.y() == 648.0f && cross.z() == -1023.0f && 
		conmutativeCross.x() == -1755.0f && conmutativeCross.y() == -648.0f && conmutativeCross.z() == 1023.0f)
    	ConsoleOutput::getInstance()->success("Vector3 cross product is working");
	else
    	ConsoleOutput::getInstance()->error("Vector3 cross product is not working");

	v3.x(2.0f);
	v3.y(23.0f);
	v3.z(18.0f);
	v3r.x(45.0f);
	v3r.y(6.0f);	
	v3r.z(81.0f);		
	Vector3 lerp3 = v3.lerp(v3r, 0.45684);
	if(lerp3.x() == 21.644121f && lerp3.y() == 15.233720f && lerp3.z() == 46.780918f)
    	ConsoleOutput::getInstance()->success("Vector3 LERP is working");
	else
    	ConsoleOutput::getInstance()->error("Vector3 LERP is not working");

	v4.x(8.8f);
	v4.y(4.4f);
	v4.z(2.2f);
	v4.w(3.3f);
	v4r = v4 * 4.0f;
	if(v4r.x() == 35.2f && v4r.y() == 17.6f && v4r.z() == 8.8f && v4r.w() == 13.2f)
    	ConsoleOutput::getInstance()->success("Vector4 scalar multiplication is working");
	else
    	ConsoleOutput::getInstance()->error("Vector4 scalar multiplication is not working");

	v4.x(10.0f);
	v4.y(20.0f);
	v4.z(30.0f);
	v4.w(40.0f);
	v4r.x(11.0f);
	v4r.y(22.0f);
	v4r.z(33.0f);
	v4r.w(44.0f);
	v4 + v4r;
	if(v4.x() == 21.0f && v4.y() == 42.0f && v4.z() == 63.0f && v4.w() == 84.0f)
    	ConsoleOutput::getInstance()->success("Vector4 addition is working");
	else
    	ConsoleOutput::getInstance()->error("Vector4 addition is not working");

	v4.x(10.0f);
	v4.y(20.0f);
	v4.z(30.0f);
	v4.w(40.0f);
	v4r.x(11.0f);
	v4r.y(22.0f);
	v4r.z(33.0f);
	v4r.w(44.0f);
	v4r - v4;
	if(v4r.x() == 1.0f && v4r.y() == 2.0f && v4r.z() == 3.0f && v4r.w() == 4.0f)
    	ConsoleOutput::getInstance()->success("Vector4 substraction is working");
	else
    	ConsoleOutput::getInstance()->error("Vector4 substraction is not working");

	v4.x(3.0f);
	v4.y(5.0f);
	v4.z(8.0f);
	v4.w(13.0f);
	if(v4.magnitude() == 16.3401346384f)
    	ConsoleOutput::getInstance()->success("Vector4 magnitude is working");
	else
    	ConsoleOutput::getInstance()->error("Vector4 magnitude is not working");

	v4.x(1.0f);
	v4.y(2.0f);
	v4.z(3.0f);
	v4.w(4.0f);
	v4.normalize();
	if(v4.x() == 0.182574182749f && v4.y() == 0.365148365498f && v4.z() == 0.547722578049f && v4.w() == 0.730296730995f)
    	ConsoleOutput::getInstance()->success("Vector4 normalization is working");
	else
    	ConsoleOutput::getInstance()->error("Vector4 normalization is not working");

	v4.x(2.0f);
	v4.y(23.0f);
	v4.z(18.0f);
	v4.w(78.0f);
	v4r.x(45.0f);
	v4r.y(6.0f);	
	v4r.z(76.0f);	
	v4r.w(41.0f);	
	if(v4r.dot(v4) == 4794.0 && v4.dot(v4r) == 4794.0)
    	ConsoleOutput::getInstance()->success("Vector4 dot product is working");
	else
    	ConsoleOutput::getInstance()->error("Vector4 dot product is not working");

	v4.x(2.0f);
	v4.y(23.0f);
	v4.z(18.0f);
	v4.w(78.0f);
	v4r.x(45.0f);
	v4r.y(6.0f);	
	v4r.z(76.0f);	
	v4r.w(41.0f);		
	Vector4 lerp4 = v4.lerp(v4r, 0.50);
	if(lerp4.x() == 23.5f && lerp4.y() == 14.5f && lerp4.z() == 47.0f && lerp4.w() == 59.5f)
    	ConsoleOutput::getInstance()->success("Vector4 LERP is working");
	else
    	ConsoleOutput::getInstance()->error("Vector4 LERP is not working");

}