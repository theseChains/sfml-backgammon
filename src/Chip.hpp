#ifndef CHIP_HPP
#define CHIP_HPP

#include <SFML/Graphics.hpp>

#include "ChipColor.hpp"
#include "ResourceIdentifiers.hpp"
#include "ResourceHolder.hpp"

class Chip
{
public:
    Chip() = default;
    Chip(const sf::Vector2f& position, ChipColor color, const TextureHolder& textures);

    void draw(sf::RenderWindow& window);

private:
    sf::Vector2f m_position;
    ChipColor m_color;
    sf::CircleShape m_chipCircle;
    sf::Texture m_texture;
};

#endif
