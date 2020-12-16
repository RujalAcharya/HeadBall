#include "Wall.hpp"
#include "Definition.hpp"
#include "Converter.hpp"

namespace HeadBall {
    Wall::Wall (GameDataRef data, WorldRef world) : _data{data}, _world{world} { }

    void Wall::init ( ) {
        this->_leftDef.position.Set (Converter::pixelsToMeters (- WALL_THICKNESS / 2), Converter::pixelsToMeters (WINDOW_HEIGHT / 2));
        this->_leftBody = this->_world->CreateBody (& this->_leftDef);
        this->_leftShape.SetAsBox (Converter::pixelsToMeters (WALL_THICKNESS / 2), Converter::pixelsToMeters (WINDOW_HEIGHT / 2));
        this->_leftFixture.shape = & this->_leftShape;
        this->_leftBody->CreateFixture (& this->_leftFixture);

        this->_rightDef.position.Set (Converter::pixelsToMeters (WINDOW_WIDTH +  WALL_THICKNESS / 2), Converter::pixelsToMeters (WINDOW_HEIGHT / 2));
        this->_rightBody = this->_world->CreateBody (& this->_rightDef);
        this->_rightShape.SetAsBox (Converter::pixelsToMeters (WALL_THICKNESS / 2), Converter::pixelsToMeters (WINDOW_HEIGHT / 2));
        this->_rightFixture.shape = & this->_rightShape;
        this->_rightBody->CreateFixture (& this->_rightFixture);

        this->_topDef.position.Set (Converter::pixelsToMeters (WINDOW_WIDTH / 2), Converter::pixelsToMeters (- WALL_THICKNESS / 2));
        this->_topBody = this->_world->CreateBody (& this->_topDef);
        this->_topShape.SetAsBox (Converter::pixelsToMeters (WINDOW_WIDTH / 2), Converter::pixelsToMeters (WALL_THICKNESS / 2));
        this->_topFixture.shape = & this->_topShape;
        this->_topBody->CreateFixture (& this->_topFixture);

        this->_lPostDef.position.Set (Converter::pixelsToMeters (GOAL_POST_WIDTH / 2), Converter::pixelsToMeters (WINDOW_HEIGHT - GROUND_HEIGHT - UPHILL_HEIGHT - GOAL_POST_HEIGHT));
        this->_leftPost = this->_world->CreateBody (& this->_lPostDef);
        this->_lPostShape.SetAsBox (Converter::pixelsToMeters (GOAL_POST_WIDTH / 2), Converter::pixelsToMeters (WALL_THICKNESS / 2));
        this->_lPostFixture.shape = & this->_lPostShape;
        this->_leftPost->CreateFixture (& this->_lPostFixture);

        this->_rPostDef.position.Set (Converter::pixelsToMeters (WINDOW_WIDTH - GOAL_POST_WIDTH / 2), Converter::pixelsToMeters (WINDOW_HEIGHT - GROUND_HEIGHT - UPHILL_HEIGHT - GOAL_POST_HEIGHT));
        this->_rightPost = this->_world->CreateBody (& this->_rPostDef);
        this->_rPostShape.SetAsBox (Converter::pixelsToMeters (GOAL_POST_WIDTH / 2), Converter::pixelsToMeters (WALL_THICKNESS / 2));
        this->_rPostFixture.shape = & this->_rPostShape;
        this->_rightPost->CreateFixture (& this->_rPostFixture);


    }
}