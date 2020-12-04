#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"
#include "TimeManager.hpp"

namespace HeadBall {
    class GameState : public State {
        public:
            GameState (GameDataRef data);
            void init ( );
            void handleInput ( );
            void update (float dt);
            void draw (float dt);
            void pause ( );
            void resume ( );

        private:
            GameDataRef _data;

            TimeManager _timer;

            sf::Font _font;
            sf::Text _text;

            bool _isPaused;
            bool _isSecondHalf;
    };
}