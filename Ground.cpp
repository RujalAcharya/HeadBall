#include "Ground.hpp"
#include "Definition.hpp"
#include "Converter.hpp"

namespace HeadBall {
    Ground::Ground (GameDataRef data, WorldRef world) : _data (data), _world (world) { }

    void Ground::init ( ) {
        this->_shape.setSize (sf::Vector2f (WINDOW_WIDTH, GROUND_HEIGHT));
        this->_shape.setPosition (this->_shape.getSize( ).x / 2,  WINDOW_HEIGHT - this->_shape.getSize( ).y / 2);
        this->_shape.setOrigin (this->_shape.getSize( ).x / 2, this->_shape.getSize( ).y / 2);
        this->_shape.setFillColor (sf::Color::Blue);

        this->_bodyDef.position.Set (Converter::pixelsToMeters (this->_shape.getPosition( ).x), Converter::pixelsToMeters (this->_shape.getPosition( ).y));
        this->_body = this->_world->CreateBody (& this->_bodyDef);

        this->_polyShape.SetAsBox (Converter::pixelsToMeters (this->_shape.getSize( ).x / 2), Converter::pixelsToMeters (this->_shape.getSize( ).y / 2));
        this->_fixture.shape = & this->_polyShape;
        this->_fixture.friction = GROUND_FRICTION;

        this->_body->CreateFixture (& this->_fixture);
    }

    sf::RectangleShape Ground::shape ( ) {
        return this->_shape;
    }

}