#pragma once
#include "Ball.h"

class Paddle : public Ball
{
	sf::Vector2f previousPosition;
public:
	Paddle();
	Paddle(float X, float Y, int Width, int Height, std::string textureStr, sf::Vector2f Speed);

	bool isCollideSpeed(Ball& e);
	void move(sf::Vector2f vector);

	~Paddle();
};

