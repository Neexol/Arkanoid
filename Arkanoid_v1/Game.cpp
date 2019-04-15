#include "Game.h"

Game::Game(sf::RenderWindow& window)
{
	backgroundTexture.loadFromFile("images/background.png");
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale((float)valueNS::windowWidth / valueNS::backgroundWidth, (float)valueNS::windowWidth / valueNS::backgroundWidth);
	backgroundSprite.setColor(sf::Color::Green);
	
	arrowsTexture.loadFromFile("images/arrow.png");
	arrowsSprite.setTexture(arrowsTexture);
	arrowsSprite.setColor(sf::Color::Green);
	arrowsSprite.setPosition(0, 0);
	arrowsSprite.setOrigin(valueNS::arrowWidth + 80, valueNS::arrowHeight / 2.f);
	arrowsSprite.setPosition(valueNS::windowWidth / 2.f, valueNS::windowHeight - valueNS::arrowHeight / 2.f - valueNS::paddleHeight);

	window.clear();
	window.draw(backgroundSprite);
	window.draw(arrowsSprite);
	arrowsSprite.setRotation(180);
	window.draw(arrowsSprite);

	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < valueNS::windowWidth / valueNS::wallWidth + 1; j++)
		{
			wall.setPosition({ j * (float)valueNS::wallHeight, i * (float)valueNS::wallWidth });
			wall.show(window);
		}
	}

	bricks.show(window);
	ball.show(window);
	paddle.show(window);
	window.display();
}


void Game::update(sf::RenderWindow& window)
{
	auto dt = clock.restart().asSeconds();

	if (playable)
	{
		auto ballPosition = ball.getPosition();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && paddle.getPosition().x > 0) { paddle.move({ -paddle.speed.x * dt, 0 }); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && paddle.getPosition().x < window.getSize().x - paddle.getWidth()) { paddle.move({ paddle.speed.x * dt, 0 }); }

		ball.move({ ball.speed.x * dt, 0});
		if (
			bricks.checkCollision(ball)
			|| (ballPosition.x > window.getSize().x - ball.getHeight() && ball.speed.x > 0
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
			|| ballPosition.y < valueNS::wallHeight * 2 && ball.speed.y < 0
			|| paddle.isCollideSpeed(ball) && ball.speed.y > 0
			)
		{
			ball.move({ 0, -ball.speed.y * dt });
			ball.speed.y *= -1;
		}

		window.clear();
		window.draw(backgroundSprite);

		if (ballPosition.y > window.getSize().y - ball.getHeight() && ball.speed.y > 0)
		{
			paddle.setPosition({ (window.getSize().x - valueNS::paddleWidth) / 2.f, (float)window.getSize().y - valueNS::paddleHeight});
			ball.setPosition({ (window.getSize().x - valueNS::ballSize ) / 2.f, (float)paddle.getPosition().y - ball.getHeight() });
			ball.speed = sf::Vector2f{ 0.f, 0.f };
			ball.toggleFire();

			window.draw(arrowsSprite);
			arrowsSprite.rotate(180);
			window.draw(arrowsSprite);

			playable = false;
		}

		for (size_t i = 0; i < 2; i++)
		{
			for (size_t j = 0; j < valueNS::windowWidth / valueNS::wallWidth + 1; j++)
			{
				wall.setPosition({ j * (float)valueNS::wallHeight, i * (float)valueNS::wallWidth });
				wall.show(window);
			}
		}

		bricks.show(window);
		ball.show(window);
		paddle.show(window);
		window.display();
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { ball.speed = valueNS::ballSpeed; ball.speed.x *= -1; playable = true; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { ball.speed = valueNS::ballSpeed; playable = true; }
	}
}


Game::~Game()
{
}
