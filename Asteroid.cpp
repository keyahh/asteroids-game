#include "Asteroid.h"

Asteroid::Asteroid()
{
}

Asteroid::Asteroid(sf::Texture* texture, int value)
	: Asteroid(texture, value, 0, {0, 0})
{

}

Asteroid::Asteroid(sf::Texture* texture, int value, float rotation)
	: Asteroid(texture, value, rotation, { 0, 0 })
{

}

Asteroid::Asteroid(sf::Texture* texture, int value, float rotation, const sf::Vector2f& startPos, EntityType type)
	: Entity(texture, 1, 1, type), value(value), rotation(rotation)
{
	speed = 80;
	setPosition(startPos);
	setScale(3,3);
}

void Asteroid::update(const float& dt, sf::RenderWindow* window, sf::View& view)
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

void Asteroid::setRotation(float rotation)
{
	Asteroid::rotation = rotation;
}