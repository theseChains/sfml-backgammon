#include "Chip.hpp"

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

Chip::Chip(const sf::Vector2f& position, ChipColor color, const TextureHolder& textures)
    : m_position{ position },
      m_color{ color },
      m_chipCircle{},
      m_texture{}
{
    m_chipCircle.setPosition(position);
    m_chipCircle.setRadius(constants::chipRadius);
    // m_chipCircle.setTexture(&m_texture);
}

void Chip::draw(sf::RenderWindow& window)
{
    window.draw(m_chipCircle);
}
