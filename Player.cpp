#include "Player.h"

Player::Player()
	: Entity(nullptr, 1, 1)
{
	/*for (int i = 0; i < 4; i++)
	{
		setAnimation(i);
	}*/
	setScale(0.3, 0.3);
	speed = 2;
}

Player::Player(sf::Texture* texture)
	: Entity(texture, 1, 1)
{
	setScale(0.3, 0.3);
	speed = 2;
}

void Player::update(const float& dt, sf::RenderWindow* window, sf::View& view)
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

	setOrigin({getLocalBounds().width / 2, getLocalBounds().height / 2});

	if(canMove)
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
		sf::Vector2f inViewPos = window->mapPixelToCoords({mousePos.x, mousePos.y}, view);
		float rotation = (atan2(inViewPos.y - getPosition().y, inViewPos.x - getPosition().x) * (180 / 3.141593)) + 90;
		setRotation(rotation);

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

void Player::setCanShoot(bool flag)
{
	canShoot = flag;
}

void Player::setShot(bool flag)
{
	shot = flag;
}
