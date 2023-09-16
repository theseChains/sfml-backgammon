#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "../Board.hpp"
#include "State.hpp"

class GameState : public State
{
public:
    GameState(StateStack& stack, Context context);

    void draw() override;
    bool handleEvent(const sf::Event& event) override;

private:
    Board m_board;
};

#endif
