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
            sf::Sprite _exitBtn;
            sf::Sound _btnClickSfx;
            sf::Music _theme;
            // sf::Text _text;
    };
}
