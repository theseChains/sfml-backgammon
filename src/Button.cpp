#include "Button.hpp"

Button::Button(ButtonInfo& buttonInfo, const sf::Font& font)
    : m_rectangle{}, m_text{}
{
    m_rectangle.setSize(buttonInfo.size);
    m_rectangle.setFillColor(buttonInfo.color);
    m_rectangle.setPosition(buttonInfo.position);

    m_text.setFont(font);
    m_text.setString(buttonInfo.buttonTextInfo.text);
    m_text.setCharacterSize(buttonInfo.buttonTextInfo.characterSize);
    m_text.setPosition(buttonInfo.buttonTextInfo.position);
    m_text.setFillColor(buttonInfo.buttonTextInfo.color);
    m_buttonInfo = buttonInfo;
}

bool Button::isClicked(const sf::Event& event, sf::RenderWindow& window)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    float startX{ m_buttonInfo.position.x };
    float endX{ m_buttonInfo.position.x + m_buttonInfo.size.x };
    float startY{ m_buttonInfo.position.y };
    float endY{ m_buttonInfo.position.y + m_buttonInfo.size.y };
    if (startX <= mousePosition.x && mousePosition.x <= endX &&
        startY <= mousePosition.y && mousePosition.y <= endY &&
        event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left)
    {
        return true;
    }

    return false;
}

void Button::setText(const sf::String& string)
{
    m_text.setString(string);
}

void Button::draw(sf::RenderWindow& window) const
{
    window.draw(m_rectangle);
    window.draw(m_text);
}
