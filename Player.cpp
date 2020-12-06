#include "Player.hpp"
#include "Definition.hpp"
#include "Converter.hpp"

namespace HeadBall { 
    Player::Player(GameDataRef data,WorldRef world) : _data{data}, _world{world} { }

    void Player::init(std::string texture, std::string texturePath, sf::Vector2f position){  
        if (!this->_data->assets.isTexturePresent(texture)) {
            this->_data->assets.loadTexture(texture, texturePath);
        }

        this->_sprite.setTexture (this->_data->assets.getTexture(texture));
        
        this->_sprite.setOrigin (this->_sprite.getGlobalBounds( ).width / 2, this->_sprite.getGlobalBounds( ).height / 2);
        this->_sprite.setPosition (position);

        this->_bodyDef.position.Set (Converter::pixelsToMeters (this->_sprite.getPosition( ).x), Converter::pixelsToMeters (this->_sprite.getPosition( ).y));
        this->_bodyDef.type = b2_dynamicBody;
        this->_body = this->_world->CreateBody (& this->_bodyDef);

        this->_rectShape.SetAsBox (Converter::pixelsToMeters (this->_sprite.getGlobalBounds( ).width / 2), Converter::pixelsToMeters (this->_sprite.getGlobalBounds( ).height / 2));
        this->_fixture.shape = & this->_rectShape;
        this->_fixture.density = PLAYER_DENSITY;
        this->_fixture.friction= PLAYER_FRICTION;

        this->_body->CreateFixture (& this->_fixture);
    }

    void Player::moveLeft ( ) {
        this->_body->SetLinearVelocity (b2Vec2(- MOVEMENT_VELOCITY , 0.f));
    }
     
    void Player::moveRight(){
        this->_body->SetLinearVelocity(b2Vec2(MOVEMENT_VELOCITY,0.f));
    }
    
    void Player::jump ( ) {
        this->_body->SetLinearVelocity (b2Vec2 (0.0f, -MOVEMENT_VELOCITY));
    }


    sf::Sprite Player::sprite(){
        return this->_sprite;
    }

    void Player::processPosition(){
        this->_sprite.setPosition (Converter::metersToPixels (this->_body->GetPosition( ).x), Converter::metersToPixels (this->_body->GetPosition( ).y));
    }
    
    
}
