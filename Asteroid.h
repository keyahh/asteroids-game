#ifndef ASTEROIDH
#define ASTEROIDH

#include "Entity.h"

class Asteroid : public Entity
{
private:
	int value = 0;
	float rotation, animationRotation; //rotation is direction asteroid is flying in, animationRotation is the sprite spinning

public:
	Asteroid();
	Asteroid(sf::Texture* texture, int value);
	Asteroid(sf::Texture* texture, int value, float rotation);

	virtual void update(const float& dt, sf::RenderWindow* window, sf::View& view);

	const float getRotation() const;
	void setRotation(float rotation);
};

#endif