#include "Definition.hpp"
#include "PausedState.hpp"
#include "MenuScreen.hpp"

namespace HeadBall {
    PausedState::PausedState (GameDataRef data) : _data (data) { }

    void PausedState::init () {
        this->_font.loadFromFile (TEXT_FONT);

        this->_text.setString ("Paused");
        this->_text.setFont (_font);
        this->_text.setCharacterSize (30);
        this->_text.setOrigin(_text.getGlobalBounds( ).width / 2, _text.getGlobalBounds( ).height / 2);
        this->_text.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    }

    void PausedState::handleInput ( ) {
        sf::Event event;

        while (this->_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->_data->window.close( );
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    this->_data->machine.removeState ( );
                }

                if (event.key.code == sf::Keyboard::M) {
                    this->_data->machine.addState (StateRef (new MenuScreen (_data)) );
                }

                if (event.key.code == sf::Keyboard::Q) {
                    this->_data->window.close ( );
                }
            }
        }
    }

    void PausedState::update (float dt) {
        
    }

    void PausedState::draw (float dt) {
        this->_data->window.clear(sf::Color::Green );
        this->_data->window.draw(this->_text );
        this->_data->window.display( );
    }
}