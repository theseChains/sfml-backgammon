#include "Chip.hpp"

#include <iostream>

#include "Constants.hpp"

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

Chip::Chip(const sf::Vector2f& position, ChipColor color,
           const TextureHolder& textures)
    : m_color{ color }, m_chipCircle{}
{
    m_chipCircle.setPosition(position);
    m_chipCircle.setTexture(textures.get(toTextureID(m_color)));
}

void Chip::setPosition(const sf::Vector2f& position)
{
    m_chipCircle.setPosition(position);
}

ChipColor Chip::getColor() const
{
    return m_color;
}

void Chip::draw(sf::RenderWindow& window)
{
    window.draw(m_chipCircle);
}
