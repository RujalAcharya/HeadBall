#include "Definition.hpp"
#include "AboutState.hpp"
#include "MenuScreen.hpp"
#include "InputManager.hpp"

namespace HeadBall {
    AboutState::AboutState (GameDataRef data) : _data{data} { }

    void AboutState::init () {
        
        if (!this->_data->assets.isFontPresent("Text Font")){
            this->_data->assets.loadFont("Text Font", TEXT_FONT_FILEPATH);
        }

        this->_text.setString ("Made By:\nPrajwol Pradhan\nRujal Acharya\nSanjay KC\nAsmin Silwal       ");
        this->_text.setFont (this->_data->assets.getFont("Text Font"));

        this->_text.setCharacterSize (30);
        this->_text.setOrigin (_text.getGlobalBounds( ).width / 2, _text.getGlobalBounds( ).height / 2);
        this->_text.setPosition (WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);


        if (!this->_data->assets.isTexturePresent("Plain bg")){
            this->_data->assets.loadTexture("Plain bg", PLAIN_BG_FILEPATH);
        }

        if (!this->_data->assets.isTexturePresent("Back btn")){
            this->_data->assets.loadTexture("Back btn", BACK_BTN_FILEPATH);
        }

        if (!this->_data->assets.isTexturePresent("Exit btn")){
            this->_data->assets.loadTexture("Exit btn", EXIT_BTN_FILEPATH);
        }


        if (!this->_data->assets.isSoundPresent("Button click")){
            this->_data->assets.loadSound("Button click", BTN_CLICK_SFX_FILEPATH);
        }
        this->_btnClickSfx.setBuffer(this->_data->assets.getSound("Button click"));


        this->_background.setTexture(this->_data->assets.getTexture("Plain bg"));
        this->_background.setOrigin(_background.getGlobalBounds( ).width / 2, _background.getGlobalBounds( ).height / 2);
        this->_background.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

        this->_backBtn.setTexture(this->_data->assets.getTexture("Back btn"));
        this->_backBtn.setOrigin(_backBtn.getGlobalBounds( ).width / 2, _backBtn.getGlobalBounds( ).height / 2);
        this->_backBtn.setPosition((WINDOW_WIDTH / 2 - WINDOW_WIDTH / 4), (3 * WINDOW_HEIGHT / 4 + 25));

        this->_exitBtn.setTexture(this->_data->assets.getTexture("Exit btn"));
        this->_exitBtn.setOrigin(_exitBtn.getGlobalBounds( ).width / 2, _exitBtn.getGlobalBounds( ).height / 2);
        this->_exitBtn.setPosition((WINDOW_WIDTH / 2 + WINDOW_WIDTH / 4), (3 * WINDOW_HEIGHT / 4 + 25));
    }

    void AboutState::handleInput ( ) {
        sf::Event event;

        while (this->_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->_data->window.close( );
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    this->_data->machine.removeState ( );
                }

                if (event.key.code == sf::Keyboard::Q) {
                    this->_data->window.close ( );
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (this->_data->input.isSpriteClicked(this->_backBtn, sf::Mouse::Left, this->_data->window)) {
                    _btnClickSfx.play();

                    this->_data->machine.removeState ( );
                }

                else if (this->_data->input.isSpriteClicked(this->_exitBtn, sf::Mouse::Left, this->_data->window)) {
                    _btnClickSfx.play();

                    this->_data->window.close ( );
                }
            }
        }
    }

    void AboutState::update ( ) { }

    void AboutState::draw ( ) {
        this->_data->window.clear( );
        this->_data->window.draw(this->_background);
        this->_data->window.draw(this->_backBtn);
        this->_data->window.draw(this->_exitBtn);

        this->_data->window.draw(this->_text );
        this->_data->window.display( );
    }
}