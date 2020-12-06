#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
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
    typedef std::shared_ptr<b2World> WorldRef;


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