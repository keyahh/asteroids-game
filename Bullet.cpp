#include "Bullet.h"

Bullet::Bullet()
	: Bullet(nullptr, 0, {0,0}, true)
{
}

Bullet::Bullet(sf::Texture* texture, float rotation, const sf::Vector2f& startPos, bool fromPlayer)
	: Entity(texture, 1, 1, BULLET), rotation(rotation), fromPlayer(fromPlayer)
{
	speed = 800;
	setPosition(startPos);
	setRotation(rotation);
	if (!fromPlayer)
	{
		value = -100;
	}
}

void Bullet::update(float dt)
{
	setOrigin({ getLocalBounds().width / 2, getLocalBounds().height / 2 });
	travelTime += dt;
	if (travelTime >= maxTravelTime) //bullet gets deleted in gamestate update
	{//no need to reset travelTime
		canKill = true;
	}
	
	double radian = (rotation - 90) * (3.141593 / 180);
	sf::Vector2f direction = {static_cast<float>(cos(radian)), static_cast<float>(sin(radian))};
	Entity::move(direction, dt);
}

const int Bullet::getValue() const
{
	return value;
}

const bool Bullet::getCanKill() const
{
	return canKill;
}
