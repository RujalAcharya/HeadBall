#pragma once 

#include <memory>
#include <stack>

#include "State.hpp"

namespace HeadBall {
    typedef std::unique_ptr <State> StateRef;

    class StateMachine {
        public:
            StateMachine ( ) { }
            ~StateMachine ( ) { }

            void addState (StateRef newState, bool isReplacing = true);
            void removeState ( );
            void processStateChanges ( );

            StateRef& getActiveState ( );

        private:
            std::stack <StateRef> _states;
            StateRef _newState;

            bool _isReplacing;
            bool _isAdding;
            bool _isRemoving;
    };
}