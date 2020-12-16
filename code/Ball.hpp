#pragma once

#include "Game.hpp"

namespace HeadBall {
    /*!
     * @brief Class for shape and movement of ball
     * 
     */
    class Ball {
        public:
            /*!
             * @brief Construct a new Ball object
             * 
             * @param data  The Shared Pointer for game data
             * @param world  The Shared pointer for Box2D world
             */
            Ball (GameDataRef data, WorldRef world);

            /*!
             * @brief Initiate the Ball object
             * 
             */
            void init ( );

            /*!
             * @brief Return the shape of the Ball object
             * 
             * @return sf::CircleShape the shape of Ball object
             */
            sf::CircleShape shape ( );

            /*!
             * @brief Process the position of the Ball object
             * 
             * This function processes the position of the CircleShape as per the position of body in Box2D
             * 
             */
            void processPosition ( );

            /*!
             * @brief Place the ball at the starting position
             * 
             */
            void rePosition ( );

            /*!
             * @brief Return the Box2D body of the ball
             * 
             * @return b2Body* The Box2D body of the ball
             */
            b2Body* body( );

        private:
            GameDataRef _data;              //!<  The Shared Pointer of the game data
            WorldRef _world;                //!<  The Shared Pointer of Box2D World

            sf::CircleShape _shape;         //!<  The SFML shape of the ball

            b2BodyDef _bodyDef;             //!<  The Definition of Box2D body
            b2Body* _body;                  //!<  The Box2D body of ball
            b2CircleShape _circleShape;     //!<  The circle shape for fixture definition
            b2FixtureDef _fixture;          //!<  The fixture of ball for defining its properties 
    };
}