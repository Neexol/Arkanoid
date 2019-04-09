#pragma once

#include <SFML/Graphics.hpp>
#include "BrickTable.h"
#include "Ball.h"

class Game
{
private:

	BrickTable bricks;
	SpeedEntity ball = SpeedEntity((valueNS::windowWidth - valueNS::ballSize) / 2, valueNS::windowHeight - valueNS::paddleHeight - valueNS::ballSize,
		valueNS::ballSize, valueNS::ballSize, "images/ball.png", valueNS::ballSpeed);
	SpeedEntity paddle = SpeedEntity((valueNS::windowWidth - valueNS::paddleWidth) / 2, valueNS::windowHeight - valueNS::paddleHeight,
		valueNS::paddleWidth, valueNS::paddleHeight, "images/paddle.png", valueNS::paddleSpeed);
	Entity wall = Entity(0.f, 0.f, valueNS::wallWidth, valueNS::wallHeight, "images/wall.png");
	sf::Clock clock;
	sf::Texture background;
	sf::Sprite backgroundSprite;

	bool playable = true;

public:
	Game(sf::RenderWindow& window);

	void update(sf::RenderWindow& window);

	~Game();
};
