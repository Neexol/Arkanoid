#pragma once
#include "Entity.h"

class SpeedEntity : public Entity
{
public:
	sf::Vector2f speed;
	
	SpeedEntity();
	SpeedEntity(float X, float Y, int Width, int Height, std::string textureStr, sf::Vector2f Speed);

	~SpeedEntity();
};