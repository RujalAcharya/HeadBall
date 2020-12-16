#pragma once

#include <SFML/Graphics.hpp>

 namespace HeadBall {
    /*!
     * @brief Handle the input given by the user
     * 
     * The class handles the input given by the user, 
     * whether it is the clicking of a button(sprite) or movement
     * and action of the player in the main game.
     * 
     */
    class InputManager {
        public:
            /*!
             * @brief Construct a new Input Manager object
             * 
             */
            InputManager ( ) { }

            /*!
             * @brief Destroy the Input Manager object
             * 
             */
            ~InputManager ( ) { }

            /*!
             * @brief Check whether a sprite is clicked or not
             * 
             * @param sprite Sprite which is to be checked
             * @param button The mouse button whose click is checked: left, right or middle
             * @param window The SFML render window object where the click is checked
             * @return true if the sprite is clicked
             * @return false if the sprite is not clicked
             */
            bool isSpriteClicked (sf::Sprite sprite, sf::Mouse::Button button, sf::RenderWindow& window);

            /*!
             * @brief Get the Mouse Position object
             * 
             * @param window The SFML render window object
             * @return sf::Vector2i The position of the mouse in with respect to the render window object
             */
            sf::Vector2i getMousePosition (sf::RenderWindow& window);

            /*!
             * @brief Check whether the player is moving or not
             * 
             * @param direction The direction : "left" or "right"
             * @param player The player : "p1" or "p2"
             * @return true if the player is moving in certain direction
             * @return false if the player is not moving in certain direction
             */
            bool isMoving (std::string direction, std::string player = "p1");
            
            /*!
             * @brief Check whether the player is performing a certain action or not
             * 
             * @param action The action : "kick" or "jump"
             * @param player The player : "p1" or "p2"
             * @return true if the player is performing the action
             * @return false if the player is not performing the action
             */
            bool isDoing (std::string action, std::string player = "p1");
    };
}