#include "Explosion.h"

Explosion::Explosion(sf::Texture* texture, float duration, int rows, int cols)
	: Particle(texture, duration, rows, cols)
{
	
}

void Explosion::update(float dt)
{
	playAnimation(0, dt);
}