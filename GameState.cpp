#include "GameState.h"

GameState::GameState()
{
}

GameState::GameState(const sf::Vector2f& windowSize, std::stack<State*>* states, bool readFromFile)
	: State(states, windowSize)
{
	srand(time(0));

	scoreBoard.setFont(Fonts::getFont(Fonts::OPEN_SANS_REGULAR));
	scoreBoard.setFillColor(sf::Color::White);
	scoreBoard.setString(std::to_string(score));

	deathText.setFont(Fonts::getFont(Fonts::OPEN_SANS_BOLD));
	deathText.setFillColor(sf::Color::Red);
	deathText.setCharacterSize(64);
	deathText.setString("You Died");

	player = new Player(Textures::getTexture(Textures::PLAYER));

	marker.setSize({ 50,50 });
	marker.setFillColor(sf::Color::Red);
	marker.setPosition({ 100, 100 });

	scoreBoard.setPosition({ player->getPosition().x - windowSize.x / 2 + 10, player->getPosition().y - windowSize.y / 2 + 10 });

	if (readFromFile)
	{
		loadFromFile();
	}
	else
	{
		setNewGame();
	}

	summonPlanets();
}

void GameState::setNewGame()
{
	std::ofstream out("game_save.txt");
	lives = 3;
	score = 0;
	player->setPosition({ 0.f, 0.f });

	out << "0\n";
	out << "0\n";
	out << "0\n";
	out << "0\n";
	out.close();

	//playerCamera.reset((sf::FloatRect(0, 0, window->getSize().x, window->getSize().y)));
	playerCamera.reset((sf::FloatRect(0, 0, windowSize.x, windowSize.y)));

	setLives();
}

void GameState::loadFromFile()
{
	std::ifstream in("game_save.txt");
	std::string data;

	getline(in, data);
	float x = std::stof(data);
	getline(in, data);
	float y = std::stof(data);
	getline(in, data);
	score = std::stoi(data);
	getline(in, data);
	lives = std::stoi(data);
	
	in.close();

	sf::Vector2f playerPos = { x, y };
	player->setPosition(playerPos);
	//playerCamera.reset(sf::FloatRect(x, y, static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)));
	playerCamera.reset(sf::FloatRect(x, y, windowSize.x, windowSize.y));
	playerCamera.setCenter(playerPos);

	setLives();
}

void GameState::setLives()
{
	livesVec.clear();
	for (int i = 0; i < lives; i++)
	{
		livesVec.push_back(sf::CircleShape(20));
		livesVec[i].setFillColor(sf::Color::White);
		livesVec[i].setOutlineThickness(4.f);
		livesVec[i].setOutlineColor(sf::Color::Red);
	}
}

void GameState::moveLives()
{
	sf::Vector2f startPos = { scoreBoard.getPosition().x, scoreBoard.getPosition().y + 50};
	if (!livesVec.empty())
	{
		for (auto& i : livesVec)
		{
			i.setPosition(startPos);
			startPos.x += i.getRadius() * 2.5;
		}
	}
}

int GameState::rngRangeNeg(int min, int max)
{
	int x = rand() % (max - min + 1) + min;
	int sign = rand() % 2 + 1;
	if (sign == 1)
	{
		return x;
	}
	return x * -1;

}

void GameState::setPlanet()
{
	float randXPos = rngRangeNeg(300, 2000);
	float randYPos = rngRangeNeg(300, 2000);
	entities.push_back(new Planet(Textures::getTexture(Textures::PLANETS), {randXPos, randYPos}, rand() % 3, rand() % 4));
}

void GameState::summonPlanets()
{
	for (int i = 0; i < 20; i++)
	{
		setPlanet();
	}
}

void GameState::setAsteroid()
{
	float randXPos = player->getPosition().x + rngRangeNeg(200, 300);
	float randYPos = player->getPosition().y + rngRangeNeg(200, 300);

	entities.push_back(new Asteroid(Textures::getTexture(Textures::ASTEROID_LARGE), 50, rand() % 360, {randXPos, randYPos }));
}

void GameState::summonAsteroids()
{
	for (int i = 0; i < 10; i++)
	{
		setAsteroid();
	}
}

void GameState::killAsteroid(Entity* asteroid, Entity* bullet)
{
	score += asteroid->getValue();

	particles.push_back(new Explosion(Textures::getTexture(Textures::EXPLOSION), bullet->getPosition()));

	switch (asteroid->getType())
	{
	case(ASTEROID_LARGE):
		entities.push_back(new Asteroid(Textures::getTexture(Textures::ASTEROID_MEDIUM), 100, bullet->getRotation() + rngRangeNeg(40, 70), asteroid->getPosition(), ASTEROID_MEDIUM, 125));
		entities.push_back(new Asteroid(Textures::getTexture(Textures::ASTEROID_MEDIUM), 100, bullet->getRotation() + rngRangeNeg(40, 70), asteroid->getPosition(), ASTEROID_MEDIUM, 125));
		break;
	case(ASTEROID_MEDIUM):
		entities.push_back(new Asteroid(Textures::getTexture(Textures::ASTEROID_SMALL), 150, bullet->getRotation() + rngRangeNeg(40, 70), asteroid->getPosition(), ASTEROID_SMALL, 160));
		entities.push_back(new Asteroid(Textures::getTexture(Textures::ASTEROID_SMALL), 150, bullet->getRotation() + rngRangeNeg(40, 70), asteroid->getPosition(), ASTEROID_SMALL, 160));
		break;
	default:
		break;
	}
	asteroid->kill();
}

void GameState::hitPlanet(Entity* planet, Entity* bullet)
{
	planet->hit();
	if (planet->getCanKill())
	{
		//big explosion
		particles.push_back(new BigExplosion(Textures::getTexture(Textures::BIG_EXPLOSION), { planet->getPosition().x - 175, planet->getPosition().y - 175 }));
		score += planet->getValue();
	}

	particles.push_back(new Explosion(Textures::getTexture(Textures::EXPLOSION), bullet->getPosition()));
}

float GameState::getDistance(Entity* entity1, Entity* entity2)
{
	return std::sqrtf(pow(entity2->getPosition().x - entity1->getPosition().x, 2) + pow(entity2->getPosition().y - entity1->getPosition().y, 2));
}

void GameState::hitPlayer()
{
	player->hit();
	lives--;
	if (!livesVec.empty())
	{
		livesVec.pop_back();
	}

	if (lives <= 0)
	{
		die();
	}
}

void GameState::die()
{
	player->setCanMove(false);
	deathText.setPosition({player->getPosition().x - deathText.getGlobalBounds().width / 2, player->getPosition().y - 150.f});
}


void GameState::update(float dt)
{
	scoreBoard.setString(std::to_string(score));
	scoreBoard.setPosition({ player->getPosition().x - windowSize.x / 2 + 10, player->getPosition().y - windowSize.y / 2 + 10 });
	playerCamera.setCenter(player->getPosition());

	////////////////////////////////////
	//window->setView(playerCamera); moved to draw function
	this->dt = dt;
	player->update(dt);

	moveLives();
	if (lives <= 0)
	{
		die();
	}

	particlesLoop(dt);
	entityLifeCycleLoop(dt);
	asteroidsLoop(dt);
	collisionLoop();

}

void GameState::entityLifeCycleLoop(float dt)
{
	for (int i = entities.size() - 1; i >= 0; i--)
	{
		/////////////////////////////////////////
		entities[i]->update(dt);

		if (getDistance(player, entities[i]) >= 600 && entities[i]->getType() != EntityType::PLANET) //remove asteroids and bullets that are too far away from player
			entities[i]->kill();

		if (entities[i]->getCanKill()) //destroy entities marked to be killed
			entities.erase(entities.begin() + i);
	}
}

void GameState::asteroidsLoop(float dt)
{
	asteroidSpawnTimeProgress += dt;
	if (asteroidSpawnTimeProgress >= asteroidSpawnTime)
	{
		summonAsteroids();
		asteroidSpawnTimeProgress = 0;
	}
}

void GameState::collisionLoop()
{
	for (int i = entities.size() - 1; i >= 0; i--)
	{
		for (int j = entities.size() - 1; j >= 0; j--)
		{
			if (i != j && entities[i]->getType() == BULLET && (entities[j]->getType() == ASTEROID_LARGE || entities[j]->getType() == ASTEROID_MEDIUM || entities[j]->getType() == ASTEROID_SMALL))
			{
				if (getDistance(entities[i], entities[j]) <= 25.0f)
				{
					killAsteroid(entities[j], entities[i]);
					entities[i]->kill();
				}
			}
			else if (i != j && entities[i]->getType() == BULLET && entities[j]->getType() == PLANET)
			{
				if (getDistance(entities[i], entities[j]) <= entities[j]->getGlobalBounds().width / 3)
				{
					hitPlanet(entities[j], entities[i]);
					entities[i]->kill();
				}
			}
			else
				continue;
		}
		if (!player->getInvul() && (entities[i]->getType() == ASTEROID_LARGE || entities[i]->getType() == ASTEROID_MEDIUM || entities[i]->getType() == ASTEROID_SMALL))
		{
			if (getDistance(player, entities[i]) <= 35.f)
			{
				hitPlayer();
			}
		}
	}
}

void GameState::particlesLoop(float dt)
{
	if (!particles.empty())
	{
		for (int i = particles.size() - 1; i >= 0; i--)
		{
			particles[i]->update(dt);
			if (particles[i]->getCanKill())
				particles.erase(particles.begin() + i);
		}
	}
}

void GameState::render(sf::RenderWindow& window, sf::RenderStates states)
{
	window.setView(playerCamera);
	window.draw(*player);
	window.draw(scoreBoard);

	for (auto& i : entities)
	{
		window.draw(*i);
	}

	for (auto& i : particles)
	{
		window.draw(*i);
	}

	if (livesVec.size() > 0)
	{
		for (auto& i : livesVec)
		{
			window.draw(i);
		}
	}
	if (lives <= 0)
	{
		window.draw(deathText);
	}
}

void GameState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.setView(playerCamera);
	target.draw(*player);
	target.draw(scoreBoard);

	for (auto& i : entities)
	{
		target.draw(*i);
	}

	for (auto& i : particles)
	{
		target.draw(*i);
	}

	if (livesVec.size() > 0)
	{
		for (auto& i : livesVec)
		{
			target.draw(i);
		}
	}
	if (lives <= 0)
	{
		target.draw(deathText);
	}
}

void GameState::eventHandler(sf::RenderWindow& window, sf::Event& event, float dt)
{
	//setting rotation of player
	if(lives > 0)
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		sf::Vector2f inViewPos = window.mapPixelToCoords({ mousePos.x, mousePos.y }, playerCamera);
		rotation = (atan2(inViewPos.y - player->getPosition().y, inViewPos.x - player->getPosition().x) * (180.f / 3.141593f)) + 90.f;
		player->setRotation(rotation);
	}

	if (player->checkShot())
	{
		entities.push_back(new Bullet(Textures::getTexture(Textures::BULLET), player->getRotation(), player->getPosition(), true));
		player->setShot(false);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		saveGame();
		clearEntities();
		states->pop();
		window.setView(window.getDefaultView());
		states->push(new MainMenuState(windowSize, states));
		states->push(new TitleScreenState(windowSize, states));
	}
}

void GameState::saveGame()
{
	std::ofstream out("game_save.txt", std::ios::trunc); //clears save and rewrites te whole thing
	out << player->getPosition().x << '\n';
	out << player->getPosition().y << '\n';
	out << score << '\n';
	out << lives << '\n';
	out.close();
}

void GameState::clearEntities()
{
	for (int i = entities.size() - 1; i >= 0; i--)
	{
		delete entities[i];
	}
	for (int i = particles.size() - 1; i >= 0; i--)
	{
		delete particles[i];
	}

	delete player;
}

void GameState::close()
{
	saveGame();
	clearEntities();

	canClose = true;
}