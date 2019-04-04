#include "Brick.h"

Brick::Brick()
	:Entity(0, 0, 80, 40, "images/brick.png"), type{ DEFAULT } {}

Brick::Brick(float X, float Y, int Width, int Height, std::string textureStr, TypeBricks Type, int value)
	:Entity(X, Y, Width, Height, textureStr), type{Type}
{
}

void Brick::setTexture(std::string& texture)
{
	sf::Texture t;
	t.loadFromFile(texture);
	sprite.setTexture(t);
}

void Brick::activate()
{
	switch (type)
	{
	case DEFAULT:
		this->setPosition({ -100, -100 });
		break;
	default:
		break;
	}
}

Brick::~Brick()
{
}
