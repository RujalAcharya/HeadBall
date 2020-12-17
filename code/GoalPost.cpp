#include "GoalPost.hpp"
#include "Definition.hpp"
#include "Converter.hpp"

namespace HeadBall{
    GoalPost::GoalPost(GameDataRef data): _data{data} { }

    void GoalPost::init(sf::Vector2f position,bool isLeft){
        std::string texture;
        if (isLeft) {
            texture = "Left Goal Post";
            if(!this->_data->assets.isTexturePresent (texture)) {
                this->_data->assets.loadTexture (texture, GOAL_POST1_FILEPATH);
            }
        } else {   
            texture = "Right Goal Post";
            if (!this->_data->assets.isTexturePresent (texture)){
                this->_data->assets.loadTexture(texture, GOAL_POST2_FILEPATH);
            }
        }
        this->_sprite.setTexture(this->_data->assets.getTexture(texture));
        
        this->_sprite.setOrigin (this->_sprite.getGlobalBounds( ).width / 2, this->_sprite.getGlobalBounds( ).height / 2);
        this->_sprite.setPosition(position);    
    }
    
    sf::Sprite GoalPost::sprite ( ) {
        return this->_sprite;
    }
}