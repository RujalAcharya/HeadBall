#include "SplashScreen.hpp"
#include "Definition.hpp"
#include "MenuScreen.hpp"

namespace HeadBall {
    SplashScreen::SplashScreen (GameDataRef data) : _data (data) { }

    void SplashScreen::init () {
        this->_font.loadFromFile (TEXT_FONT);

        this->_text.setString ("Splash Screen");
        this->_text.setFont (_font);
        this->_text.setCharacterSize (30);
        this->_text.setOrigin(_text.getGlobalBounds( ).width / 2, _text.getGlobalBounds( ).height / 2);
        this->_text.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

        this->_clock.restart( );
    }

    void SplashScreen::handleInput ( ) {
        sf::Event event;

        while (this->_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->_data->window.close( );
            }
        }
    }

    void SplashScreen::update (float dt) {
        float elapsedTime = _clock.getElapsedTime( ).asSeconds ( );

        if (elapsedTime >= SPLASH_SCREEN_TIME) {
            this->_data->machine.addState (StateRef (new MenuScreen (_data)));
        }
    }

    void SplashScreen::draw (float dt) {
        this->_data->window.clear( );
        this->_data->window.draw(this->_text );
        this->_data->window.display( );
    }
}