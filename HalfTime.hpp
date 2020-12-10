#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

namespace HeadBall {
    class HalfTime : public State {
        public:
            HalfTime (GameDataRef data, ScoreTimeRef scoretime);
            void init ( );
            void handleInput ( );
            void update ( );
            void draw ( );

        private:
            GameDataRef _data;
            ScoreTimeRef _scoreTime;

            sf::Text _score;

            sf::Music _theme;
            sf::Sound _btnClickSfx;

            sf::Sprite _background;
            sf::Sprite _resumeBtn;
    };
}