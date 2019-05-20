#include "Game.h"

Game::Game(sf::RenderWindow& window)
{
	arrowsTexture.loadFromFile("images/arrow.png");
	arrowsSprite.setTexture(arrowsTexture);
	arrowsSprite.setColor(sf::Color::Green);
	arrowsSprite.setPosition(0, 0);
	arrowsSprite.setOrigin(valueNS::arrowWidth + 80, valueNS::arrowHeight / 2.f);
	arrowsSprite.setPosition(valueNS::windowWidth / 2.f, valueNS::windowHeight - valueNS::arrowHeight / 2.f - valueNS::paddleHeight);

	heartTexture.loadFromFile("images/heart.png");
	heartSprite.setTexture(heartTexture);

	font.loadFromFile("Comfortaa.ttf");
	levelText.setFont(font);
	levelText.setString("Level 1");
	levelText.setPosition(17, 10);
	levelText.setFillColor(sf::Color(31, 42, 0));
	levelText.setCharacterSize(30);
	levelText.setStyle(sf::Text::Bold);
	
	window.clear();

	background.show(window);
	window.draw(arrowsSprite);
	arrowsSprite.setRotation(180);
	window.draw(arrowsSprite);
	wall.show(window);

	for (int i = 1; i <= health; i++)
	{
		heartSprite.setPosition(valueNS::windowWidth - (40 * i + 10), 19);
		window.draw(heartSprite);
	}

	window.draw(levelText);
	bricks.show(window);
	ball.show(window);
	paddle.show(window);
	window.display();
}

void Game::menu(sf::RenderWindow& window)
{
	Entity menu = Entity(0.f, 0.f, valueNS::windowHeight, valueNS::windowWidth, "images/menu.png");
	Entity start = Entity(0.f, 0.f, valueNS::windowHeight, valueNS::windowWidth, "images/start.png");
	Entity exit = Entity(0.f, 0.f, valueNS::windowHeight, valueNS::windowWidth, "images/exit.png");
	sf::Event event;
	window.clear();
	menu.show(window);
	window.display();
	
	bool isMenu = true;

	while (isMenu)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (sf::IntRect(265, 420, 270, 95).contains(sf::Mouse::getPosition(window)))
			{
				start.show(window);
				window.display();
				if (event.type == sf::Event::MouseButtonPressed)
					isMenu = false;
			} 
			else if (sf::IntRect(286, 564, 226, 84).contains(sf::Mouse::getPosition(window)))
			{
				exit.show(window);
				window.display();
				if (event.type == sf::Event::MouseButtonPressed)
					window.close();
			}
			else
			{
				menu.show(window);
				window.display();
			}
		}
	}
}

void Game::update(sf::RenderWindow& window)
{
	auto dt = clock.restart().asSeconds();

	if (playable && health > 0)
	{
		auto ballPosition = ball.getPosition();

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && paddle.getPosition().x > 0) { paddle.move({ -paddle.speed.x * dt, 0 }); }
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && paddle.getPosition().x < window.getSize().x - paddle.getWidth()) { paddle.move({ paddle.speed.x * dt, 0 }); }

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
			|| ballPosition.y < valueNS::wallHeight && ball.speed.y < 0
			|| paddle.isCollideSpeed(ball) && ball.speed.y > 0
			)
		{
			ball.move({ 0, -ball.speed.y * dt });
			ball.speed.y *= -1;
		}

		window.clear();
		background.show(window);

		if (ballPosition.y > window.getSize().y - ball.getHeight() && ball.speed.y > 0)
		{
			health--;

			paddle.setPosition({ (window.getSize().x - valueNS::paddleWidth) / 2.f, (float)window.getSize().y - valueNS::paddleHeight });
			ball.setPosition({ (window.getSize().x - valueNS::ballSize) / 2.f, (float)paddle.getPosition().y - ball.getHeight() });
			ball.speed = sf::Vector2f{ 0.f, 0.f };
			ball.toggleFire();

			window.draw(arrowsSprite);
			arrowsSprite.rotate(180);
			window.draw(arrowsSprite);

			playable = false;
		}

		if (bricks.getNumberOfDeletedBricks() == valueNS::brickTableHeight * valueNS::brickTableWidth)
		{
			level++;
			levelText.setString("Level " + std::to_string(level));
			levelText.setPosition(10, 10);
			bricks.newTable();

			paddle.setPosition({ (window.getSize().x - valueNS::paddleWidth) / 2.f, (float)window.getSize().y - valueNS::paddleHeight });
			ball.setPosition({ (window.getSize().x - valueNS::ballSize) / 2.f, (float)paddle.getPosition().y - ball.getHeight() });
			ball.speed = sf::Vector2f{ 0.f, 0.f };
			ball.toggleFire();

			window.draw(arrowsSprite);
			arrowsSprite.rotate(180);
			window.draw(arrowsSprite);

			playable = false;
		}

		wall.show(window);

		for (int i = 1; i <= health; i++)
		{
			heartSprite.setPosition(valueNS::windowWidth - (40 * i + 10), 20);
			window.draw(heartSprite);
		}

		window.draw(levelText);

		bricks.show(window);
		ball.show(window);
		paddle.show(window);

		if (!health)
		{
			sf::Texture gameOverTexture;
			gameOverTexture.loadFromFile("images/GameOver.png");
			sf::Sprite gameOverSprite;
			gameOverSprite.setTexture(gameOverTexture);
			window.clear();
			window.draw(gameOverSprite);
		}

		if (level == valueNS::maxLevel + 1)
		{
			sf::Texture youWinTexture;
			youWinTexture.loadFromFile("images/YouWin.png");
			sf::Sprite youWinSprite;
			youWinSprite.setTexture(youWinTexture);
			window.clear();
			window.draw(youWinSprite);
		}

		window.display();
	}
	else if (!playable && health > 0)
	{
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && health)
		{
			ball.speed = valueNS::ballSpeed;
			ball.speed.x *= -1;
			playable = true;
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && health)
		{
			ball.speed = valueNS::ballSpeed;
			playable = true;
		}
	}
}

Game::~Game()
{
}