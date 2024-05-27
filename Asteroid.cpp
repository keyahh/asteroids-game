#include "Asteroid.h"

Asteroid::Asteroid()
{
}

Asteroid::Asteroid(sf::Texture* texture, int value)
	: Asteroid(texture, value, 0)
{

}

Asteroid::Asteroid(sf::Texture* texture, int value, float rotation)
	: Entity(texture, 1, 1), value(value), rotation(rotation)
{
}

void Asteroid::update(const float& dt, sf::RenderWindow* window, sf::View& view)
{
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