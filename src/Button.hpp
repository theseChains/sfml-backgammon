#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

#include "ButtonInfo.hpp"

class Button
{
public:
   Button(const ButtonInfo& buttonInfo);

   bool isClicked(const sf::Event& event, sf::RenderWindow& window);
   void draw(sf::RenderWindow& window) const;

private:
   sf::RectangleShape m_rectangle;
   ButtonInfo m_buttonInfo;
};

#endif
