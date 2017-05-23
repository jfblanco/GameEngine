#include "TickEvent.h"
#include "../../../Low-Level-Rendering/utils/Mesh.h"
#include <iostream>

TickEvent::TickEvent(){
	pitch = 0.0;
	roll = 0.0;
	yaw = 0.0;

	position.translationMatrix(0.0, 0.0, -500.0);
	rotation.rotationMatrix(pitch, roll, yaw);
}

TickEvent::~TickEvent(){

}

void TickEvent::excecute(Mesh* _mesh, unsigned int _tick){	
	roll  -= 0.0001;
	rotation.rotationMatrix(pitch, roll, yaw);	
	//position.translationMatrix(pitch, roll, yaw);
	_mesh->modelMatrix = rotation * position;
}