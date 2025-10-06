#pragma once
#include <particle.h>
#include <vector>

class System {
private:
	std::vector<Particle> particles;
	int WIDTH, HEIGHT;
	float smoothingRadius = 5.0f;
public:
	System();
	void CreateParticles();
	void Update();
	void Render();
	void handleUserInput();
	void AddParticle(Vector2 position);
	void AddParticle(Vector2 position, Color clr);

	float CalculateDensity(Particle&);
	float CalculateProperty(Particle&);

};
