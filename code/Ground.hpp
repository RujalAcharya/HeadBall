#pragma once

#include "Game.hpp"

namespace HeadBall {
    /*!
     * @brief Class for defining the ground in the game world
     * 
     */
    class Ground {
        public:
            /*!
             * @brief Construct a new Ground object
             * 
             * @param data The Shared Pointer for game data
             * @param world The Shared pointer for Box2D world
             */
            Ground (GameDataRef data, WorldRef world);

            /*!
             * @brief Initiate the Ground Object
             * 
             */
            void init( );

            /*!
             * @brief Return the shape of the Ground object
             * 
             * @return sf::RectangleShape Shape of Ground Object
             */
            sf::RectangleShape shape (  );

        private:
            GameDataRef _data;              //!<  The Shared Pointer of the game data
            WorldRef _world;                //!<  The Shared Pointer of Box2D World

            sf::RectangleShape _shape;      //!<  The SFML shape of the ground

            b2BodyDef _bodyDef;             //!<  The Definition of Box2D body
            b2Body* _body;                  //!<  The Box2D body of ground
            b2PolygonShape _polyShape;      //!<  The polygon shape for fixture definition
            b2FixtureDef _fixture;          //!<  The fixture of ground for defining its properties
    };
}