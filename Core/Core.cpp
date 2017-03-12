#include "Core.h"
#include "interfaces/Animation.h"
#include "interfaces/Audio.h"
#include "interfaces/ArtificialInteligense.h"
#include "interfaces/Debug.h"
#include "interfaces/FrontEnd.h"
#include "interfaces/GamePlay.h"
#include "interfaces/Input.h"
#include "interfaces/NetWork.h"
#include "interfaces/Physics.h"
#include "interfaces/Render.h"
#include "interfaces/Resources.h"
#include "interfaces/VisualEfects.h"

Core* Core::instance = 0;

Core::Core(){

}

Core* Core::getInstance(){
	if(Core::instance == 0)
		Core::instance = new Core();
	return Core::instance;
}

Core::~Core(){
	
}

void Core::start(){

}

void Core::stop(){
	this->imAlive = false;
}

void Core::begin(){
	while(this->imAlive){
		render->renderScene();
	}
}

void Core::pause(){

}

void Core::setRender(Render* _render){
	this->render = _render;
}

Render* Core::getRender(){
	return this->render;
}

void Core::setAudio(Audio* _audio){
	this->audio = _audio;
}
Audio* Core::getAudio(){
	return this->audio;
}

void Core::setArtificialInteligense(ArtificialInteligense* _artificialInteligense){
	this->artificialInteligense = _artificialInteligense;
}
		
ArtificialInteligense* Core::getArtificialInteligense(){
	return this->artificialInteligense;
}

void Core::setResources(Resources* _resources){
	this->resources = _resources;
}
		
Resources* Core::getResources(){
	return this->resources;
}

void Core::setInput(Input* _input){
	this->input = _input;
}

Input* Core::getInput(){
	return this->input;
}

void Core::setFrontEnd(FrontEnd* _frontEnd){
	this->frontEnd = _frontEnd;
}

FrontEnd* Core::getFrontEnd(){
	return this->frontEnd;
}

void Core::setAnimation(Animation* _animation){
	this->animation = _animation;
}

Animation* Core::getAnimation(){
	return this->animation;
}

void Core::setDebug(Debug* _debug){
	this->debug = _debug;
}

Debug* Core::getDebug(){
	return this->debug;
}

void Core::setGamePlay(GamePlay* _gamePlay){
	this->gamePlay = _gamePlay;
}

GamePlay* Core::getGamePlay(){
	return this->gamePlay;
}

void Core::setNetwork(Network* _netWork){
	this->netWork = _netWork;
}

Network* Core::getNetwork(){
	return this->netWork;
}

void Core::setPhysics(Physics* _physics){
	this->physics = _physics;
}

Physics* Core::getPhysics(){
	return this->physics;
}

void Core::setScene(Scene* _scene){
	this->scene = _scene;
}

Scene* Core::getScene(){
	return this->scene;
}

void Core::setVisualEfects(VisualEfects* _visualEfects){
	this->visualEfects = _visualEfects;
}

VisualEfects* Core::getVisualEfects(){
	return this->visualEfects;
}