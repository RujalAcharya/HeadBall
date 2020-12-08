  #include "Definition.hpp"
#include "HalfTime.hpp"
#include "GameState.hpp"
#include "MenuScreen.hpp"

namespace HeadBall {
    HalfTime::HalfTime (GameDataRef data, ScoreTimeRef scoretime) : _data{data}, _scoreTime{scoretime} { }

    void HalfTime::init () {

        if (!this->_data->assets.isFontPresent("Text Font")){
            this->_data->assets.loadFont("Text Font", TEXT_FONT_FILEPATH);
        }
        
        this->_text.setString("Half Time");
        this->_text.setFont (this->_data->assets.getFont("Text Font"));

        this->_text.setCharacterSize(30);
        this->_text.setOrigin(_text.getGlobalBounds( ).width / 2, _text.getGlobalBounds( ).height / 2);
        this->_text.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    }

    void HalfTime::handleInput ( ) {
        sf::Event event;

        while (this->_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->_data->window.close( );
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    this->_scoreTime->time.resume ( );
                    this->_data->machine.addState (StateRef(new GameState (this->_data, this->_scoreTime, true)) );
                }
            }
        }
    }

    void HalfTime::update ( ) { }

    void HalfTime::draw ( ) {
        this->_data->window.clear(sf::Color::Green );
        this->_data->window.draw(this->_text );
        this->_data->window.display( );
    }
}