#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <memory>

#include "State.hpp"
#include "Game.hpp"
#include "TimeManager.hpp"
#include "Ground.hpp"
#include "Ball.hpp"
#include "Definition.hpp"

namespace HeadBall {
    class GameState : public State {
        public:
            GameState (GameDataRef data);
            void init ( );
            void handleInput ( );
            void update (float dt);
            void draw (float dt);
            void pause ( );
            void resume ( );

        private:
            GameDataRef _data;

            TimeManager _timer;

            sf::Font _font;
            sf::Text _text;

            WorldRef _world = std::make_shared <b2World> (b2Vec2(WORLD_GRAVITY_X, WORLD_GRAVITY_Y));

            Ground _ground;
            Ball _ball;

            bool _isPaused;
            bool _isSecondHalf;
    };
}