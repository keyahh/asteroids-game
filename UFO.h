#ifndef UFOH
#define UFOH

#include "Entity.h"

class UFO : public Entity
{
public:
	UFO();
	UFO(sf::Texture* texture, const sf::Vector2f& startPos);

	virtual void update(float dt, sf::RenderWindow& window, sf::View& view);
	virtual const int getValue() const;
};

#endif