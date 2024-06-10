#ifndef BULLETH
#define BULLETH

#include "Entity.h"

class Bullet : public Entity
{
private:
	bool fromPlayer;
	float rotation, maxTravelTime = 5.0f, travelTime = 0.0f;
	int value;

public:
	Bullet();
	Bullet(sf::Texture* texture, float rotation, const sf::Vector2f& startPos, bool fromPlayer = false);
	virtual void update(float dt);
	virtual const int getValue() const;
	const bool getCanKill() const;
};

#endif
