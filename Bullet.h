#ifndef BULLETH
#define BULLETH

#include "Entity.h"

class Bullet : public Entity
{
private:
	bool fromPlayer, canKill = false;
	float rotation, maxTravelTime = 10.0f, travelTime = 0.0f;

public:
	Bullet();
	Bullet(sf::Texture* texture, float rotation, const sf::Vector2f& startPos, bool fromPlayer = false);
	void update(const float& dt, sf::RenderWindow* window, sf::View& view);
	void move(const sf::Vector2f& vec, float dt);
	const bool getCanKill() const;
};

#endif
