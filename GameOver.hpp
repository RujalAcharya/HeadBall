#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

namespace HeadBall {
    class GameOver : public State {
        public:
            GameOver (GameDataRef data);
            void init ( );
            void handleInput ( );
            void update (float dt);
            void draw (float dt);

        private:
            GameDataRef _data;

            sf::Font _font;
            sf::Text _text;
    };
}
