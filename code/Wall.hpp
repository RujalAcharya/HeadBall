#pragma once 

#include "Game.hpp"

namespace HeadBall {
    /*!
     * @brief Class for invisible wall around the field and above the goalpost
     * 
     */
    class Wall {
        public:
            /*!
             * @brief Construct a new Wall object
             * 
             * @param data   The Shared Pointer for game data
             * @param world   The Shared pointer for Box2D world
             */
            Wall (GameDataRef data, WorldRef world);

            /*!
             * @brief Initiate the wall object
             * 
             */
            void init ( );

    private:
        GameDataRef _data;                                                                      //!< The shared pointer for GameData                                                                  
        WorldRef _world;                                                                        //!< The shared pointer for b2World                                                                  
    
        b2BodyDef _leftDef, _rightDef, _topDef, _lPostDef, _rPostDef;                           //!< The definition of Box2d bodies                      
        b2Body* _leftBody;                                                                      //!< The Box2d body of left wall                                                                  
        b2Body* _rightBody;                                                                     //!< The Box2d body of right wall                                                        
        b2Body* _topBody;                                                                       //!< The Box2D body of top wall                        
        b2Body* _leftPost;                                                                      //!< The Box2D body of wall for left goal post
        b2Body* _rightPost;                                                                     //!< The Box2D body of wall for right goal post
        b2PolygonShape _leftShape, _rightShape, _topShape, _lPostShape, _rPostShape;            //!< The polygon shape for the fixure definition
        b2FixtureDef _leftFixture, _rightFixture, _topFixture, _lPostFixture, _rPostFixture;    //!< The fixture of wall for defining its properties
    };

}