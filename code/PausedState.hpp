#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

namespace HeadBall {
    /*!
     * @brief Class for the screen to be displayed when game is paused
     * 
     */
    class PausedState : public State {
        public:
            /*!
             * @brief Construct a new Paused State object
             * 
             * @param data Shared pointer for game data
             */
            PausedState (GameDataRef data);

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
            GameDataRef _data;              //!< Shared pointer of game data

            sf::Sprite _background;         //!< Background sprite to draw on the screen
            sf::Sprite _resumeBtn;          //!< Button to resume game
            sf::Sprite _instructionsBtn;    //!< Button to go to instructions state
            sf::Sprite _exitBtn;            //!< Button to exit from the game

            sf::Sound _btnClickSfx;         //!< Sound effect for button click
            sf::Music _theme;               //!< Theme music
    };
}
