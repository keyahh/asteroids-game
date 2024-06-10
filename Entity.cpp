#include "Entity.h"

Entity::Entity()
{
}

//Entity::Entity(const std::string& texturePath, int rows, int cols)
//	: AnimatedSpriteSheet(texturePath, rows, cols)
//{
//}

Entity::Entity(sf::Texture* texture, int rows, int cols, EntityType type)
	: AnimatedSpriteSheet(texture, rows, cols), type(type)
{
}

void Entity::setAnimation(int row, int cols)
{
	std::vector<Frame> frames;
	float x = 0, y = row * getRect().height;
	for (int i = 0; i < cols; i++)
	{
		frames.push_back(Frame({ x, y }, 0.15));
		x += getRect().width;
	}
	Animation ani(*this, getRect(), frames, true);
	addAnimation(ani);
}

void Entity::move(const sf::Vector2f& vec, float dt)
{
	Sprite::move({ vec.x * speed * dt, vec.y * speed * dt });
}

void Entity::update(float dt)
{
}

void Entity::update(float dt, sf::RenderWindow* window, sf::View& view)
{
}

void Entity::update(float dt, sf::RenderWindow& window, sf::View& view)
{
}

void Entity::hit()
{
}

const bool Entity::getCanKill() const
{
	return canKill;
}

void Entity::kill()
{
	canKill = true;
}

const EntityType& Entity::getType() const
{
	return type;
}

