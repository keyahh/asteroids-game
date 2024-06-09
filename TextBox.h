#ifndef TEXTBOX
#define TEXTBOX

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Helper/MouseEvents.h"

class TextBox : public sf::RectangleShape
{
private:
	sf::Text text;
	sf::RenderWindow* window;

	bool canClick = true, clicked = false;
	float clickCoolDown = 0.25, clickTime = 0;

	void centerText(const sf::Shape& obj, sf::Text& text);
	void alignLeft(const sf::Shape& obj, sf::Text& text);
	
public:
	TextBox();
	TextBox(const std::string& text, const sf::Font& font, const sf::Vector2f& size);
	TextBox(const std::string& text, const sf::Font& font, const sf::Vector2f& boxSize, int fontSize, const sf::Color& textColor, const sf::Color& boxColor);

	void create(const std::string& text, const sf::Font& font, const sf::Vector2f& boxSize, int fontSize, const sf::Color& textColor, const sf::Color& boxColor);

	void eventHandler(sf::RenderWindow& window, sf::Event event, float dt, int pad = 0);

	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
	void setPosition(const sf::Vector2f& position, int alignment);
	virtual void setPosition(const sf::Vector2f& position);

	bool checkClick(sf::Window* window) const;
	void update(float dt);

	void setText(const std::string& text);
	void setTextObj(const std::string& text, const sf::Font& font, int fontSize);
	const std::string& getString() const;

	bool getClicked() const;
};

#endif
