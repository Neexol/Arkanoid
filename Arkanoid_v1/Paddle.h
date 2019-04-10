#pragma once
#include "Ball.h"

class Paddle : public Ball
{
public:
	Paddle();
	Paddle(float X, float Y, int Width, int Height, std::string textureStr, sf::Vector2f Speed);

	bool isCollideSpeed(Ball& e);

	~Paddle();
};

