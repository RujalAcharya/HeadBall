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
            void update ( );
            void draw ( );

        private:
            GameDataRef _data;
            sf::Clock _clock;

            sf::Sprite _backgroundSprite;
            sf::Sprite _flagSprite;
    };
}