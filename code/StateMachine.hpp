#pragma once 

#include <memory>
#include <stack>

#include "State.hpp"

namespace HeadBall {
    /*!
     * @brief The Unique Pointer for storing the States
     * 
     * All the states are inherited from the abstract class `State` that makes it possible to use a same pointer for all the states
     * 
     */
    typedef std::unique_ptr <State> StateRef;

    /*!
     * @brief The class that manages the states in the project
     * 
     * This class manages all the states in the game in a stack. In every game loop, the state at the top of the stack is resumed.
     * 
     */
    class StateMachine {
        public:
            /*!
             * @brief Construct a new State Machine object
             * 
             */
            StateMachine ( ) { }

            /*!
             * @brief Destroy the State Machine object
             * 
             */
            ~StateMachine ( ) { }

            /*!
             * @brief Add a new state to the state machine
             * 
             * @param newState The Unique Pointer to new state
             * @param isReplacing Whether the top state at the stack is being replaced or another state is being pushed at the top of it
             */
            void addState (StateRef newState, bool isReplacing = true);

            /*!
             * @brief Remove the state at the top of the stack
             * 
             */
            void removeState ( );

            /*!
             * @brief Process the changes in the state
             * 
             */
            void processStateChanges ( );

            /*!
             * @brief Get the Active State object i.e the state at the top of the stack
             * 
             * @return StateRef& The reference to the state at the top of the stack
             */
            StateRef& getActiveState ( );

        private:
            std::stack <StateRef> _states;          //!< The stack where the states in the game are kept 
            StateRef _newState;                     //!< The Unique Pointer to new state that is beong added

            bool _isReplacing;                      //!< Whether the state at the top of stack is being popped or another state is being pushed at the top of it
            bool _isAdding;                         //!< Whether a new state is being added
            bool _isRemoving;                       //!< Whether the state at the top of stack is being popped
    };
}