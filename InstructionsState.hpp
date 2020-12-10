#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>

#include "State.hpp"
#include "Game.hpp"

namespace HeadBall {
    class InstructionsState : public State {
        public:
            InstructionsState (GameDataRef data);
            void init ( );
            std::string displayInstructions ( );
            void handleInput ( );
            void update ( );
            void draw ( );

        private:
            GameDataRef _data;
            sf::Sprite _background;            
            sf::Sprite _backBtn;
            sf::Sprite _exitBtn;
            sf::Sound _btnClickSfx;
            sf::Text _instructionsText;
            std::stringstream ss;

    };
}
