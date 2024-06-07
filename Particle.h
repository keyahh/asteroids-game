#ifndef PARTICLEH
#define PARTICLEH

#include "AnimatedSpriteSheet.h"

class Particle : public AnimatedSpriteSheet
{
private:
	float duration = 0.f, durationTimer = 0.f;
	bool canKill = false;

public:
	Particle(sf::Texture* texture = nullptr, float duration = 0.f, int rows = 1, int cols = 1);

	virtual void update(float dt);
	virtual void setAnimation(int row, int cols);

	const bool getCanKill() const;
	void setCanKill(bool flag);
};

#endif