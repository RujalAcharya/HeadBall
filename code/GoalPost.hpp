#pragma once
#include "Game.hpp"

namespace HeadBall{
    /*!
     * @brief The Goalpost to be displayed in GameState
     * 
     */
    class GoalPost {
        public:
            /*!
             * @brief Construct a new Goal Post object
             * 
             * @param data The Shared Pointer of game data
             */
            GoalPost (GameDataRef data);

            /*!
             * @brief Initiate the GoalPost object
             * 
             * @param position The position where the GoalPost is placed
             * @param isLeft To specify whether the GoalPost is left post or right post, for keeping appropriate sprite for appropriate post
             */
            void init (sf::Vector2f position, bool isLeft = true);

            /*!
             * @brief Return the sprite to be displayed in the GameState
             * 
             * @return sf::Sprite The sprite to be displayed
             */
            sf::Sprite sprite ( );

        private:
            GameDataRef _data;      //!< The Shared Pointer of game data

            sf::Sprite _sprite;     //!< The sprite of the goal post
    };   
}