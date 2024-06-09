#ifndef ASTEROIDH
#define ASTEROIDH

#include "Entity.h"

class Asteroid : public Entity
{
private:
	int value = 0;
	float rotation = 0, rotationTime = 0.1f, rotationProgress = 0.f;

public:
	Asteroid();
	Asteroid(sf::Texture* texture, int value);
	Asteroid(sf::Texture* texture, int value, float rotation);
	Asteroid(sf::Texture* texture, int value, float rotation, const sf::Vector2f& startPos, EntityType type = ASTEROID_LARGE, int baseSpeed = 100);

	virtual void update(float dt, sf::RenderWindow* window, sf::View& view);
	virtual void update(float dt, sf::RenderWindow& window, sf::View& view);

	const float getRotation() const;
	virtual const int getValue() const;
	void setRotation(float rotation);

};

#endif