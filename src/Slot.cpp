#include "Slot.hpp"

float Slot::getXLeft()
{
    return m_bounds.left;
}

float Slot::getYTop()
{
    return m_bounds.top;
}

void Slot::setYTop(float newTop)
{
    m_bounds.top = newTop;
}

sf::FloatRect Slot::getBounds()
{
    return m_bounds;
}

float Slot::getHeight()
{
    return m_bounds.height;
}

void Slot::setBounds(float x_left, float y_top)
{
    m_bounds.left = x_left;
    m_bounds.width = constants::SlotWidth;
    m_bounds.top = y_top;
    m_bounds.height = constants::SlotHeight;
}

void Slot::setHeight(float height)
{
    m_bounds.height = height;
}

int Slot::getChipsCount()
{
    return m_chipCount;
}

void Slot::setChipsCount(int count)
{
    m_chipCount = count;
}

ChipColor Slot::getChipColor()
{
    return m_chipColor;
}

void Slot::setChipColor(ChipColor color)
{
    m_chipColor = color;
}

void Slot::incrementChipCount()
{
    ++m_chipCount;
}

void Slot::decrementChipCount()
{
    --m_chipCount;
}

void Slot::pushChip(const Chip& chip)
{
    m_chips.push_back(chip);
}

Chip Slot::popChip()
{
    Chip chip{ m_chips.back() };
    m_chips.pop_back();
    return chip;
}

void Slot::clearChips()
{
    m_chips.clear();
}

void Slot::drawChips(sf::RenderWindow& window)
{
    for (int i{ 0 }; i < m_chips.size(); ++i)
    {
        m_chips[i].draw(window);
    }
}

void Slot::drawSlotBounds(sf::RenderWindow& window, int index)
{
    m_boundsRectangle.setSize({ m_bounds.width, m_bounds.height });
    m_boundsRectangle.setPosition({ m_bounds.left, m_bounds.top });
    m_boundsRectangle.setFillColor(sf::Color::Transparent);
    m_boundsRectangle.setOutlineThickness(2.0f);
    if (index >= 0 && index < 6)
        m_boundsRectangle.setOutlineColor(sf::Color::Blue);
    else if (index >= 6 && index < 12)
        m_boundsRectangle.setOutlineColor(sf::Color::Yellow);
    if (index >= 12 && index < 18)
        m_boundsRectangle.setOutlineColor(sf::Color::Magenta);
    if (index >= 18 && index < 24)
        m_boundsRectangle.setOutlineColor(sf::Color::Green);

    window.draw(m_boundsRectangle);
}
