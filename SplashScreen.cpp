#include "SplashScreen.hpp"
#include "Definition.hpp"
#include "MenuScreen.hpp"

namespace HeadBall {
    SplashScreen::SplashScreen (GameDataRef data) : _data{data} { }

    void SplashScreen::init () {
    
        if (!this->_data->assets.isFontPresent("Text Font")){
            this->_data->assets.loadFont("Text Font", TEXT_FONT_FILEPATH);
        }

        this->_data->assets.loadTexture("Nepal flag", NEPAL_FLAG_FILEPATH);
        this->_flagSprite.setTexture(this->_data->assets.getTexture("Nepal flag"));
        this->_flagSprite.setOrigin(this->_flagSprite.getGlobalBounds( ).width / 2, this->_flagSprite.getGlobalBounds( ).height / 2);
        // this->_flagSprite.scale(sf::Vector2f(5, 5));
        this->_flagSprite.setPosition (WINDOW_WIDTH / 2 + 15, WINDOW_HEIGHT / 2 - 325);
        
 
        this->_data->assets.loadTexture("Splash Screen Background", SPLASH_SCREEN_BACKGROUND_FILEPATH);
        this->_backgroundSprite.setTexture(this->_data->assets.getTexture("Splash Screen Background"));
        this->_backgroundSprite.setOrigin(this->_backgroundSprite.getGlobalBounds( ).width / 2, this->_backgroundSprite.getGlobalBounds( ).height / 2);

        this->_backgroundSprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

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

    void SplashScreen::update ( ) {
        float elapsedTime = _clock.getElapsedTime( ).asSeconds ( );

        if (elapsedTime >= SPLASH_SCREEN_TIME) {
            this->_data->machine.addState (StateRef (new MenuScreen (_data)));
        }
    }

    void SplashScreen::draw ( ) {
        this->_data->window.clear(sf::Color::White);
        this->_data->window.draw(_backgroundSprite);
        this->_data->window.draw(_flagSprite);
        this->_data->window.display( );
    }
}