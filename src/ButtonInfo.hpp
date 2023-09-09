#ifndef BUTTON_INFO_HPP
#define BUTTON_INFO_HPP

#include <SFML/Graphics.hpp>

#include <string>

struct ButtonTextInfo
{
    sf::Font font;
    int characterSize;
    std::string text;
    sf::Vector2f position;
    sf::Color color;
};

struct ButtonInfo
{
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color color;
    sf::Color textColor;
    ButtonTextInfo buttonTextInfo;
};

#endif
