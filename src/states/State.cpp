#include "State.hpp"
#include "StateStack.hpp"

State::Context::Context(sf::RenderWindow& window, TextureHolder& textures,
                        FontHolder& fonts)
    : m_window{ &window }, m_textures{ &textures }, m_fonts{ &fonts }
{
}

State::State(StateStack& stack, Context context)
    : m_stack{ &stack }, m_context{ context }
{
}

State::~State()
{
}

void State::requestStackPush(States::ID stateID)
{
    m_stack->pushState(stateID);
}

void State::requestStackPop()
{
    m_stack->popState();
}

void State::requestStackClear()
{
    m_stack->clearStates();
}

State::Context State::getContext() const
{
    return m_context;
}
