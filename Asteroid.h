#ifndef ASTEROIDH
#define ASTEROIDH

#include "Entity.h"

class Asteroid : public Entity
{
private:
	int value = 0;
	float rotation = 0, animationRotation = 0; //rotation is direction asteroid is flying in, animationRotation is the sprite spinning
	float rotationTime = 0.1, rotationProgress = 0;
	bool clockWise = true;

public:
	Asteroid();
	Asteroid(sf::Texture* texture, int value);
	Asteroid(sf::Texture* texture, int value, float rotation);
	Asteroid(sf::Texture* texture, int value, float rotation, const sf::Vector2f& startPos);

	virtual void update(const float& dt, sf::RenderWindow* window, sf::View& view);

	const float getRotation() const;
	void setRotation(float rotation);
};

#endif