#ifndef PLAYERH
#define PLAYERH

#include "Entity.h"
#include "Bullet.h"
#include <cmath>

class Player : public Entity
{
private:
	//void setAnimation(int row);
	float shootCD = 0.2;
	float shootCDProgress = 0.0;
	bool shootFlag = false;

public:

	Player();

	//virtual void move(const sf::Vector2f& vec, float dt);
	void update(const float& dt, sf::RenderWindow* window, sf::View& view, std::vector<Bullet>& bullets, const std::vector<sf::Texture*>& textures);

	bool checkKeyPress() const;
	const float getSpeed() const;
	const bool getCanMove() const;
};

#endif