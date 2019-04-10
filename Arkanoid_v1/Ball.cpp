#include "Ball.h"

Ball::Ball(){}

Ball::Ball(float X, float Y, int Width, int Height, std::string textureStr, sf::Vector2f Speed)
	: Entity(X, Y, Width, Height, textureStr), speed{Speed}
{}

void Ball::toggleFire()
{
	if (abs(speed.x) > 500)
	{
		sprite.setColor(sf::Color(255, 0, 0));
		fireBall = true;
	}
	else
	{
		sprite.setColor(sf::Color(255, 255, 255));
		fireBall = false;
	}
}

Ball::~Ball()
{
}
