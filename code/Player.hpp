#pragma once
#include "Game.hpp"

namespace HeadBall{
    /*!
     * @brief Class for shape and movement of player
     * 
     */
    class Player {
    public:
        /*!
         * @brief Construct a new Player object
         * 
         * @param data  Shared pointer of game data
         * @param world  Shared pointer of Box2D world
         */
        Player(GameDataRef data,WorldRef world);

        /*!
         * @brief Initiate the Player object
         * 
         * @param texture  Texture of the player as defined in the `map`
         * @param texturePath Path to the texture
         * @param position  Position of the player
         */
        void init(std::string texture, std::string texturePath, sf::Vector2f position);

        /*!
         * @brief Return the sprite of the Player object
         * 
         * @return sf::Sprite Sprite of the player object
         */
        sf::Sprite sprite();

        /*!
         * @brief Process the position of Player object
         * 
         * This function processes the position of the sprite as per the position of body in Box2D
         * 
         */
        void processPosition();

        /*!
         * @brief Move the player left
         * 
         */
        void moveLeft ( );

        /*!
         * @brief Move the player right
         * 
         */
        void moveRight ( );

        /*!
         * @brief Make the player jump
         * 
         */
        void jump ( );

        /*!
         * @brief Set the Texture of the sprite
         * 
         * @param texture  Texture as defined in the `map`
         */
        void setTexture(std::string texture );

    private:
        GameDataRef _data;              //!<   The Shared Pointer of the game data
        WorldRef _world;                //!<   The Shared Pointer of Box2D World

        sf::Sprite _sprite;             //!<   The SFML sprite of the player

        b2BodyDef _bodyDef;             //!<   The definition of Box2D body
        b2Body* _body;                  //!<   The Box2D body of player
        b2PolygonShape _rectShape;      //!<   The polygon shape for fixture definition
        b2FixtureDef _fixture;          //!<   The fixture of player for defining its properties
        
    };    
}