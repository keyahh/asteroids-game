#include "Asteroid.h"

Asteroid::Asteroid()
{
}

Asteroid::Asteroid(sf::Texture* texture, int value)
	: Asteroid(texture, value, 0, {0, 0})
{

}

Asteroid::Asteroid(sf::Texture* texture, int value, float rotation)
	: Asteroid(texture, value, rotation, { 0, 0 }, ASTEROID_LARGE, 80)
{

}

Asteroid::Asteroid(sf::Texture* texture, int value, float rotation, const sf::Vector2f& startPos, EntityType type, int baseSpeed)
	: Entity(texture, 1, 1, type), value(value), rotation(rotation)
{
	speed = rand() % (baseSpeed * 2 - baseSpeed + 1) + baseSpeed;
	setPosition(startPos);
	setScale(3.f,3.f);
}

void Asteroid::update(float dt)
{
	setOrigin({ getLocalBounds().width / 2, getLocalBounds().height / 2 });
	double radian = (rotation - 90) * (3.141593 / 180);
	sf::Vector2f direction = { static_cast<float>(cos(radian)), static_cast<float>(sin(radian)) };
	move(direction, dt);
}

const float Asteroid::getRotation() const
{
	return rotation;
}

const int Asteroid::getValue() const
{
	return value;
}

void Asteroid::setRotation(float rotation)
{
	Asteroid::rotation = rotation;
}