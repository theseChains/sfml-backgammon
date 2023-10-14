#ifndef SLOT_HPP
#define SLOT_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "Chip.hpp"
#include "ChipColor.hpp"
#include "Constants.hpp"

class Slot
{
public:
    float getXLeft();
    float getYTop();
    void setYTop(float newTop);
    float getHeight();
    sf::FloatRect getBounds();
    void setBounds(float x_left, float y_top);
    void setHeight(float height);
    void setWidth(float width);
    int getChipsCount();
    void setChipsCount(int count);
    ChipColor getChipColor();
    void setChipColor(ChipColor color);
    void incrementChipCount();
    void decrementChipCount();

    void pushChip(const Chip& chip);
    Chip popChip();
    void clearChips();

    // remove later
    void drawSlotBounds(sf::RenderWindow& window, int index);
    void drawChips(sf::RenderWindow& window);

private:
    sf::FloatRect m_bounds;
    int m_chipCount;
    ChipColor m_chipColor;
    std::vector<Chip> m_chips;

    // remove later
    sf::RectangleShape m_boundsRectangle;
};

#endif  // SLOT_HPP
