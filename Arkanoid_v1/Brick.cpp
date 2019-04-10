#include "Brick.h"

Brick::Brick()
	:Entity(0.f, 0.f, valueNS::brickWidth, valueNS::brickHeight, "images/brick.png"), status{ StatusBrick::NORMAL } {}

Brick::Brick(float X, float Y, int Width, int Height, std::string textureStr, int value)
	:Entity(X, Y, Width, Height, textureStr), status{(StatusBrick)value}
{
}

void Brick::activate(const Entity& ball)
{
	if (ball.isFireBall() || status == CRASHED)
	{
		this->setPosition({ -100.f, -100.f });
	}
	else
	{
		status = CRASHED;
		this->setTexture(brickCrashedPath);
	}
}

Brick::~Brick()
{
}
