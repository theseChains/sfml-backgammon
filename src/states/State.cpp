#include "State.hpp"

State::Context::Context(sf::RenderWindow& window, TextureHolder& textures,
                        FontHolder& fonts)
    : m_window{ &window }, m_textures{ &textures }, m_fonts{ &fonts }
{
}

State::State(StateStack& stack, Context context)
    : m_stack{ &stack }, m_context{ context }
{
}
