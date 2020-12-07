#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <memory>

#include "State.hpp"
#include "Game.hpp"
#include "TimeManager.hpp"
#include "Ground.hpp"
#include "Ball.hpp"
#include "Uphill.hpp"
#include "Wall.hpp"
#include "Definition.hpp"
#include "GoalPost.hpp"
#include "Player.hpp"

namespace HeadBall {
    class GameState : public State {
        public:
            GameState (GameDataRef data, ScoreTimeRef scoretime, bool is2ndHalf = false);
            void init ( );
            void handleInput ( );
            void update ( );
            void draw ( );
            void pause ( );
            void resume ( );

        private:
            GameDataRef _data;

            sf::Text _text;
            ScoreTimeRef _scoretime;

            WorldRef _world = std::make_shared <b2World> (b2Vec2(WORLD_GRAVITY_X, WORLD_GRAVITY_Y));

            Ground _ground;
            UpHill _leftUpHill, _rightUpHill;
            Wall _wall;
            GoalPost _leftPost, _rightPost;

            Player _p1, _p2;
            
            Ball _ball;

            bool _isPaused;
            bool _isSecondHalf;

            sf::Sprite _pauseBtn;
    };
}