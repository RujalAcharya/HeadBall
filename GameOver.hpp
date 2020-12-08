#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

namespace HeadBall {
    class GameOver : public State {
        public:
            GameOver (GameDataRef data, ScoreTimeRef scoreTime);
            void init ( );
            void handleInput ( );
            void update ( );
            void draw ( );

        private:
            GameDataRef _data;
            ScoreTimeRef _scoreTime;
            // sf::Sound _crowdCheerOnGoal;
            sf::Text _text;
    };
}