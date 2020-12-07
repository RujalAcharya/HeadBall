#pragma once 

#include "Game.hpp"

namespace HeadBall {
    class Wall {
        public:
            Wall (GameDataRef data, WorldRef world);
            void init ( );

    private:
        GameDataRef _data;
        WorldRef _world;

        b2BodyDef _leftDef, _rightDef, _topDef, _lPostDef, _rPostDef;
        b2Body* _leftBody;
        b2Body* _rightBody;
        b2Body* _topBody;
        b2Body* _leftPost;
        b2Body* _rightPost;
        b2PolygonShape _leftShape, _rightShape, _topShape, _lPostShape, _rPostShape;
        b2FixtureDef _leftFixture, _rightFixture, _topFixture, _lPostFixture, _rPostFixture;
    };

}