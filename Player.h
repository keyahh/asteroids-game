#ifndef PLAYERH
#define PLAYERH

#include "Entity.h"
#include "Bullet.h"
#include <cmath>

class Player : public Entity
{
private:
	float shootCD = 0.2;
	float shootCDProgress = 0.0;
	bool canShoot = false, shot = false;

public:

	Player();
	Player(sf::Texture* texture);

	//virtual void move(const sf::Vector2f& vec, float dt);
	virtual void update(const float& dt, sf::RenderWindow* window, sf::View& view);

	bool checkKeyPress() const;
	const float getSpeed() const;
	const bool getCanMove() const;
	const bool checkShot() const;

	void setCanShoot(bool flag);
	void setShot(bool flag);

};

#endif