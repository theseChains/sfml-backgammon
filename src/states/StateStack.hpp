#ifndef STATE_STACK_HPP
#define STATE_STACK_HPP

#include "../Aliases.hpp"
#include "State.hpp"

#include <vector>

class StateStack
{
public:
    enum class Action
    {
        push,
        pop,
        clear
    };

    explicit StateStack(State::Context context);
    StatePtr createState(States::ID stateID);

    void draw();
    void handleEvent(const sf::Event& event);

    void pushState(States::ID stateID);
    void popState();
    void clearStates();

    bool isEmpty() const;

private:
    struct PendingChange
    {
        PendingChange(Action action, States::ID stateID = States::ID::none);

        Action m_action{};
        States::ID m_stateID{};
    };

    std::vector<StatePtr> m_stack{};
    std::vector<PendingChange> m_pendingChanges{};

    State::Context m_context;

    void applyPendingChanges();
};

#endif
