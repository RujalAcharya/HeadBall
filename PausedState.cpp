#include "Definition.hpp"
#include "PausedState.hpp"
#include "MenuScreen.hpp"

namespace HeadBall {
    PausedState::PausedState (GameDataRef data) : _data{data} { }

    void PausedState::init () {
        
        if (!this->_data->assets.isFontPresent("Text Font")){
            this->_data->assets.loadFont("Text Font", TEXT_FONT_FILEPATH);
        }

        this->_text.setString ("Paused");
        this->_text.setFont (this->_data->assets.getFont("Text Font"));

        this->_text.setCharacterSize (30);
        this->_text.setOrigin (_text.getGlobalBounds( ).width / 2, _text.getGlobalBounds( ).height / 2);
        this->_text.setPosition (WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);


        if (!this->_data->assets.isTexturePresent("Paused background")){
            this->_data->assets.loadTexture("Paused background", PAUSED_BG_FILEPATH);
        }

        if (!this->_data->assets.isTexturePresent("Resume btn")){
            this->_data->assets.loadTexture("Resume btn", RESUME_BTN_FILEPATH);
        }

        if (!this->_data->assets.isTexturePresent("Instructions btn")){
            this->_data->assets.loadTexture("Instructions btn", INSTRUCTIONS_BTN_FILEPATH);
        }

        if (!this->_data->assets.isTexturePresent("About btn")){
            this->_data->assets.loadTexture("About btn", ABOUT_BTN_FILEPATH);
        }

        if (!this->_data->assets.isTexturePresent("Exit btn")){
            this->_data->assets.loadTexture("Exit btn", EXIT_BTN_FILEPATH);
        }

        this->_background.setTexture(this->_data->assets.getTexture("Paused background"));
        this->_background.setOrigin(_background.getLocalBounds( ).width / 2, _background.getLocalBounds( ).height / 2);
        this->_background.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

        this->_resumeBtn.setTexture(this->_data->assets.getTexture("Resume btn"));
        this->_resumeBtn.setOrigin(_resumeBtn.getLocalBounds( ).width / 2, _resumeBtn.getLocalBounds( ).height / 2);
        this->_resumeBtn.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

        this->_instructionsBtn.setTexture(this->_data->assets.getTexture("Instructions btn"));
        this->_instructionsBtn.setOrigin(_instructionsBtn.getLocalBounds( ).width / 2, _instructionsBtn.getLocalBounds( ).height / 2);
        this->_instructionsBtn.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 + 100);

        this->_aboutBtn.setTexture(this->_data->assets.getTexture("About btn"));
        this->_aboutBtn.setOrigin(_aboutBtn.getLocalBounds( ).width / 2, _aboutBtn.getLocalBounds( ).height / 2);
        this->_aboutBtn.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 + 200);

        this->_exitBtn.setTexture(this->_data->assets.getTexture("Exit btn"));
        this->_exitBtn.setOrigin(_exitBtn.getLocalBounds( ).width / 2, _exitBtn.getLocalBounds( ).height / 2);
        this->_exitBtn.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 + 300);
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
                    this->_data->machine.addState (StateRef (new MenuScreen (_data)));
                }

                if (event.key.code == sf::Keyboard::Q) {
                    this->_data->window.close ( );
                }
            }
        }
    }

    void PausedState::update ( ) { }

    void PausedState::draw ( ) {
        this->_data->window.clear( );
        this->_data->window.draw(this->_background);
        this->_data->window.draw(this->_resumeBtn);
        this->_data->window.draw(this->_instructionsBtn);
        this->_data->window.draw(this->_aboutBtn);
        this->_data->window.draw(this->_exitBtn);

        // this->_data->window.draw(this->_text );
        this->_data->window.display( );
    }
}