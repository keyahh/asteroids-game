//
// Created by Dave R. Smith on 5/21/24.
//

#include "Fonts.h"

sf::Font& Fonts::getFont(Fonts::fontEnum font)
{
    if (fonts.count(font) == 0)
        loadFont(font);
    return fonts[font];
}

void Fonts::loadFont(Fonts::fontEnum font)
{
    fonts[font].loadFromFile(getFontPath(font));
}

std::string Fonts::getFontPath(Fonts::fontEnum font)
{
    switch (font)
    {
    case OPEN_SANS_BOLD: return "fonts/OpenSans-Bold.ttf";
    case OPEN_SANS_REGULAR: return "fonts/opensans.ttf";
    }
}
