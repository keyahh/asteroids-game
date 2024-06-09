#include "Planet.h"

Planet::Planet(sf::Texture* texture, const sf::Vector2f& startPos, int row, int col)
	: Entity(texture, 3, 4, EntityType::PLANET)
{
	setRowCol(row, col);
	setPosition(startPos);

	float scale = rand() % 6 + 7;
	setScale(scale, scale);
	//setOrigin({ getLocalBounds().width / 2, getLocalBounds().height / 2 });
}

void Planet::update(float dt, sf::RenderWindow& window, sf::View& view)
{
	setOrigin({ getLocalBounds().width / 2, getLocalBounds().height / 2 });
}

const int Planet::getValue() const
{
	return value;
}

void Planet::hit()
{
	lives--;
	if (lives <= 0)
	{
		canKill = true;
	}
}
