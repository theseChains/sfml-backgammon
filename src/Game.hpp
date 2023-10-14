#ifndef GAME_HPP
#define GAME_HPP

#include <array>
#include <iostream>

#include "ChipColor.hpp"
#include "Constants.hpp"
#include "MoveCount.hpp"
#include "PlayerTurn.hpp"
#include "Random.hpp"
#include "Slot.hpp"

class Game
{
public:
    Game(TextureHolder& textures);
    int GetSlotIndex(const sf::Event& event, sf::RenderWindow& window);
    void SlotInit();
    void setDices();
    int getDice1();
    int getDice2();
    void setDolbaeb(bool fl);
    void chooseChip(const sf::Event& event, sf::RenderWindow& window);
    void handleChipMovement(const sf::Event& event, sf::RenderWindow& window,
                            PlayerTurn& turn);
    MoveCount moveIsValid(int slotMovedFromIndex, int slotMovedToIndex,
                          ChipColor color);
    void updateSlotChips(Slot& slot, int slotIndex);
    void moveChip();
    void ChangeHeight(int slot_id);
    bool SlotsSameColor(int from_, int to_);
    void StartPosition(const TextureHolder& textures);
    bool SexChips(int slotMovedToIndex, ChipColor col);
    bool CheckMoves(PlayerTurn & turn);

    bool isMoveState() const;
    bool isDiceThrowState() const;
    bool isChipChooseState() const;

    void setMoveState(bool moveState);
    void setDiceThrowState(bool diceThrowState);
    void setChipChooseState(bool chipChooseState);
    bool home(ChipColor col);
    void change_states();
    MoveCount home_play(ChipColor color, int slotfrom);
    bool checkForEmptySlots(int num, int dice);

    void draw(sf::RenderWindow& window);

    // remove later
    void drawBounds(sf::RenderWindow& window);

private:
    std::array<Slot, constants::numberOfSlots + 2> slots;
    TextureHolder& m_textures;
    int dice_1, dice_2, dice_3, dice_4;
    Random rnd;
    bool is_timur;
    int slot_index_take, slot_index_drop;

    bool m_diceThrowState = 1;
    bool dubl;
    bool m_moveState = 0;
    bool m_chipChooseState = 0;
    bool was_taken_from_head = 0;
};

#endif
