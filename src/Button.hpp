#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

#include "ButtonInfo.hpp"

class Button
{
public:
    Button() = default;
    Button(ButtonInfo& buttonInfo, const sf::Font& font);
    bool isClicked(const sf::Event& event, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window) const;
    void setText(const sf::String& str);

private:
    sf::RectangleShape m_rectangle;
    sf::Text m_text;
    ButtonInfo m_buttonInfo;
};

#endif
