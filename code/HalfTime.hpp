#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

namespace HeadBall {
    /*!
     * @brief Class for Half Time State 
     * 
     */
    class HalfTime : public State {
        public:
            /*!
             * @brief Construct a new Half Time object
             * 
             * @param data  Shared pointer of game data
             * @param scoretime   Shared pointer of score and time
             */
            HalfTime (GameDataRef data, ScoreTimeRef scoretime);

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
            GameDataRef _data;          //!< Shared pointer of all game data
            ScoreTimeRef _scoreTime;    //!< Shared pointer of the score and time

            sf::Text _score;            //!< Scores of the players displayed as text

            sf::Music _theme;           //!< The theme music
            sf::Sound _btnClickSfx;     //!< Sound effect for button click

            sf::Sprite _background;     //!< Background sprite to draw on screen
            sf::Sprite _resumeBtn;      //!< Sprite for resume button
    };
}