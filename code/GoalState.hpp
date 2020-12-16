#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

namespace HeadBall {
    /*!
     * @brief Derived class of State class with visibility mode public 
     *         that checks whether the player has scored goal 
     *          or not and updates the state
     */
    class GoalState : public State {
        public:
        /*!
         * @brief Construct a new Goal State object
         * 
         * @param data The shared pointer of GameData
         * @param scoretime The shared pointer of ScoreTimeData
         * @param isSecondHalf The boolean variable that checks whether the half is second or not
         */
            GoalState (GameDataRef data, ScoreTimeRef scoretime, bool isSecondHalf);
            /*!
             * @brief Initialze a new GoalState object
             * 
             */
            void init ( );
            /*!
             * @brief Handles all the input during goalstate
             * 
             */
            void handleInput ( );
            /*!
             * @brief Updates the rendering window as per the 
             *          provided inputs
             * 
             */
            void update ( );
            /*!
             * @brief Draws all the SFML objects of Goal state
             * 
             */
            void draw ( );

        private:
            GameDataRef _data;              //!< Shared pointer for game data
            ScoreTimeRef _scoreTime;        //!< Shared pointer for score and time

            sf::Sound _crowdCheerOnGoal;    //!< Croud cheering sound
            sf::Sprite _background;         //!< Background sprite to draw on the screen

            bool _isSecondHalf;             //!< Store whether it is first half or second
            int _animationCounter;          //!< Counter for animation of movements
    };
}