#include "Particle.h"


Particle::Particle(sf::Texture* texture, float duration, int rows, int cols)
	: AnimatedSpriteSheet(texture, rows, cols), duration(duration)
{
	for (int i = 0; i < rows; i++)
	{
		setAnimation(i, cols);
	}
}


void Particle::setAnimation(int row, int cols)
{
	std::vector<Frame> frames;
	float x = 0, y = row * getRect().height;
	for (int i = 0; i < cols; i++)
	{
		frames.push_back(Frame({ x, y }, 0.15));
		x += getRect().width;
	}
	Animation ani(*this, getRect(), frames, true);
	addAnimation(ani);
}

const bool Particle::getCanKill() const
{
	return canKill;
}

void Particle::setCanKill(bool flag)
{
	canKill = flag;
}

void Particle::update(float dt)
{
	durationTimer += dt;
	if (durationTimer >= duration)
	{
		canKill = true;
	}
}
