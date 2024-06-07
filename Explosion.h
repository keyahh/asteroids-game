#ifndef EXPLOSIONH
#define EXPLOSIONH

#include "Particle.h"

class Explosion : public Particle
{
private:

public:
	Explosion(sf::Texture* texture = nullptr, float duration = 0.5f, int rows = 1, int cols = 6);
	Explosion(sf::Texture* texture = nullptr, const sf::Vector2f& startPos = {0.f, 0.f}, float duration = 0.5f, int rows = 1, int cols = 6);

	virtual void update(float dt);
};

#endif