#pragma once

#include <SFML/Graphics.hpp>
#include "BrickTable.h"
#include "Ball.h"
#include "Paddle.h"

class Game
{
private:

	BrickTable bricks;
	Ball ball = Ball((valueNS::windowWidth - valueNS::ballSize) / 2, valueNS::windowHeight - valueNS::paddleHeight - valueNS::ballSize,
		valueNS::ballSize, valueNS::ballSize, "images/ball.png", { 0.f, 0.f });
	Paddle paddle = Paddle((valueNS::windowWidth - valueNS::paddleWidth) / 2, valueNS::windowHeight - valueNS::paddleHeight,
		valueNS::paddleWidth, valueNS::paddleHeight, "images/paddle.png", valueNS::paddleSpeed);
	Entity wall = Entity(0.f, 0.f, valueNS::wallWidth, valueNS::wallHeight, "images/wall.png");

	sf::Clock clock;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	
	sf::Texture arrowsTexture;
	sf::Sprite arrowsSprite;

	bool playable = false;

public:
	Game(sf::RenderWindow& window);

	void update(sf::RenderWindow& window);

	~Game();
};

