#pragma once

#include "Game.hpp"

namespace HeadBall {
    class Ground {
        public:
            Ground (GameDataRef data, WorldRef world);
            void init( );
            sf::RectangleShape shape (  );

        private:
            GameDataRef _data;
            WorldRef _world;

            sf::RectangleShape _shape;

            b2BodyDef _bodyDef;
            b2Body* _body;
            b2PolygonShape _polyShape;
            b2FixtureDef _fixture;
    };
}