#include "Entity.h"

Entity::Entity()
{
}

//Entity::Entity(const std::string& texturePath, int rows, int cols)
//	: AnimatedSpriteSheet(texturePath, rows, cols)
//{
//}

Entity::Entity(sf::Texture* texture, int rows, int cols)
	: AnimatedSpriteSheet(texture, rows, cols)
{
}

void Entity::move(const sf::Vector2f& vec, float dt)
{
	Sprite::move({ vec.x * speed * dt, vec.y * speed * dt });
	//centerHitBox();
}

void Entity::update(const float& dt, sf::RenderWindow* window, sf::View& view)
{
}
