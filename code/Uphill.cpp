#include "Uphill.hpp"
#include "Definition.hpp"
#include "Converter.hpp"

namespace HeadBall {
    UpHill::UpHill (GameDataRef data, WorldRef world ) : _data{data}, _world{world} { }

    void UpHill::init (sf::Vector2i position ) {
        this->_shape.setSize (sf::Vector2f (UPHILL_WIDTH, UPHILL_HEIGHT));
        this->_shape.setPosition (position.x, position.y);
        this->_shape.setOrigin (this->_shape.getSize( ).x / 2, this->_shape.getSize( ).y / 2);
        this->_shape.setFillColor (sf::Color(0,207,0));
        // this->_shape.setFillColor (sf::Color::Green);

        this->_bodyDef.position.Set (Converter::pixelsToMeters (this->_shape.getPosition( ).x), Converter::pixelsToMeters (this->_shape.getPosition( ).y));
        this->_body = this->_world->CreateBody (& this->_bodyDef);

        this->_polyShape.SetAsBox (Converter::pixelsToMeters (this->_shape.getSize( ).x / 2), Converter::pixelsToMeters (this->_shape.getSize( ).y / 2));
        this->_fixture.shape = & this->_polyShape;
        this->_fixture.friction = GROUND_FRICTION;

        this->_body->CreateFixture (& this->_fixture);
    }

    sf::RectangleShape UpHill::shape ( ) {
        return this->_shape;
    }

}