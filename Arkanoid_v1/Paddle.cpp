#include "Paddle.h"
#include <iostream>

Paddle::Paddle()
{}

Paddle::Paddle(float X, float Y, int Width, int Height, std::string textureStr, sf::Vector2f Speed)
	: Ball(X, Y, Width, Height, textureStr, Speed)
{}


bool Paddle::isCollideSpeed(Ball& e)
{
	if (this->getRect().intersects(e.getRect()))
	{
		if ((getPosition().x - previousPosition.x) * (e.getPosition().x - e.previousPosition.x >= 0))
			e.speed.x += e.speed.x > 0 ? 20 : -20; else
			e.speed.x += e.speed.x < 0 ? 20 : -20;
		e.toggleFire();

		return true;
	}

	return false;
}

Paddle::~Paddle()
{}
