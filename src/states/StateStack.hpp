#ifndef STATE_STACK_HPP
#define STATE_STACK_HPP

#include "State.hpp"

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


};

#endif
