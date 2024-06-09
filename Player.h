#ifndef PLAYERH
#define PLAYERH

#include "Entity.h"
#include "Bullet.h"
#include <cmath>

class Player : public Entity
{
private:
	float shootCD = 0.2f, shootCDProgress = 0.0f, iFrames = 0.4f, iFrameProgress = 0.0f;
	bool canShoot = false, shot = false, invulnerable = false;

public:

	Player();
	Player(sf::Texture* texture);

	//virtual void move(const sf::Vector2f& vec, float dt);
	virtual void update(float dt, sf::RenderWindow& window, sf::View& view);
	virtual const int getValue() const;

	bool checkKeyPress() const;
	const float getSpeed() const;
	const bool getCanMove() const;
	const bool checkShot() const;
	const bool getInvul() const;

	void setCanMove(bool flag);
	void setCanShoot(bool flag);
	void setShot(bool flag);
	void setInvul(bool flag);

	void hit();
};

#endif