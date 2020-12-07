#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

namespace HeadBall {
    class AboutState : public State {
        public:
            AboutState (GameDataRef data);
            void init ( );
            void handleInput ( );
            void update ( );
            void draw ( );

        private:
            GameDataRef _data;
            sf::Sprite _background;            
            sf::Sprite _backBtn;
            sf::Sprite _exitBtn;
            // sf::Sprite _aboutBtn;
 

            sf::Text _text;
    };
}
