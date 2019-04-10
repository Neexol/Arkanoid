#pragma once
#include "Entity.h"

class Ball : public Entity
{
public:
	sf::Vector2f previousPosition;
public:
	sf::Vector2f speed;
	
	Ball();
	Ball(float X, float Y, int Width, int Height, std::string textureStr, sf::Vector2f Speed);
	void move(sf::Vector2f vector);
	void toggleFire();

	~Ball();
};