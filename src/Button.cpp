#include "Button.hpp"

Button::Button(ButtonInfo& buttonInfo, const sf::Font& font)
  : m_rectangle{},
    m_text{}
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
  float start_x = m_buttonInfo.position.x;
  float end_x = m_buttonInfo.position.x + m_buttonInfo.size.x;
  float start_y = m_buttonInfo.position.y;
  float end_y = m_buttonInfo.position.y + m_buttonInfo.size.y;
  if (start_x <= mousePosition.x && mousePosition.x <= end_x && start_y <= mousePosition.y && mousePosition.y <= end_y &&
      event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
  {
    // m_buttonInfo.color.b += 50;
    return true;
  }
  return false;
}

void Button::draw(sf::RenderWindow& window) const
{
   window.draw(m_rectangle);
   window.draw(m_text);
}
