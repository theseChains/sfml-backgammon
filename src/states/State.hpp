#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>

#include "../ResourceIdentifiers.hpp"
#include "StateIdentifiers.hpp"

class StateStack;

class State
{
public:
    struct Context
    {
        Context(sf::RenderWindow& window, TextureHolder& textures,
                FontHolder& fonts);

        sf::RenderWindow* m_window{};
        TextureHolder* m_textures{};
        FontHolder* m_fonts{};
    };

    State(StateStack& stack, Context context);
    // virtual ~State();

    // virtual void draw() = 0;
    // virtual void handleEvent(const sf::Event& event) = 0;

protected:
    void requestStackPush(States::ID stateID);
    void requestStackPop();
    void requestStackClear();

    Context getContext();

private:
    StateStack* m_stack{};
    Context m_context;
};

#endif
