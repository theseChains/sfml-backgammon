#ifndef GAME_HPP
#define GAME_HPP

#include <array>
#include <iostream>
#include "Slot.hpp"
#include "Random.hpp"
#include "ChipColor.hpp"
#include "Constants.hpp"
#include "PlayerTurn.hpp"
#include "MoveCount.hpp"

class Game {
  public:
  Game(const TextureHolder& textures);
  int GetSlotIndex(const sf::Event& event, sf::RenderWindow& window);
  void SlotInit();
  void setDices();
  int getDice1();
  int getDice2();
  void setDolbaeb(bool fl);
  void chooseChip(const sf::Event& event, sf::RenderWindow& window, PlayerTurn turn);
  void handleChipMovement(const sf::Event& event, sf::RenderWindow& window, PlayerTurn turn);
  MoveCount moveIsValid(int slotMovedFromIndex, int slotMovedToIndex, ChipColor color);
  void moveChip();
  void ChangeHeight(int slot_id);
  bool SlotsSameColor(int from_, int to_);
  void StartPosition(const TextureHolder& textures);

  bool isMoveState() const;
  bool isDiceThrowState() const;
  bool isChipChooseState() const;

  void setMoveState(bool moveState);
  void setDiceThrowState(bool diceThrowState);
  void setChipChooseState(bool chipChooseState);

  void draw(sf::RenderWindow& window);

  // remove later
  void drawBounds(sf::RenderWindow& window);

  private:
  std::array<Slot, constants::numberOfSlots> slots;
  int dice_1, dice_2;
  Random rnd;
  bool is_timur;
  int slot_index_take, slot_index_drop;

  bool m_diceThrowState = 1;
  bool m_moveState = 0;
  bool m_chipChooseState = 0;
  int stop_move = 0;
  bool was_taken_from_head = 0;
};

#endif
