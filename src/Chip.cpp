#include "Chip.hpp"

#include "Constants.hpp"
#include <iostream>

Textures::ID toTextureID(ChipColor color)
{
    switch (color)
    {
        case ChipColor::white:
            return Textures::ID::whiteChip;
        case ChipColor::black:
            return Textures::ID::blackChip;
        default:
            return Textures::ID{};
    }
}

Chip::Chip(const sf::Vector2f& position, ChipColor color, const TextureHolder& textures)
    : m_position{ position },
      m_color{ color },
      m_chipCircle{}
{
    m_chipCircle.setPosition(position);
    m_chipCircle.setTexture(textures.get(toTextureID(m_color)));
}

void Chip::setPosition(const sf::Vector2f& position)
{
    m_position = position;
}

void Chip::draw(sf::RenderWindow& window)
{
    window.draw(m_chipCircle);
}
