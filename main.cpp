#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Pokemon");
    Game Game(&window);
    Game.run();

    return 0;
}

