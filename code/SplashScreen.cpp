#include <sstream>

#include "SplashScreen.hpp"
#include "Definition.hpp"
#include "MenuScreen.hpp"

namespace HeadBall {
    SplashScreen::SplashScreen (GameDataRef data) : _data{data} { }

    void SplashScreen::init () {
    
        if (!this->_data->assets.isFontPresent("Text Font")){
            this->_data->assets.loadFont("Text Font", TEXT_FONT_FILEPATH);
        }
 
        this->_data->assets.loadTexture("Splash Screen Background", PLAIN_BG_FILEPATH);

        this->_data->assets.loadTexture("Splash Anim 1", SPLASH_SCREEN_ANIM_1);
        this->_data->assets.loadTexture("Splash Anim 2", SPLASH_SCREEN_ANIM_2);
        this->_data->assets.loadTexture("Splash Anim 3", SPLASH_SCREEN_ANIM_3);
        this->_data->assets.loadTexture("Splash Anim 4", SPLASH_SCREEN_ANIM_4);
        this->_data->assets.loadTexture("Splash Anim 5", SPLASH_SCREEN_ANIM_5);
        this->_data->assets.loadTexture("Splash Anim 6", SPLASH_SCREEN_ANIM_6);
        this->_data->assets.loadTexture("Splash Anim 7", SPLASH_SCREEN_ANIM_7);
        this->_data->assets.loadTexture("Splash Anim 8", SPLASH_SCREEN_ANIM_8);
        this->_data->assets.loadTexture("Splash Anim 9", SPLASH_SCREEN_ANIM_9);
        this->_data->assets.loadTexture("Splash Anim 10", SPLASH_SCREEN_ANIM_10);
        this->_data->assets.loadTexture("Splash Anim 11", SPLASH_SCREEN_ANIM_11);


        this->_backgroundSprite.setTexture(this->_data->assets.getTexture("Splash Screen Background"));
        this->_backgroundSprite.setOrigin(this->_backgroundSprite.getGlobalBounds( ).width / 2, this->_backgroundSprite.getGlobalBounds( ).height / 2);

        this->_backgroundSprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

        this->_animationCounter = 0;
        this->_spriteCounter = 1;
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
        this->_animationCounter ++;

        if (this->_animationCounter == this->_spriteCounter * FRAMES_PER_ANIMATION * 2) {
            std::stringstream ss;
            ss << "Splash Anim " << this->_spriteCounter;

            this->_logoSprite.setTexture (this->_data->assets.getTexture (ss.str ( )));
            this->_logoSprite.setOrigin(this->_logoSprite.getGlobalBounds( ).width / 2, this->_logoSprite.getGlobalBounds( ).height / 2);
            this->_logoSprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

            this->_spriteCounter ++;
        }

        if (this->_spriteCounter == 12) {
            this->_data->machine.addState (StateRef (new MenuScreen (_data)));
        }
    }

    void SplashScreen::draw ( ) {
        this->_data->window.clear( );
        this->_data->window.draw(this->_backgroundSprite);
        this->_data->window.draw(this->_logoSprite);
        this->_data->window.display( );
    }
}