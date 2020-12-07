#pragma once
#include "Game.hpp"

namespace HeadBall{
    class Player
    {
    public:
        Player(GameDataRef data,WorldRef world);
        void init(std::string texture, std::string texturePath, sf::Vector2f position);
        sf::Sprite sprite();
        void processPosition();
        void moveLeft ( );
        void moveRight ( );
        void jump ( );
        void rePosition (sf::Vector2f position);
    
    private:
        GameDataRef _data;
        WorldRef _world;  

        sf::Sprite _sprite;

        b2BodyDef _bodyDef;
        b2Body* _body;
        b2PolygonShape _rectShape;
        b2FixtureDef _fixture;
        
    };    
}