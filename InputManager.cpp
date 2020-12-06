#include "Definition.hpp"
#include "InputManager.hpp"

namespace HeadBall {
    bool InputManager::isSpriteClicked (sf::Sprite sprite, sf::Mouse::Button button, sf::RenderWindow& window) {
        if (sf::Mouse::isButtonPressed(button)) {
            sf::IntRect spriteRect (sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height); 
            if (spriteRect.contains(sf::Mouse::getPosition(window))) {
                return true;
             }
        }
        return false;
    }

    sf::Vector2i InputManager::getMousePosition (sf::RenderWindow& window) {
        return sf::Mouse::getPosition(window);
    }

    bool InputManager::isMoving (std::string position, std::string player) {
        bool isp2 = false;
        if (player == "p2") {
            isp2 = false; 
        }

        if (!isp2 && position == "left") {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P1_LEFT)) {
                return true;
            }
        }

        if (!isp2 && position == "right") {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P1_RIGHT)) {
                return true;
            }
        }

        if (isp2 && position == "left") {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P2_LEFT)) {
                return true;
            }
        }

        if (isp2 && position == "right") {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P2_RIGHT)) {
                return true;
            }
        }

        return false;
    }

    bool InputManager::isDoing (std::string action, std::string player) {
        bool isp2 = false;
        if (player == "p2") {
            isp2 = false; 
        }

        if (!isp2 && action == "jump") {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P1_JUMP)) {
                return true;
            }
        }

        if (!isp2 && action == "kick") {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P1_KICK)) {
                return true;
            }
        }

        if (isp2 && action == "jump") {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P2_JUMP)) {
                return true;
            }
        }

        if (isp2 && action == "kick") {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P2_KICK)) {
                return true;
            }
        }

        return false;
    }
}