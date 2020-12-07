#pragma once
#include "Game.hpp"

namespace HeadBall{
    class GoalPost {
        public:
            GoalPost (GameDataRef data);
            void init (sf::Vector2f position, bool isLeft = true);
            sf::Sprite sprite ( );

        private:
            GameDataRef _data;
            WorldRef _world;

            sf::Sprite _sprite;
    };   
}