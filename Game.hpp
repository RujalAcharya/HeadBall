#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

#include "StateMachine.hpp"
#include "InputManager.hpp"

namespace HeadBall {
    struct GameData {
        sf::RenderWindow window;
        StateMachine machine;
        InputManager input;
    };

    typedef std::shared_ptr <GameData> GameDataRef;

    class Game {
        public:
            Game (int width, int height, std::string title);

        private:
            const float dt = 1.0f / 60.0f;
            sf::Clock _clock;

            GameDataRef _data = std::make_shared <GameData> ( );

            void run ( );
    };
}