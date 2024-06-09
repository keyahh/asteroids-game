#include "Textures.h"

sf::Texture* Textures::getTexture(textureEnum texture)
{
    if (textures.count(texture) == 0)
        loadTexture(texture);
    return &textures[texture];
}

void Textures::loadTexture(textureEnum texture)
{
    textures[texture].loadFromFile(getTexturePath(texture));
}

std::string Textures::getTexturePath(textureEnum texture)
{
    switch (texture)
    {
    case PLAYER:
        return "images/entities/player.png";
        break;
    case BULLET:
        return "images/entities/bullet.png";
        break;
    case ASTEROID_LARGE:
        return "images/entities/asteroid_large.png";
        break;
    case ASTEROID_MEDIUM:
        return "images/entities/asteroid_medium.png";
        break;
    case ASTEROID_SMALL:
        return "images/entities/asteroid_small.png";
        break;
    case EXPLOSION:
        return "images/entities/explosion.png";
        break;
    case PLANETS:
        return "images/entities/planets.png";
        break;
    case SPLASH_SCREEN:
        return "images/splashscreen.png";
        break;
    case MENU_ART:
        return "images/art.png";
        break;
    case BIG_EXPLOSION:
        return "images/entities/bigexplosion.png";
        break;
    }
}
