#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "ResourceIdentifiers.hpp"

#include <unordered_map>

namespace constants
{
    inline constexpr int windowWidth{ 1920 };
    inline constexpr int windowHeight{ 1080 };
    inline constexpr int numberOfChips{ 15 };
    inline constexpr int numberOfSlots{ 24 };
    inline constexpr int SlotHeight{ 500 };
    inline constexpr int SlotWidth{ 125 };
    inline constexpr int EbannayaPalka{ 85 };

    inline constexpr int ChipDiam{ 125 };

    inline constexpr float firstChipDistanceConstant{ 4.5 };

    inline constexpr int lowerBound{ 1044 };

    inline std::unordered_map<int, Textures::ID> textureMap{
        { 1, Textures::ID::diceOne },
        { 2, Textures::ID::diceTwo },
        { 3, Textures::ID::diceThree },
        { 4, Textures::ID::diceFour },
        { 5, Textures::ID::diceFive },
        { 6, Textures::ID::diceSix }
    };
};

#endif
