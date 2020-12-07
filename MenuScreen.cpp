#include "Definition.hpp"
#include "MenuScreen.hpp"
#include "GameState.hpp"

namespace HeadBall {
    MenuScreen::MenuScreen (GameDataRef data) : _data{data} { }

    void MenuScreen::init () {
        if (!this->_data->assets.isFontPresent("Text Font")){
            this->_data->assets.loadFont("Text Font", TEXT_FONT_FILEPATH);
        }

        this->_text.setString ("Menu Screen");
        this->_text.setFont (this->_data->assets.getFont("Text Font"));

        this->_text.setCharacterSize (30);
        this->_text.setOrigin(_text.getGlobalBounds( ).width / 2, _text.getGlobalBounds( ).height / 2);
        this->_text.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);


        if (!this->_data->assets.isTexturePresent("Main menu bg")){
            this->_data->assets.loadTexture("Main menu bg", MAIN_MENU_BG_FILEPATH);
        }

        if (!this->_data->assets.isTexturePresent("Play btn")){
            this->_data->assets.loadTexture("Play btn", PLAY_BTN_FILEPATH);
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

        this->_background.setTexture(this->_data->assets.getTexture("Main menu bg"));


        this->_playBtn.setTexture(this->_data->assets.getTexture("Play btn"));
        this->_playBtn.setOrigin(_playBtn.getLocalBounds( ).width / 2, _playBtn.getLocalBounds( ).height / 2);
        this->_playBtn.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

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

    void MenuScreen::handleInput ( ) {
        sf::Event event;

        while (this->_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->_data->window.close( );
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    this->_scoretime->p1Score = 0;
                    this->_scoretime->p2Score = 0;
                    this->_data->machine.addState (StateRef (new GameState (this->_data, this->_scoretime)));
                }

                if (event.key.code == sf::Keyboard::Q) {
                    this->_data->window.close ( );
                }
            }
        }
    }

    void MenuScreen::update ( ) { }

    void MenuScreen::draw ( ) {
        this->_data->window.clear( );
        this->_data->window.draw(_background);
        this->_data->window.draw(_playBtn);
        this->_data->window.draw(_instructionsBtn);
        this->_data->window.draw(_aboutBtn);
        this->_data->window.draw(_exitBtn);

        // this->_data->window.draw(this->_text );
        this->_data->window.display( );
    }
}