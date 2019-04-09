#pragma once
#include <SFML/Graphics.hpp>

namespace valueNS
{
	constexpr int windowWidth = 1000;
	constexpr int windowHeight = 750;

	constexpr int paddleWidth = 100;
	constexpr int paddleHeight = 21;
	const sf::Vector2f paddleSpeed { 600, 0 };

	constexpr int brickWidth = 80;
	constexpr int brickHeight = 37;

	constexpr int ballSize = 12;
	const sf::Vector2f ballSpeed{ 300, -300 };

	constexpr int backgroundWidth = 208;
	constexpr int backgroundHeight = 232;

	constexpr int wallWidth = 32;
	constexpr int wallHeight = 32;

	constexpr int brickTableWidth = 1;
	constexpr int brickTableHeight = 2;
}