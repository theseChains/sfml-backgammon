#include "GameState.hpp"

GameState::GameState(StateStack& stack, Context context)
    : State{ stack, context },
      m_board{ context.m_fonts->get(Fonts::ID::main), *context.m_textures, *context.m_window }
{
}

void GameState::draw()
{
    m_board.draw();
}

bool GameState::handleEvent(const sf::Event& event)
{
    m_board.handleEvent(event);
    return true;
}
