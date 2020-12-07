#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"
#include "InputManager.hpp"

namespace HeadBall {
    class MenuScreen : public State {
        public:
            MenuScreen (GameDataRef data);
            void init ( );
            void handleInput ( );
            void update ( );
            void draw ( );

        private:
            GameDataRef _data;
            ScoreTimeRef _scoretime = std::make_shared <ScoreTimeData> ( );
            sf::Sprite _background;
            sf::Sprite _playBtn;
            sf::Sprite _instructionsBtn;
            sf::Sprite _aboutBtn;
            sf::Sprite _exitBtn;
            sf::Music _theme;
            sf::Text _text;
    };
}