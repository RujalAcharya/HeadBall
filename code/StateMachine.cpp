#include "StateMachine.hpp"

namespace HeadBall {
    void StateMachine::addState (StateRef newState, bool isReplacing) {
        this-> _isAdding = true;
        this->_isReplacing = isReplacing;

        this->_newState =  std::move(newState);
    }

    void StateMachine::removeState ( ) {
        this->_isRemoving = true;
    }

    void StateMachine::processStateChanges ( ) {
        if (_isRemoving == true && !_states.empty() ) {
            this->_states.pop( );

            if (!_states.empty ( )) {
                this->_states.top( )->resume( );
            }

            this->_isRemoving = false;
        }

        if (_isAdding == true) {
            if (_isReplacing == true && !_states.empty()) {
                this->_states.pop( );
            } else if (!_states.empty()) {
                this->_states.top( )->pause( );
            }

            this->_states.push(std::move(this->_newState));
            this->_states.top( )->init( );

            this->_isAdding = false;
        }
    }

    StateRef& StateMachine::getActiveState ( ) {
        return this->_states.top( );
    }
}