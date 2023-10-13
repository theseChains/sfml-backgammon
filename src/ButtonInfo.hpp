#ifndef BUTTON_INFO_HPP
#define BUTTON_INFO_HPP

#include <SFML/Graphics.hpp>
#include <string>

struct ButtonTextInfo
{
    unsigned int characterSize;
    std::string text;
    sf::Vector2f position;
    sf::Color color;
};

struct ButtonInfo
{
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color color;
    ButtonTextInfo buttonTextInfo;
};

#endif
