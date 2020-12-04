#include "Definition.hpp"
#include "MenuScreen.hpp"
#include "GameState.hpp"

namespace HeadBall {
    MenuScreen::MenuScreen (GameDataRef data) : _data (data) { }

    void MenuScreen::init () {
        this->_font.loadFromFile (TEXT_FONT);

        this->_text.setString ("Menu Screen");
        this->_text.setFont (_font);
        this->_text.setCharacterSize (30);
        this->_text.setOrigin(_text.getGlobalBounds( ).width / 2, _text.getGlobalBounds( ).height / 2);
        this->_text.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    }

    void MenuScreen::handleInput ( ) {
        sf::Event event;

        while (this->_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->_data->window.close( );
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    this->_data->machine.addState (StateRef (new GameState (this->_data)));
                }

                if (event.key.code == sf::Keyboard::Q) {
                    this->_data->window.close ( );
                }
            }
        }
    }

    void MenuScreen::update (float dt) {
        
    }

    void MenuScreen::draw (float dt) {
        this->_data->window.clear(sf::Color::Blue );
        this->_data->window.draw(this->_text );
        this->_data->window.display( );
    }
}