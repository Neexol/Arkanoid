#include "Paddle.h"

Paddle::Paddle()
{}

Paddle::Paddle(float X, float Y, int Width, int Height, std::string textureStr, sf::Vector2f Speed)
	: Ball(X, Y, Width, Height, textureStr, Speed)
{}


bool Paddle::isCollideSpeed(Ball& e)
{
	if (this->getRect().intersects(e.getRect()))
	{
		if (((getPosition().x - previousPosition.x) * e.speed.x) >= 0)
			e.speed.x += e.speed.x > 0 ? valueNS::ballVelocity : -valueNS::ballVelocity; else
			e.speed.x += e.speed.x < 0 ? valueNS::ballVelocity : -valueNS::ballVelocity;
		e.toggleFire();

		return true;
	}

	return false;
}

void Paddle::move(sf::Vector2f vector)
{
	previousPosition = this->getPosition();
	Ball::move(vector);
}

Paddle::~Paddle()
{}
