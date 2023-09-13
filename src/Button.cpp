#include "Button.hpp"

#include <iostream>

Button::Button(const ButtonInfo& buttonInfo)
  : m_rectangle{},
    m_text{}
{
  //button
  m_rectangle.setSize(buttonInfo.size);
  std::cout << "x: " << m_rectangle.getSize().x << '\n';
  std::cout << "y: " << m_rectangle.getSize().y << '\n';
  m_rectangle.setFillColor(buttonInfo.color);
  m_rectangle.setPosition(buttonInfo.position);
  //text
  m_text.setString(buttonInfo.buttonTextInfo.text);
  m_text.setFont(buttonInfo.buttonTextInfo.font);
  m_text.setCharacterSize(buttonInfo.buttonTextInfo.characterSize);
  m_text.setFillColor(buttonInfo.buttonTextInfo.color);
  m_text.setPosition(buttonInfo.buttonTextInfo.position);
  std::cout << "constructed button\n";
}

bool Button::isClicked(const sf::Event& event, sf::RenderWindow& window)
{
  std::cout << "!\n";
  sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
  float start_x = m_buttonInfo.position.x;
  float end_x = m_buttonInfo.position.x * m_buttonInfo.size.x;
  float start_y = m_buttonInfo.position.y;
  float end_y = m_buttonInfo.position.y * m_buttonInfo.size.y;
  if (start_x <= mousePosition.x <= end_x && start_y <= mousePosition.y <= end_y &&
      event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) 
  {
    // m_buttonInfo.color.b += 50;
    std::cout << "clicked!\n";
    return true;
  }
  return false;
}

 void Button::draw(sf::RenderWindow& window) const
 {
   window.draw(m_rectangle);
   // window.draw(m_text);
 }

