#include "Planet.h"

Planet::Planet(sf::Texture* texture, const sf::Vector2f& startPos)
	: Entity(texture, 3, 4, EntityType::PLANET)
{
	value = 2000;
	setRowCol(rand() % 12, rand() % 12);
	setPosition(startPos);
}

void Planet::update(float dt, sf::RenderWindow* window, sf::View& view)
{
}

const int Planet::getValue() const
{
	return value;
}
