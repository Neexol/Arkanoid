#include "Brick.h"

Brick::Brick()
	:Entity(0.f, 0.f, valueNS::brickWidth, valueNS::brickHeight, "images/brick.png"), status{ StatusBrick::NORMAL } {}

Brick::Brick(float X, float Y, int Width, int Height, std::string textureStr, int value)
	:Entity(X, Y, Width, Height, textureStr), status{(StatusBrick)value}
{
}

void Brick::activate()
{
	if (status == NORMAL)
	{
		status = CRASHED;
		this->setTexture(brickCrashedPath);
	}
	else
	{
		this->setPosition({ -100.f, -100.f });
	}
}

Brick::~Brick()
{
}
