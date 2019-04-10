#include "Ball.h"

Ball::Ball(){}

Ball::Ball(float X, float Y, int Width, int Height, std::string textureStr, sf::Vector2f Speed)
	: Entity(X, Y, Width, Height, textureStr), speed{Speed}
{}

void Ball::move(sf::Vector2f vector)
{
	if (!(int)vector.x)
		previousPosition = this->getPosition();
	x += vector.x;
	y += vector.y;
	sprite.setPosition(x, y);
}

void Ball::toggleFire()
{
	if (speed.x > 500)
		sprite.setColor(sf::Color(255, 0, 0)); else
		sprite.setColor(sf::Color(255, 255, 255));
}

Ball::~Ball()
{
}
