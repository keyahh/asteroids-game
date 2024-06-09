#ifndef BUTTON
#define BUTTON

#include "MouseEvents.h"
#include "ColorPalette.h"
#include "../Fonts.h"
#include "Position.h"
#include <string>
#include <iostream>

class Button : public sf::CircleShape
{
private:
	sf::Text text;
	sf::Color defaultColor, hoverColor;
	bool canClick = true, clicked = false;
	float clickCoolDown = 0.3f, clickTime = 0.f;

	void centerText();

public:
	Button();
	Button(const std::string& text, const sf::Font& font, const sf::Color& defaultColor);
	Button(const std::string& text, const sf::Font& font, const sf::Color& defaultColor, const sf::Color& hoverColor);
	Button(const std::string& text, const sf::Font& font, float buttonRadius = 50, const sf::Color& defaultColor = ColorPalette::charcoal, const sf::Color& hoverColor = ColorPalette::lightGray, const sf::Color& textColor = sf::Color::White, int fontSize = 30);

	void create(const std::string& text, const sf::Font& font, float buttonRadius = 50, const sf::Color& defaultColor = ColorPalette::charcoal, const sf::Color& hoverColor = ColorPalette::lightGray, const sf::Color& textColor = sf::Color::White, int fontSize = 30);

	void eventHandler(sf::RenderWindow& window, sf::Event event, float dt, int pad = 0);

	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
	virtual void setPosition(const sf::Vector2f& position);

	void update(float dt);

	void setDefaultColor(const sf::Color& defaultColor);
	void setHoverColor(const sf::Color& hoverColor);

	bool getClicked() const;
	void setClicked(bool flag);
	void setCanClick(bool flag);
	const sf::String& getString() const;
};

#endif