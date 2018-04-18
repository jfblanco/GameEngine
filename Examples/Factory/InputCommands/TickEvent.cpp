#include "TickEvent.h"
#include "../../../Core/utils/Actor.h"
#include <iostream>

TickEvent::TickEvent(){
	pitch = 0.0;
	roll = 0.0;
	yaw = 0.0;

	position.translationMatrix(0.0, 0.0, -1000.0);
	rotation.rotationMatrix(pitch, roll, yaw);
}

TickEvent::~TickEvent(){

}

void TickEvent::excecute(Actor* _actor, unsigned int _tick){	
	roll  -= 0.0001;
	rotation.rotationMatrix(pitch, roll, yaw);	
	//position.translationMatrix(pitch, roll, yaw);
	position.print();
	_actor->modelMatrix = rotation * position;
}