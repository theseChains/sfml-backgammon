#ifndef GAME_HPP
#define GAME_HPP

#include <array>
#include "Slot.hpp"
#include "Random.hpp"
#include "ChipColor.hpp"
#include "Constants.hpp"
#include "PlayerTurn.hpp"

class Game {
  public:
  int GetSlotIndex(const sf::Event& event, sf::RenderWindow& window);
  void SlotInit();
  void setDices();
  void setDolbaeb(bool fl);
  void chooseChip(const sf::Event& event, sf::RenderWindow& window, PlayerTurn turn);
  void handleChipMovement(const sf::Event& event, sf::RenderWindow& window, PlayerTurn turn);
  bool moveIsValid(int slotMovedFromIndex, int slotMovedToIndex);
  void ChangeHeight(int slot_id);
  bool SlotsSameColor(int from_, int to_);
  void StartPosition();

  bool isMoveState() const;
  bool isDiceThrowState() const;
  bool isChipChooseState() const;

  void setMoveState(bool moveState);
  void setDiceThrowState(bool diceThrowState);
  void setChipChooseState(bool chipChooseState);

  private:
  std::array<Slot, constants::numberOfSlots> slots;
  int dice_1, dice_2;
  Random rnd;
  bool is_timur;
  int slot_index_take, slot_index_drop;

  bool m_diceThrowState;
  bool m_moveState;
  bool m_chipChooseState;
};

#endif
