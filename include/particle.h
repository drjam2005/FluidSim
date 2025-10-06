#pragma once
#include <raylib.h>

class Particle {
	Vector2 position;
	Vector2 velocity = {0.0f, 0.0f};
	Vector2 acceleration = {0.0f, 0.0f};
public:
	Color clr = WHITE;
	Particle(Vector2 position);
	Particle(Vector2 position, Color clr);
	Particle(Vector2 position, Vector2 velocity);
	Particle(Vector2 position, Vector2 velocity, Vector2 acceleration);

	Vector2 getPosition();
	Vector2 getVelocity();
	Vector2 getAcceleration();

	void Render();
	void Update();
	void UpdateVelocity();
	void UpdateVelocity(Vector2 velocity);
	void UpdatePosition(Vector2 position);
	void UpdateAcceleration(Vector2 acceleration);

	bool operator==(Particle& otherParticle){
		if(
			this->position.x == otherParticle.position.x && 
			this->position.y == otherParticle.position.y && 
			this->velocity.y == otherParticle.velocity.y && 
			this->velocity.y == otherParticle.velocity.y && 
			this->acceleration.y == otherParticle.acceleration.y && 
			this->acceleration.y == otherParticle.acceleration.y 
		  )
			return true;

		return false;
	}
};
