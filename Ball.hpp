#pragma once

#include "Game.hpp"

namespace HeadBall {
    class Ball {
        public:
            Ball (GameDataRef data, WorldRef world);
            void init ( );
            sf::CircleShape shape ( );
            void processPosition ( );
            void rePosition ( );

        private:
            GameDataRef _data;
            WorldRef _world;

            sf::CircleShape _shape;
            sf::Sprite _ballSprite;

            b2BodyDef _bodyDef;
            b2Body* _body;
            b2CircleShape _circleShape;
            b2FixtureDef _fixture;
    };
}