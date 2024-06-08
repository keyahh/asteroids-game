#ifndef PLANETH
#define PLANETH

#include "Entity.h"

class Planet : public Entity
{
private:
	float ufoSpawnCD = 3.0f, ufoSpawnProgress = 0.0f;
	int ufoCount = 0, maxUFOs = 4, value = 0;
public:
	Planet(sf::Texture* texture = nullptr, const sf::Vector2f& startPos = {0.f,0.f});

	virtual void update(float dt, sf::RenderWindow* window, sf::View& view);
	virtual const int getValue() const;
};

#endif