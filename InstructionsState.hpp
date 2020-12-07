#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

namespace HeadBall {
    class InstructionsState : public State {
        public:
            InstructionsState (GameDataRef data);
            void init ( );
            void handleInput ( );
            void update ( );
            void draw ( );

        private:
            GameDataRef _data;
            sf::Sprite _background;            
            sf::Sprite _backBtn;
            sf::Sprite _exitBtn;

            sf::Text _text;
    };
}
