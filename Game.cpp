#include "Game.hpp"
#include "SplashScreen.hpp"

namespace HeadBall {
    Game::Game (int width, int height, std::string title) {
        this->_data->window.create (sf::VideoMode (width, height), title, sf::Style::Titlebar | sf::Style::Close);
        this->_data->machine.addState (StateRef (new SplashScreen (this->_data)));

        this->run ( );
    }

    void Game::run ( ) {
        float newTime, frameTime, interpolation;
        float currentTime = this->_clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while (this->_data->window.isOpen()) {
            this->_data->machine.processStateChanges( );

            newTime = this->_clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;

            if (frameTime > 0.25f) {
                frameTime = 0.25f;
            }

            currentTime = newTime;

            accumulator += frameTime;
            
            if (accumulator >= dt) {
                this->_data->machine.getActiveState()->handleInput();
                this->_data->machine.getActiveState()->update(dt);

                accumulator -= dt;
            }

            interpolation = accumulator / dt;
            this->_data->machine.getActiveState()->draw (interpolation);
        }

    }
}