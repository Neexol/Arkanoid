#include <SFML/Graphics.hpp>
#include "BrickTable.h"
#include "Ball.h"
#include <iostream>

int main()
{
	constexpr int WINDOW_WIDTH = 800;
	constexpr int WINDOW_HEIGHT = 600;
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Arkanoid");

	BrickTable bricks;
	Ball ball(390, 490, 10, 10, "images/ball.png", { 300, -300 });
	Ball paddle(WINDOW_WIDTH / 2 - 40, WINDOW_HEIGHT - 20, 80, 20, "images/paddle.png", {600, 0});

	sf::Clock clock;
	bool playable = true;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		auto dt = clock.restart().asSeconds();

		if (playable)
		{
			auto ballPosition = ball.getPosition();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && paddle.getPosition().x > 0) { paddle.move({ -paddle.speed.x * dt, 0 }); }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && paddle.getPosition().x < WINDOW_WIDTH - paddle.getWidth()) { paddle.move({ paddle.speed.x * dt, 0 }); }

			ball.move({ ball.speed.x * dt, 0 });
			if (
				bricks.checkCollision(ball)
				|| (ballPosition.x > WINDOW_WIDTH - ball.getHeight() && ball.speed.x > 0
					|| ballPosition.x < 0 && ball.speed.x < 0)
				|| paddle.isCollide(ball) && ((paddle.getPosition().x - ball.getPosition().x) * ball.speed.x) > 0
				)
			{
				ball.move({ -ball.speed.x * dt, 0 });
				ball.speed.x *= -1;
			}

			ball.move({ 0, ball.speed.y * dt });
			if (
				bricks.checkCollision(ball)
				|| ballPosition.y < 0 && ball.speed.y < 0
				|| paddle.isCollide(ball) && ball.speed.y > 0
				)
			{
				ball.move({ 0, -ball.speed.y * dt });
				ball.speed.y *= -1;
			}

			if (ballPosition.y > WINDOW_HEIGHT - ball.getHeight() && ball.speed.y > 0)
			{
				paddle.setPosition({ WINDOW_WIDTH / 2 - 40, WINDOW_HEIGHT - 20 });
				ball.setPosition({ 395, paddle.getPosition().y - ball.getHeight() });
				ball.speed = { 300, -300 };
				window.clear();
				bricks.show(window);
				ball.show(window);
				paddle.show(window);
				window.display();

				playable = false;
			}

			window.clear();
			bricks.show(window);
			ball.show(window);
			paddle.show(window);
			window.display();
		}
		else
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { ball.speed = { -300, -300 }; playable = true; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { ball.speed = { 300, -300 }; playable = true; }
		}
	}

	return 0;
}