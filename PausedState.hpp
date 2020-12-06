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
            void update (float dt);
            void draw (float dt);

        private:
            GameDataRef _data;
            
            sf::Text _text;
    };
}
