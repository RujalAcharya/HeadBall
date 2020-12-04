#include "Definition.hpp"
#include "GameState.hpp"
#include "PausedState.hpp"
#include "HalfTime.hpp"
#include "GameOver.hpp"

namespace HeadBall {
    GameState::GameState (GameDataRef data) : _data (data) { }

    void GameState::init () {
        this->_font.loadFromFile (TEXT_FONT);

        this->_text.setString ("Timer");
        this->_text.setFont (_font);
        this->_text.setCharacterSize (30);
        this->_text.setOrigin(_text.getGlobalBounds( ).width / 2, _text.getGlobalBounds( ).height / 2);
        this->_text.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

        this->_isPaused = false;
        this->_isSecondHalf = false;
    }

    void GameState::handleInput ( ) {
        sf::Event event;

        while (this->_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->_data->window.close( );
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    this->_data->machine.addState (StateRef (new PausedState (this->_data)), false);
                }
            }
        }
    }

    void GameState::update (float dt) {
        if (!this->_isPaused) {
            this->_timer.processTime ( );

            this->_text.setString (this->_timer.displayTimer ( ));

            if (this->_timer.getTime ( ) >= GAME_TIME / 2 && !this->_isSecondHalf) {
                this->_isSecondHalf = true;
                this->_data->machine.addState (StateRef (new HalfTime (this->_data)), false);
            }

            if (this->_timer.getTime ( ) >= GAME_TIME) {
                this->_data->machine.addState (StateRef (new GameOver (this->_data)));
            }
        }
    }

    void GameState::draw (float dt) {
        if (!this->_isPaused) {
            this->_data->window.clear(sf::Color::Red);
            this->_data->window.draw(this->_text );
            this->_data->window.display( );
        }
    }

    void GameState::pause ( ) {
        this->_timer.pause ( );
        this->_isPaused = true;
    }

    void GameState::resume ( ) {
        this->_timer.resume ( );
        this->_isPaused = false;
    }
}