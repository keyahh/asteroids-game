#include "Ufo.h"

Ufo::Ufo()
{
}

Ufo::Ufo(sf::Texture* texture, const sf::Vector2f& startPos)
	: Entity(texture, 1, 1, EntityType::UFO)
{
	setPosition(startPos);
	speed = 150;
}

void Ufo::update(float dt)
{
	setOrigin({ getLocalBounds().width / 2, getLocalBounds().height / 2 });

	if (!canShoot)
	{//shooting cool down
		shootCDTime += dt;
		if (shootCDTime >= shootCD)
		{
			canShoot = true;
			shootCDTime = 0.0;
		}
	}
}

const int Ufo::getValue() const
{
	return value;
}

bool Ufo::getCanShoot() const
{
	return canShoot;
}

void Ufo::setCanShoot(bool flag)
{
	canShoot = flag;
}
