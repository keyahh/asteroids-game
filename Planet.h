#ifndef PLANETH
#define PLANETH

#include "Entity.h"

class Planet : public Entity
{
private:
	float ufoSpawnCD = 3.0f, ufoSpawnProgress = 0.0f;
	int ufoCount = 0, maxUFOs = 4, value = 0;
public:
	Planet();
	Planet(sf::Texture* texture);
	Planet(sf::Texture* texture, const sf::Vector2f& startPos);

	virtual void update(const float& dt, sf::RenderWindow* window, sf::View& view);
	virtual const int getValue() const;
};

#endif