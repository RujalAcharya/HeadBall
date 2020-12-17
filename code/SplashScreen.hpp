#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

namespace HeadBall {
    /*!
     * @brief Class for the Splash Screen 
     * 
     */
    class SplashScreen : public State {
        public:
            /*!
             * @brief Construct a new Splash Screen object
             * 
             * @param data Shared pointer of game data 
             */
            SplashScreen (GameDataRef data);

            /*!
             * @brief Initialize SplashScreen object
             *
             */
            void init ( );

            /*!
             * @brief Handle the user inputs
             * 
             */
            void handleInput ( );

            /*!
             * @brief Update the Animation
             * 
             */
            void update ( );

            /*!
             * @brief Draw the Sprites
             * 
             */
            void draw ( );

        private:
            GameDataRef _data;              //!< Shared Pointer for all game data

            sf::Sprite _backgroundSprite;   //!< Initial background sprite
            sf::Sprite _logoSprite;         //!< Initial logo animation sprite

            int _animationCounter;          //!< Counter for animation cycles
            int _spriteCounter;             //!< Counter for sprites
    };
}