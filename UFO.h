#ifndef UfoH
#define UfoH

#include "Entity.h"

class Ufo : public Entity
{
private:
	int value = 100;
	float shootCD = 1.f, shootCDTime = 0.f;
	bool canShoot = false;

public:
	Ufo();
	Ufo(sf::Texture* texture, const sf::Vector2f& startPos);

	virtual void update(float dt);
	virtual const int getValue() const;
	virtual bool getCanShoot() const;
	virtual void setCanShoot(bool flag);
};

#endif