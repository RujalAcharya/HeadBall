#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

namespace HeadBall {
    /*!
     * @brief Class for game over or full-time state
     * 
     */
    class GameOver : public State {
        public:
            /*!
             * @brief Construct a new Game Over object
             * 
             * @param data 
             * @param scoreTime 
             */
            GameOver (GameDataRef data, ScoreTimeRef scoreTime);

            /*!
             * @brief Initialize state related data
             * 
             */
            void init ( );

            /*!
             * @brief Handle user input
             * 
             */
            void handleInput ( );

            /*!
             * @brief Update state data
             * 
             */
            void update ( );

            /*!
             * @brief Draw state objects
             * 
             */
            void draw ( );

        private:
            GameDataRef _data;              //!< The shared pointer for GameData
            ScoreTimeRef _scoreTime;        //!< The shared pointer for ScoreTimeData

            sf::Sound _crowdCheerOnGoal;    //!< Sound effect for crowd cheering
            sf::Sound _btnClickSfx;         //!< Sound effect for button click
            
            sf::Sprite _background;         //!< Background sprite to draw on the screen
            sf::Sprite _replayBtn;          //!< Button to replay the game
            sf::Sprite _exitBtn;            //!< Button to exit the game

            sf::Text _winnerText;           //!< Text to display depending on who won or if it is a draw
            sf::Text _score;                //!< Final score of the game
    };
}