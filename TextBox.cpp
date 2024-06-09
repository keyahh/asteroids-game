#include "TextBox.h"

TextBox::TextBox()
	: window(nullptr)
{
	setSize({ 300, 50 });
	setFillColor(sf::Color::White);
}

TextBox::TextBox(const std::string& text, const sf::Font& font, const sf::Vector2f& size)
{
	setSize(size);
	setFillColor(sf::Color::White);
	TextBox::text = sf::Text(text, font, 24);
	TextBox::text.setFillColor(sf::Color::Black);
	alignLeft(*this, TextBox::text);
}

TextBox::TextBox(const std::string& text, const sf::Font& font, const sf::Vector2f& boxSize, int fontSize, const sf::Color& textColor, const sf::Color& boxColor)
{
	setSize(boxSize);
	setFillColor(boxColor);
	TextBox::text = sf::Text(text, font, fontSize);
	TextBox::text.setFillColor(textColor);
	centerText(*this, TextBox::text);
}

void TextBox::create(const std::string& text, const sf::Font& font, const sf::Vector2f& boxSize, int fontSize, const sf::Color& textColor, const sf::Color& boxColor)
{
	setSize(boxSize);
	setFillColor(boxColor);
	TextBox::text = sf::Text(text, font, fontSize);
	TextBox::text.setFillColor(textColor);
	centerText(*this, TextBox::text);
}

void TextBox::eventHandler(sf::RenderWindow& window, sf::Event event, float dt, int pad)
{
	if (MouseEvents::isClicked(*this, window, pad) && canClick)
	{
		clicked = true;
		canClick = false;
	}
}

void TextBox::alignLeft(const sf::Shape& obj, sf::Text& text)
{
	text.setPosition((obj.getGlobalBounds().left + 10), (obj.getGlobalBounds().top + obj.getGlobalBounds().height / 2 - text.getGlobalBounds().height / 1.5));
}

void TextBox::centerText(const sf::Shape& obj, sf::Text& text)
{
	text.setPosition((obj.getGlobalBounds().left + obj.getGlobalBounds().width / 2 - text.getGlobalBounds().width / 2),
		(obj.getGlobalBounds().top + obj.getGlobalBounds().height / 2 - text.getGlobalBounds().height / 1.5));
}

void TextBox::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	sf::RectangleShape parent = *this;
	window.draw(parent);
	window.draw(text);
}

void TextBox::setPosition(const sf::Vector2f& position, int alignment)
{
	sf::RectangleShape::setPosition(position);

	switch (alignment)
	{
	case 0:
		alignLeft(*this, text);
	case 1:
		centerText(*this, text);
	}
}

void TextBox::setPosition(const sf::Vector2f& position)
{
	sf::RectangleShape::setPosition(position);
	alignLeft(*this, text);
}

bool TextBox::checkClick(sf::Window* window) const
{
	if (canClick) {
		sf::Vector2f mousePos = (sf::Vector2f)sf::Mouse::getPosition(*window);
		return getGlobalBounds().contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
	}
	return false;
}

void TextBox::update(float dt)
{
	clickTime += dt;
	if (clickTime >= clickCoolDown)
	{
		clickTime = 0.f;
		canClick = true;
		clicked = false;
	}
}

void TextBox::setText(const std::string& text)
{
	TextBox::text.setString(text);
}

void TextBox::setTextObj(const std::string& text, const sf::Font& font, int fontSize)
{
	TextBox::text.setFillColor(sf::Color::Black);
	TextBox::text = sf::Text(text, font, fontSize);
}

const std::string& TextBox::getString() const
{
	return text.getString();
}

bool TextBox::getClicked() const
{
	return clicked;
}
