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

	scoreBox.create("0", window, *font, { 100, 50 }, 40, sf::Color::White, sf::Color::Transparent);

	player = new Player(textures[0]);

	marker.setSize({ 50,50 });
	marker.setFillColor(sf::Color::Red);
	marker.setPosition({ 100, 100 });

	scoreBox.setPosition({ player->getPosition().x - static_cast<float>(window->getSize().x / 2) + 10, player->getPosition().y - static_cast<float>(window->getSize().y / 2) + 10 });


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
	out << "0\n";
	out << "0\n";
	out.close();

	//player.setPosition({ static_cast<float>(window->getSize().x / 2 - player.getGlobalBounds().width / 2), static_cast<float>(window->getSize().y / 2 - player.getGlobalBounds().height / 2) });
	playerCamera.reset((sf::FloatRect(0, 0, window->getSize().x, window->getSize().y)));
	//playerCamera.setCenter({ player.getPosition().x + player.getGlobalBounds().width / 2, player.getPosition().y + player.getGlobalBounds().height / 2 });
}

void GameState::loadFromFile()
{
	std::ifstream in("game_save.txt");
	std::string data;

	getline(in, data);
	float x = std::stof(data);
	getline(in, data);
	float y = std::stof(data);
	
	sf::Vector2f playerPos = { x, y };
	player->setPosition(playerPos);
	playerCamera.reset(sf::FloatRect(x, y, window->getSize().x, window->getSize().y));
	playerCamera.setCenter(playerPos);
	in.close();
}

void GameState::setAsteroid()
{
	float randXPos = player->getPosition().x + ((rand() % (350 - 251) + 300) * (rand() % 2 - 1));
	float randYPos = player->getPosition().y + ((rand() % (350 - 251) + 300) * (rand() % 2 - 1));

	entities.push_back(new Asteroid(textures[2], 500, rand() % 360, {randXPos, randYPos }));
}

void GameState::summonAsteroids()
{
	for (int i = 0; i < 10; i++)
	{
		setAsteroid();
	}
}

float GameState::getDistance(Entity* entity1, Entity* entity2)
{
	return std::sqrtf(pow(entity2->getPosition().x - entity1->getPosition().x, 2) + pow(entity2->getPosition().y - entity1->getPosition().y, 2));
}

void GameState::update(const float& dt)
{
	//playerCamera.setCenter({ player.getPosition().x + player.getGlobalBounds().width / 2, player.getPosition().y + player.getGlobalBounds().height / 2 });
	scoreBox.setPosition({ player->getPosition().x - static_cast<float>(window->getSize().x / 2) + 10, player->getPosition().y - static_cast<float>(window->getSize().y / 2) + 10 });
	playerCamera.setCenter(player->getPosition());
	window->setView(playerCamera);
	player->update(dt, window, playerCamera);

	if (player->checkShot())
	{
		entities.push_back(new Bullet(textures[1], player->getRotation(), player->getPosition(), true));
		player->setShot(false);
	}

	asteroidSpawnTimeProgress += dt;
	if (asteroidSpawnTimeProgress >= asteroidSpawnTime)
	{
		summonAsteroids();
		asteroidSpawnTimeProgress = 0;
	}

	for (int i = entities.size() - 1; i >= 0; i--)
	{
		entities[i]->update(dt, window, playerCamera);

		if (getDistance(player, entities[i]) >= 600) //remove asteroids and bullets that are too far away from player
			entities[i]->kill();

		if (entities[i]->getCanKill()) //destroy entities marked to be killed
			entities.erase(entities.begin() + i);
	}
}

void GameState::render(sf::RenderTarget* window)
{
	window->draw(marker);
	window->draw(*player);
	window->draw(scoreBox);
	for (auto& i : entities)
	{
		window->draw(*i);
	}
}

void GameState::close()//save game
{
	std::ofstream out("game_save.txt", std::ios::trunc); //clears save and rewrites te whole thing
	out << player->getPosition().x << '\n';
	out << player->getPosition().y << '\n';
	out.close();

	for (int i = entities.size() - 1; i >= 0; i--)
	{
		delete entities[i];
	}
	delete player;
	canClose = true;
}