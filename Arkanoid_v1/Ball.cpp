#include "Ball.h"

Ball::Ball(float X, float Y, int Width, int Height, std::string textureStr, sf::Vector2f Speed)
	: Entity(X, Y, Width, Height, textureStr), speed{Speed}
{
}

Ball::~Ball()
{
}
