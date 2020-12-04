#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

namespace HeadBall {
    class SplashScreen : public State {
        public:
            SplashScreen (GameDataRef data);
            void init ( );
            void handleInput ( );
            void update (float dt);
            void draw (float dt);

        private:
            GameDataRef _data;
            sf::Clock _clock;

            sf::Font _font;
            sf::Text _text;
    };
}