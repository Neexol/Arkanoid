#pragma once
#include "Entity.h"

class Brick : public Entity
{
private:

	enum StatusBrick
	{
		CRASHED,
		NORMAL
	};

	StatusBrick status;

	std::string brickCrashedPath = "images/brick_crashed.png";

public:

	Brick();
	Brick(float X, float Y, int Width, int Height, std::string textureStr, int value = 0);

	void activate();

	~Brick();
};