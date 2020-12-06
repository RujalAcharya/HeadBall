#include "Ball.hpp"
#include "Definition.hpp"
#include "Converter.hpp"

namespace HeadBall {
    Ball::Ball (GameDataRef data, WorldRef world) : _data (data), _world (world) { }

    void Ball::init ( ) {
        this->_shape.setRadius (BALL_DIAMETER / 2);
        this->_shape.setOrigin (this->_shape.getRadius ( ) / 2, this->_shape.getRadius ( ) / 2);
        this->_shape.setPosition (WINDOW_WIDTH / 2, 2 * WINDOW_HEIGHT / 3);

        this->_bodyDef.position.Set (Converter::pixelsToMeters (this->_shape.getPosition( ).x), Converter::pixelsToMeters (this->_shape.getPosition( ).y));
        this->_bodyDef.type = b2_dynamicBody;
        this->_body = this->_world->CreateBody (& this->_bodyDef);


        this->_circleShape.m_p.Set (0, 0);
        this->_circleShape.m_radius =  Converter::pixelsToMeters (BALL_DIAMETER / 2);
        this->_fixture.shape = & this->_circleShape;
        this->_fixture.density = BALL_DENSITY;
        this->_fixture.friction = BALL_FRICTION;
        this->_fixture.restitution = BALL_RESTITUTION;

        this->_body->CreateFixture (& this->_fixture);
    }

    sf::CircleShape Ball::shape ( ) {
        return this->_shape;
    }

    void Ball::processPosition ( ) {
        this->_shape.setPosition (Converter::metersToPixels (this->_body->GetPosition( ).x), Converter::metersToPixels (this->_body->GetPosition( ).y));
    }
}