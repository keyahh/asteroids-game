#include "BigExplosion.h"

BigExplosion::BigExplosion(sf::Texture* texture, float duration, int rows, int cols)
	: Particle(texture, duration, rows, cols)
{
	setScale(6.f, 6.f);
}

BigExplosion::BigExplosion(sf::Texture* texture, const sf::Vector2f& startPos, float duration, int rows, int cols)
	: Particle(texture, duration, rows, cols)
{
	setScale(6.f, 6.f);
	setPosition(startPos);
}

void BigExplosion::update(float dt)
{
	playAnimation(0, dt);
	Particle::update(dt);
}
