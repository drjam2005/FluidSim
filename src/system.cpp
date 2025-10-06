#include <system.h>
#include <bits/stdc++.h>
#include <math.h>
#include <rlgl.h>
#include <raymath.h>

System::System(){
	CreateParticles();
}

float ExampleFunc(Vector2 pos){
	return cos(pos.y - 3 + sin(pos.x));
}

float SmoothingKernel(float radius, float dst){
	float volume = PI * pow(radius, 8) / 4.0f;
	float value = fmax(0, (radius*radius) - (dst*dst));
	return value * value * value / volume;
}

void System::handleUserInput(){
	if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
		AddParticle(GetMousePosition());
	}
}

void System::AddParticle(Vector2 position){
	particles.push_back(Particle( {position.x,position.y} ));
}
void System::AddParticle(Vector2 position, Color clr){
	particles.push_back(Particle( {position.x,position.y},clr ));
}

void System::Render(){
	for(auto& particle : particles){
		particle.Render();
	}
}


void System::Update() {
	float gravity = 800.0f;
	//for (auto& particle : particles) {
	//	CalculateDensity(particle);
	//	particle.UpdateAcceleration(
	//		{particle.getAcceleration().x, gravity}
	//	);
	//}

	for (auto& particle : particles) {
		Vector2 position = particle.getPosition();
		Vector2 velocity = particle.getVelocity();
		if (position.y + 5.0f >= GetScreenHeight() && velocity.y > 0) {

			position.y = GetScreenHeight() - 5.0f;
			particle.UpdatePosition(position);

			velocity.y = -velocity.y * 0.8f;
			if (fabs(velocity.y) < 0.5f)
				velocity.y = 0.0f;

			particle.UpdateVelocity(velocity);
		}
		if (position.y - 5.0f <= 0 && velocity.y < 0) {

			position.y = 5.0f;
			particle.UpdatePosition(position);

			velocity.y = -velocity.y * 0.8f;
			if (fabs(velocity.y) < 0.5f)
				velocity.y = 0.0f;

			particle.UpdateVelocity(velocity);
		}
		if (position.x + 5.0f >= GetScreenWidth() && velocity.x > 0) {

			position.x = GetScreenWidth() - 5.0f;
			particle.UpdatePosition(position);

			velocity.x = -velocity.x * 0.8f;
			if (fabs(velocity.x) < 0.5f)
				velocity.x = 0.0f;

			particle.UpdateVelocity(velocity);
		}

		if (position.x - 5.0f <= 0  && velocity.x < 0) {

			position.x = 5.0f;
			particle.UpdatePosition(position);

			velocity.x = -velocity.x * 0.8f;
			if (fabs(velocity.x) < 0.5f)
				velocity.x = 0.0f;

			particle.UpdateVelocity(velocity);
		}
	}

    const float restDistance = 25.0f;
    const float stiffness = 0.01f;
    for (auto& part1 : particles) {
        for (auto& part2 : particles) {
            if (&part1 == &part2) continue;

            Vector2 pos1 = part1.getPosition();
            Vector2 pos2 = part2.getPosition();

            Vector2 dir = Vector2Subtract(pos2, pos1);
            float dist = Vector2Length(dir);
            if (dist <= 0.0001f) continue;
            if (dist < restDistance) {
                Vector2 norm = Vector2Scale(dir, 1.0f / dist);
                float diff = restDistance - dist;

                Vector2 force = Vector2Scale(norm, -diff * stiffness);

                part1.UpdateVelocity(Vector2Add(part1.getVelocity(), force));
            }
            dir = Vector2Subtract(GetMousePosition(), pos1);
            dist = Vector2Length(dir);
            if (dist < restDistance) {
                Vector2 norm = Vector2Scale(dir, 1.0f / dist);
                float diff = restDistance - dist;

                Vector2 force = Vector2Scale(norm, -diff * 0.025f);

                part1.UpdateVelocity(Vector2Add(part1.getVelocity(), force));
            }

        }
    }

	for (auto& particle : particles){
		float dampen = 0.975f;
		Vector2 accel = particle.getVelocity();
		Vector2 appliedAccel = {accel.x * dampen, accel.y * dampen};
		particle.UpdateVelocity(appliedAccel);
	}
	for (auto& particle : particles){
		particle.UpdateVelocity();
		particle.Update();
	}
}

float System::CalculateDensity(Particle& pt){
	float density = 0.0f;
	const float mass = 1.0f;

	for(auto& particle : particles){
		if(particle == pt) continue;
		float dst = Vector2Distance(particle.getPosition(), pt.getPosition());
		float influence = SmoothingKernel(smoothingRadius, dst);
		density += mass * influence;
	}

	return density;
}

void System::CreateParticles(){
	srand(time(NULL));
	for(int i = 0; i < 200; ++i){
		int x = rand() % 800;
		int y = rand() % 600;
		AddParticle({(float)x, (float)y});
	}
}
