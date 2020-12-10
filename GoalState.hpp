#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

namespace HeadBall {
    class GoalState : public State {
        public:
            GoalState (GameDataRef data, ScoreTimeRef scoretime, bool isSecondHalf);
            void init ( );
            void handleInput ( );
            void update ( );
            void draw ( );

        private:
            GameDataRef _data;
            ScoreTimeRef _scoreTime;
            sf::Sound _crowdCheerOnGoal;
            sf::Text _text;
            sf::Sprite _background;

            bool _isSecondHalf;
            int _animationCounter;
    };
}