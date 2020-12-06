#pragma once

#include <SFML/Graphics.hpp>

 namespace HeadBall {
    class InputManager {
        public:
            InputManager ( ) { }
            ~InputManager ( ) { }

            bool isSpriteClicked (sf::Sprite sprite, sf::Mouse::Button button, sf::RenderWindow& window);
            sf::Vector2i getMousePosition (sf::RenderWindow& window);

            bool isMoving (std::string position, std::string player = "p1");
            bool isDoing (std::string action, std::string player = "p1");
    };
}