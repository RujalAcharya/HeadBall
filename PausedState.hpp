#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

namespace HeadBall {
    class PausedState : public State {
        public:
            PausedState (GameDataRef data);
            void init ( );
            void handleInput ( );
            void update ( );
            void draw ( );

        private:
            GameDataRef _data;
            sf::Sprite _background;
            sf::Sprite _resumeBtn;
            sf::Sprite _instructionsBtn;
            sf::Sprite _aboutBtn;
            sf::Sprite _exitBtn;

            sf::Text _text;
    };
}
