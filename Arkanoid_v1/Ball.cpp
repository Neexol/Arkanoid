#include "Ball.h"

SpeedEntity::SpeedEntity(){}

SpeedEntity::SpeedEntity(float X, float Y, int Width, int Height, std::string textureStr, sf::Vector2f Speed)
	: Entity(X, Y, Width, Height, textureStr), speed{Speed}
{}

SpeedEntity::~SpeedEntity()
{
}
