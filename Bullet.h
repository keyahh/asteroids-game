#ifndef BULLETH
#define BULLETH

#include "Entity.h"

class Bullet : public Entity
{
private:
	bool fromPlayer;
	float rotation, maxTravelTime = 5.0f, travelTime = 0.0f;

public:
	Bullet();
	Bullet(sf::Texture* texture, float rotation, const sf::Vector2f& startPos, bool fromPlayer = false);
	virtual void update(const float& dt, sf::RenderWindow* window, sf::View& view);
	void move(const sf::Vector2f& vec, float dt);
	const bool getCanKill() const;
};

#endif
