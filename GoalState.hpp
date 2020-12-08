#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

namespace HeadBall {
    class GoalState : public State {
        public:
            GoalState (GameDataRef data, ScoreTimeRef scoretime);
            void init ( );
            void handleInput ( );
            void update ( );
            void draw ( );

        private:
            GameDataRef _data;
            ScoreTimeRef _scoreTime;

            sf::Text _text;
    };
}