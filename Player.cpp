#include "Player.h"

Player::Player()
	: Entity(nullptr, 1, 1, PLAYER)
{
	
}

Player::Player(sf::Texture* texture)
	: Entity(texture, 1, 1, PLAYER)
{
	/*for (int i = 0; i < 4; i++)
	{
		setAnimation(i);
	}*/;
	setScale(0.3f, 0.3f);
	speed = 2.f;
}

void Player::update(float dt)
{
	if (!canShoot) 
	{//shooting cool down
		shootCDProgress += dt;
		if (shootCDProgress >= shootCD)
		{
			canShoot = true;
			shootCDProgress = 0.0;
		}
	}
	if (invulnerable)
	{
		iFrameProgress += dt;
		if (iFrameProgress >= iFrames)
		{
			invulnerable = false;
			iFrameProgress = 0.0f;
		}
	}

	setOrigin({getLocalBounds().width / 2, getLocalBounds().height / 2});

	if(canMove)
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			move({ -100, 0 }, dt);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			move({ 100, 0 }, dt);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			move({ 0, -100 }, dt);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			move({ 0, 100 }, dt);
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && canShoot)
		{
			shot = true;
			canShoot = false;
		}
	}
}

const int Player::getValue() const
{
	return 0;
}

bool Player::checkKeyPress() const
{
	for (int k = -1; k < sf::Keyboard::KeyCount; ++k)
	{
		if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(k)))
			return true;
	}
	return false;
}

const float Player::getSpeed() const
{
	return speed;
}

const bool Player::getCanMove() const
{
	return canMove;
}

const bool Player::checkShot() const
{
	return shot;
}

const bool Player::getInvul() const
{
	return invulnerable;
}

void Player::setCanMove(bool flag)
{
	canMove = flag;
}

void Player::setCanShoot(bool flag)
{
	canShoot = flag;
}

void Player::setShot(bool flag)
{
	shot = flag;
}

void Player::setInvul(bool flag)
{
	invulnerable = flag;
}

void Player::setRotation(float rotation)
{
	sf::Sprite::setRotation(rotation);
}

void Player::hit()
{
	invulnerable = true;
	iFrameProgress = 0.0f;
}
