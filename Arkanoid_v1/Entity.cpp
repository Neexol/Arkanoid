#include "Entity.h"

Entity::Entity(float X, float Y, int Width, int Height, const std::string& textureStr)
	: x{ X }, y{ Y }, height{ Height }, width{ Width }
{
	texture.loadFromFile(textureStr);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}

void Entity::setPosition(sf::Vector2f pos)
{
	x = pos.x; 
	y = pos.y;
	sprite.setPosition(x, y);
}

void Entity::show(sf::RenderWindow& window)
{
	window.draw(sprite);
}

bool Entity::isCollide(Entity& e)
{
	return this->getRect().intersects(e.getRect());
}

void Entity::move(sf::Vector2f vector)
{
	x += vector.x;
	y += vector.y;
	sprite.setPosition(x, y);
}

Entity::~Entity()
{
}
