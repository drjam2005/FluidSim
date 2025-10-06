#include <particle.h>

Particle::Particle(Vector2 position){
	this->position = position;
}

Particle::Particle(Vector2 position, Color clr){
	this->position = position;
	this->clr = clr;
}
Particle::Particle(Vector2 position, Vector2 velocity){
	this->position = position;
	this->velocity = velocity;
}

Particle::Particle(Vector2 position, Vector2 velocity, Vector2 acceleration){
	this->position = position;
	this->velocity = velocity;
	this->acceleration = acceleration;
}
void Particle::Update(){
	this->position.x += this->velocity.x * GetFrameTime();
	this->position.y += this->velocity.y * GetFrameTime();
}

void Particle::UpdateVelocity(){
	this->velocity.x += this->acceleration.x * GetFrameTime();
	this->velocity.y += this->acceleration.y * GetFrameTime();
}

void Particle::UpdateVelocity(Vector2 velocity){
	this->velocity = velocity;
}

void Particle::UpdateAcceleration(Vector2 acceleration){
	this->acceleration = acceleration;
}

void Particle::UpdatePosition(Vector2 position){
	this->position = position;
}

void Particle::Render(){
	DrawCircle(position.x, position.y, 5.0f, clr);
}

Vector2 Particle::getPosition(){
	return this->position;
}

Vector2 Particle::getVelocity(){
	return this->velocity;
}
Vector2 Particle::getAcceleration(){
	return this->acceleration;
}
