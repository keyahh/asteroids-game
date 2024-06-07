//
// Created by Dave R. Smith on 5/21/24.
//

#ifndef CS3A_SPRING24_CALCULATOR_FONTS_H
#define CS3A_SPRING24_CALCULATOR_FONTS_H
#include <SFML/Graphics.hpp>
#include <map>
class Fonts
{
public:
    enum fontEnum {
        OPEN_SANS_BOLD,
        OPEN_SANS_REGULAR
    };
    static sf::Font& getFont(fontEnum font);
private:
    inline static std::map<fontEnum, sf::Font> fonts;
    static void loadFont(fontEnum font);
    static std::string getFontPath(fontEnum font);
};


#endif //CS3A_SPRING24_CALCULATOR_FONTS_H
