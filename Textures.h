#ifndef TEXTURESH
#define TEXTURESH

#include <SFML/Graphics.hpp>
#include <map>

class Textures
{
public:
    enum textureEnum {
        PLAYER,
        BULLET,
        ASTEROID_LARGE,
        ASTEROID_MEDIUM,
        ASTEROID_SMALL,
        EXPLOSION,
        PLANETS,
        SPLASH_SCREEN,
        MENU_ART,
        BIG_EXPLOSION
    };
    static sf::Texture* getTexture(textureEnum texture);
private:
    inline static std::map<textureEnum, sf::Texture> textures;
    static void loadTexture(textureEnum texture);
    static std::string getTexturePath(textureEnum texture);
};

#endif