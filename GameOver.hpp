#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

namespace HeadBall {
    class GameOver : public State {
        public:
            GameOver (GameDataRef data, ScoreTimeRef scoreTime);
            void init ( );
            void handleInput ( );
            void update ( );
            void draw ( );

        private:
            GameDataRef _data;
            ScoreTimeRef _scoreTime;

            sf::Music _theme;
            sf::Sound _crowdCheerOnGoal;
            sf::Sound _btnClickSfx;
            
            sf::Sprite _background;
            sf::Sprite _replayBtn;
            sf::Sprite _exitBtn;


            sf::Text _winnerText;
            sf::Text _score;
    };
}