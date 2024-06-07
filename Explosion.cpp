#include "Explosion.h"

Explosion::Explosion(sf::Texture* texture, float duration, int rows, int cols)
	: Particle(texture, duration, rows, cols)
{
	setScale(1.4f, 1.4f);
}

Explosion::Explosion(sf::Texture* texture, const sf::Vector2f& startPos, float duration, int rows, int cols)
	: Particle(texture, duration, rows, cols)
{
	setScale(1.4f, 1.4f);
	setPosition(startPos);
}

void Explosion::update(float dt)
{
	playAnimation(0, dt);
	Particle::update(dt);
}