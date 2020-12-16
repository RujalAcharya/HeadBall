#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

namespace HeadBall {
    /*!
     * @brief Class for About page
     * 
     */
    class AboutState : public State {
        public:

            /*!
             * @brief Construct a new About State object
             * 
             * @param data Shared pointer for game data
             */
            AboutState (GameDataRef data);

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
        
            GameDataRef _data;          //!< The shared pointer for all the game data

            sf::Sprite _background;     //!< Background sprite to draw on the screen
            sf::Sprite _backBtn;        //!< Button to return back
            sf::Sprite _exitBtn;        //!< Button to exit from the game
            
            sf::Sound _btnClickSfx;     //!< Sound effect for button click
            
            sf::Text _text;             //!< Text to display `about` information
    };
}
