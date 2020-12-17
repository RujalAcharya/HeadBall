#pragma once

#include "Game.hpp"

namespace HeadBall {
    /*!
     * @brief The Uphill part of the game field, below the goal post and above the ground
     */
    class UpHill {
        public:
            /*!
             * @brief Construct a new Up Hill object
             * 
             * @param data The Shared Pointer of game data
             * @param world The Shared Pointer of Box2D world
             */
            UpHill (GameDataRef data, WorldRef world);

            /*!
             * @brief Initiate the Up Hill ubject
             * 
             * @param position The position where object is placed
             */
            void init (sf::Vector2i position );

            /*!
             * @brief Return the shape of Up Hill object
             * 
             * @return sf::RectangleShape The shape of Up Hill obkect
             */
            sf::RectangleShape shape (  );

        private:
            GameDataRef _data;          //!<  The Shared Pointer of the game data
            WorldRef _world;            //!<  The Shared Pointer of Box2D World

            sf::RectangleShape _shape;  //!<  The SFML shape of the uphill


            b2BodyDef _bodyDef;         //!<  The Definition of Box2D body
            b2Body* _body;              //!<  The Box2D body of uphill
            b2PolygonShape _polyShape;  //!<  The polygon shape for fixture definition
            b2FixtureDef _fixture;      //!<  The fixture of uphill for defining its properties 
    };
}