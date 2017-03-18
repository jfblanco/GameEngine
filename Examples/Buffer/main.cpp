#include <iostream>
#include "../../Core/utils/Mesh.h"
#include "../../Core/utils/Actor.h"
#include "../../Core/utils/Buffer.h"

int main(int argc, char** args){
	Mesh mesh;
	mesh.id = 1;
	mesh.tag = "first";

	Mesh mesh1;	
	mesh1.id = 1;
	mesh1.tag = "second";

	Mesh mesh2;
	mesh2.id = 3;
	mesh2.tag = "thirdth";

	Mesh mesh3;
	mesh3.id = 4;
	mesh3.tag = "fourth";

	Mesh mesh4;
	mesh4.id = 5;
	mesh4.tag = "fifth";

	Buffer<Mesh> buffer;

	buffer.insert(&mesh);
	buffer.insert(&mesh1);
	buffer.insert(&mesh2);
	buffer.insert(&mesh3);
	buffer.insert(&mesh4);

	Mesh* newMesh = buffer.get(4);
	std::cout << newMesh->tag.toChar() << std::endl;
}