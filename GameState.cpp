#include "GameState.h"

GameState::GameState()
{
}

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
	: GameState(window, states, nullptr)
{

}

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states, sf::Font* font, bool readFromFile)
	: State(window, states, font)
{
	srand(time(0));

	for (int i = 0; i < 5; i++)
	{
		textures.push_back(new sf::Texture);
	}
	assert(textures[0]->loadFromFile("images/entities/player.png"));
	assert(textures[1]->loadFromFile("images/entities/bullet.png"));
	assert(textures[2]->loadFromFile("images/entities/asteroid_large.png"));
	assert(textures[3]->loadFromFile("images/entities/asteroid_medium.png"));
	assert(textures[4]->loadFromFile("images/entities/asteroid_small.png"));

	//scoreBox.create("0", window, *font, { 100, 50 }, 40, sf::Color::White, sf::Color::Transparent);
	scoreBoard.setFont(*font);
	scoreBoard.setFillColor(sf::Color::White);
	scoreBoard.setString(std::to_string(score));

	player = new Player(textures[0]);

	marker.setSize({ 50,50 });
	marker.setFillColor(sf::Color::Red);
	marker.setPosition({ 100, 100 });

	scoreBoard.setPosition({ player->getPosition().x - static_cast<float>(window->getSize().x / 2) + 10, player->getPosition().y - static_cast<float>(window->getSize().y / 2) + 10 });


	if (readFromFile)
	{
		loadFromFile();
	}
	else
	{
		setNewGame();
	}
}

void GameState::setNewGame()
{
	std::ofstream out("game_save.txt");
	lives = 3;
	score = 0;

	out << "0\n";
	out << "0\n";
	out << "0\n";
	out << "0\n";
	out.close();

	playerCamera.reset((sf::FloatRect(0, 0, window->getSize().x, window->getSize().y)));

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
	playerCamera.reset(sf::FloatRect(x, y, static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)));
	playerCamera.setCenter(playerPos);

	setLives();
}

void GameState::setLives()
{
	livesVec.clear();
	for (int i = 0; i < lives; i++)
	{
		livesVec.push_back(sf::CircleShape(30));
		livesVec[i].setFillColor(sf::Color::White);
		livesVec[i].setOutlineColor(sf::Color::Red);
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

void GameState::setAsteroid()
{
	float randXPos = player->getPosition().x + rngRangeNeg(200, 300);
	float randYPos = player->getPosition().y + rngRangeNeg(200, 300);

	entities.push_back(new Asteroid(textures[2], 50, rand() % 360, {randXPos, randYPos }));
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
	switch (asteroid->getType())
	{
	case(ASTEROID_LARGE):
		entities.push_back(new Asteroid(textures[3], 100, bullet->getRotation() + rngRangeNeg(40, 75), asteroid->getPosition(), ASTEROID_MEDIUM, 100));
		entities.push_back(new Asteroid(textures[3], 100, bullet->getRotation() + rngRangeNeg(40, 75), asteroid->getPosition(), ASTEROID_MEDIUM, 100));
		break;
	case(ASTEROID_MEDIUM):
		entities.push_back(new Asteroid(textures[4], 150, bullet->getRotation() + rngRangeNeg(40, 75), asteroid->getPosition(), ASTEROID_SMALL, 120));
		entities.push_back(new Asteroid(textures[4], 150, bullet->getRotation() + rngRangeNeg(40, 75), asteroid->getPosition(), ASTEROID_SMALL, 120));
		break;
	default:
		break;
	}
	asteroid->kill();
}

float GameState::getDistance(Entity* entity1, Entity* entity2)
{
	return std::sqrtf(pow(entity2->getPosition().x - entity1->getPosition().x, 2) + pow(entity2->getPosition().y - entity1->getPosition().y, 2));
}

void GameState::die()
{
	player->setCanMove(false);
}

void GameState::update(float dt)
{
	scoreBoard.setString(std::to_string(score));
	scoreBoard.setPosition({ player->getPosition().x - static_cast<float>(window->getSize().x / 2) + 10, player->getPosition().y - static_cast<float>(window->getSize().y / 2) + 10 });
	playerCamera.setCenter(player->getPosition());
	window->setView(playerCamera);
	player->update(dt, window, playerCamera);

	if (player->checkShot())
	{
		entities.push_back(new Bullet(textures[1], player->getRotation(), player->getPosition(), true));
		player->setShot(false);
	}
	if (lives <= 0)
	{
		die();
	}

	entityLifeCycleLoop(dt);
	asteroidsLoop(dt);
	collisionLoop();

}

void GameState::entityLifeCycleLoop(float dt)
{
	for (int i = entities.size() - 1; i >= 0; i--)
	{
		entities[i]->update(dt, window, playerCamera);

		if (getDistance(player, entities[i]) >= 600) //remove asteroids and bullets that are too far away from player
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
				if (getDistance(entities[i], entities[j]) <= 20.0f)
				{
					killAsteroid(entities[j], entities[i]);
					entities[i]->kill();
				}
			}
			else
				continue;
		}
	}
}

void GameState::render(sf::RenderTarget* window)
{
	window->draw(marker);
	window->draw(*player);
	window->draw(scoreBoard);
	for (auto& i : entities)
	{
		window->draw(*i);
		//window->draw(i->getHitBox());
	}

	if(livesVec.size() > 0)
	{
		for (auto& i : livesVec)
		{
			window->draw(i);
		}
	}
}

void GameState::close()//save game
{
	std::ofstream out("game_save.txt", std::ios::trunc); //clears save and rewrites te whole thing
	out << player->getPosition().x << '\n';
	out << player->getPosition().y << '\n';
	out << score << '\n';
	out << lives << '\n';
	out.close();

	for (int i = entities.size() - 1; i >= 0; i--)
	{
		delete entities[i];
	}
	delete player;
	canClose = true;
}