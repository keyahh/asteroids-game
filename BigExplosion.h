#ifndef BIGEXPLOSIONH
#define BIGEXPLOSIONH

#include "Particle.h"

class BigExplosion : public Particle
{
private:

public:
	BigExplosion(sf::Texture* texture = nullptr, float duration = 0.5f, int rows = 1, int cols = 5);
	BigExplosion(sf::Texture* texture = nullptr, const sf::Vector2f& startPos = { 0.f, 0.f }, float duration = 0.5f, int rows = 1, int cols = 5);

	virtual void update(float dt);
};

#endif