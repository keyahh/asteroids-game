#include "Player.h"

Player::Player()
	: Entity("images/entities/player.png", 1, 1)
{
	/*for (int i = 0; i < 4; i++)
	{
		setAnimation(i);
	}*/
	setScale(0.3, 0.3);
	speed = 2;
}

//void Player::setAnimation(int row)
//{
//	std::vector<Frame> frames;
//	float x = 0, y = row * getRect().height;
//	for (int i = 0; i < 4; i++)
//	{
//		frames.push_back(Frame({ x, y }, 0.15));
//		x += getRect().width;
//	}
//	Animation ani(*this, getRect(), frames, true);
//	addAnimation(ani);
//}

void Player::update(const float& dt, sf::RenderWindow* window, sf::View& view, std::vector<Bullet>& bullets, const std::vector<sf::Texture*>& textures)
{
	if (shootFlag) 
	{//shooting cool down
		shootCDProgress += dt;
		if (shootCDProgress >= shootCD)
		{
			shootFlag = false;
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

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !shootFlag)
		{
			shootFlag = true;
			bullets.push_back(Bullet(textures[0], rotation, getPosition(), true));
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
