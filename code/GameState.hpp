#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <memory>

#include "State.hpp"
#include "Game.hpp"
#include "TimeManager.hpp"
#include "Ground.hpp"
#include "Ball.hpp"
#include "Uphill.hpp"
#include "Wall.hpp"
#include "Definition.hpp"
#include "GoalPost.hpp"
#include "Player.hpp"

namespace HeadBall {
    /*!
     * @brief Derived class of State class with visibility mode
     *        public that includes main gameplay 
     * 
     */
    class GameState : public State {
        public:
            /*!
             * @brief Construct a new Game State object
             * 
             * @param data The shared pointer of GameData
             * @param scoretime The shared pointer of ScoreTimeData
             * @param is2ndHalf The bool variable with default value false
             */
            GameState (GameDataRef data, ScoreTimeRef scoretime, bool is2ndHalf = false);

            /*!
             * @brief Initialize a new GameSate Object
             * 
             */
            void init ( );

            /*!
             * @brief Handles all the inputs of Game State
             * 
             */
            void handleInput ( );

            /*!
             * @brief Updates the rendering window according to the provided input
             * 
             */
            void update ( );

            /*!
             * @brief Draws all the SFML object in the rendering window
             * 
             */
            void draw ( );

            /*!
             * @brief Pauses the game 
             * 
             */
            void pause ( );

            /*!
             * @brief Resumes the game
             * 
             */
            void resume ( );

            /*!
             * @brief Animates the movement of the players 
             * 
             * @param player String object whose value is either "p1" or "p2"
             */
            void animate (std::string player);

            /*!
             * @brief Kicks the ball when called by the player
             * 
             * @param player String object whose value is either "p1" or "p2"
             */
            void kick (std::string player);


        private:
            GameDataRef _data;                                                                          //!<    The shared pointer of GameData

            sf::Text _timeText, _p1Score, _p2Score;                                                     //!<    The SFML text of Score and Time
            ScoreTimeRef _scoreTime;                                                                    //!<    The shared pointer of ScoreTimeData

            WorldRef _world = std::make_shared <b2World> (b2Vec2(WORLD_GRAVITY_X, WORLD_GRAVITY_Y));    //!<    The shared pointer of Box2d world

            Ground _ground;                                                                             //!<    The Ground object 
            UpHill _leftUpHill, _rightUpHill;                                                           //!<    The Uphill objects
            Wall _wall;                                                                                 //!<    The Wall objects
            GoalPost _leftPost, _rightPost;                                                             //!<    The GoalPost objects

            Player _p1, _p2;                                                                            //!<    The Player objects
            
            Ball _ball;                                                                                 //!<    The Ball objects

            bool _isPaused;                                                                             //!<    The boolean variable to if the game is paused
            bool _isSecondHalf;                                                                         //!<    The boolean variable to check if the state is second half or not

            sf::Sprite _pauseBtn;                                                                       //!<    Sprite for pause button
   
            sf::Music _crowdCheerSfx;                                                                   //!<    Crowd cheer sound
            sf::Sound _btnClickSfx;                                                                     //!<    Sound effect for button click
            sf::Sound _longWhistleSfx;                                                                  //!<    Sound effect to play at the end of each half
            sf::Sound _shortWhistleSfx;                                                                 //!<    Sound effect to play at the start of every half and after every goal
             sf::Sound _playerKickSfx;                                                                  //!<    Sound effect to play when the ball is kicked
   
            int _p1MoveCounter;                                                                         //!<    The int variable to count Player1 movement
            int _p2MoveCounter;                                                                         //!<    The int variable to count Player2 movement
            
    };                                  
}