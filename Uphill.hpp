#pragma once

#include "Game.hpp"

namespace HeadBall {
    class UpHill {
        public:
            UpHill (GameDataRef data, WorldRef world);
            void init (sf::Vector2i position );
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