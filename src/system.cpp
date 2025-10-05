#include <system.h>
#include <iostream>
#include <rlgl.h>
#include <raymath.h>

void System::handleUserInput(){
	if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
		AddParticle(GetMousePosition());
	}
}

void System::AddParticle(Vector2 position){
	particles.push_back(Particle( {position.x,position.y} ));
}

void System::Render(){
	for(auto& particle : particles){
		particle.Render();
	}
}

void System::Update(){
	for(auto& p1 : particles){
		for(auto& p2 : particles){
			if(p1 == p2) continue;
			Vector2 pos1 = p1.getPosition();
			Vector2 pos2 = p2.getPosition();
			float dist = Vector2Distance(pos1, pos2); 
														
			Vector2 diff = Vector2Subtract(pos2, pos1);
			float angle = atan2f(diff.y, diff.x);
			float magX = 1.0f / dist * cos(angle);
			float magY = 1.0f / dist * sin(angle);
			p1.UpdateAcceleration({-magX, -magY});
			p2.UpdateAcceleration({magX, magY});
		}
	}

	for (Particle& particle : particles) {
		if(particle.position.x - 50.0f <= 0){
			particle.UpdateVelocity({-particle.velocity.x,particle.velocity.y});
		}
		if(particle.position.x + 50.0f >= GetScreenWidth()){
			particle.UpdateVelocity({-particle.velocity.x,particle.velocity.y});
		}
		if(particle.position.y - 50.0f <= 0){
			particle.UpdateVelocity({particle.velocity.x,-particle.velocity.y});
		}
		if(particle.position.y + 50.0f >= GetScreenWidth()){
			particle.UpdateVelocity({particle.velocity.x,-particle.velocity.y});
		}
		particle.UpdateVelocity();
		particle.Update();
	}
}
