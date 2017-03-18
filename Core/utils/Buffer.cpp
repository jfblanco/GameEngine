#include "Buffer.h"
#include "Mesh.h"
#include "Actor.h"
#include "Material.h"
#include "Shader.h"
#include <iostream>
#include <cstdint>
#include <cstring>

template <typename T> Buffer<T>::Buffer(){
	lenght = 0;
}
		
template <typename T> Buffer<T>::~Buffer(){

}

template <typename T> T* Buffer<T>::get(int _index){

}

template <typename T> void Buffer<T>::insert(T* _object){

}

template <>
Buffer<Mesh>::Buffer(){
	lenght = 0;
}
		
template <>
Buffer<Mesh>::~Buffer(){

}

template <>
Mesh* Buffer<Mesh>::get(int _index){
	return (Mesh*) &(buffer[index[_index]]);
}

template <>
void Buffer<Mesh>::insert(Mesh* _object){	
	index[lenght] = lenght * sizeof (*_object);
	std::memcpy(&(buffer[index[lenght]]), _object, sizeof (*_object));
	lenght++;	
}

template <>
Buffer<Actor>::Buffer(){
	lenght = 0;
}
		
template <>
Buffer<Actor>::~Buffer(){

}

template <>
Actor* Buffer<Actor>::get(int _index){

}

template <>
void Buffer<Actor>::insert(Actor* _object){

}

template <>
Buffer<Material>::Buffer(){
	lenght = 0;
}
		
template <>
Buffer<Material>::~Buffer(){

}

template <>
Material* Buffer<Material>::get(int _index){

}

template <>
void Buffer<Material>::insert(Material* _object){

}

template <>
Buffer<Shader>::Buffer(){
	lenght = 0;
}
		
template <>
Buffer<Shader>::~Buffer(){

}

template <>
Shader* Buffer<Shader>::get(int _index){

}

template <>
void Buffer<Shader>::insert(Shader* _object){

}