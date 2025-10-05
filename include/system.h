#pragma once
#include <particle.h>
#include <vector>

class System {
private:
	std::vector<Particle> particles;
public:
	void Render();
	void handleUserInput();
	void AddParticle(Vector2 position);

	void Update();
};
