#include <iomanip>

#include "Definition.hpp"
#include "InputManager.hpp"
#include "InstructionsState.hpp"

namespace HeadBall {
    InstructionsState::InstructionsState (GameDataRef data) : _data{data} { }

    void InstructionsState::init () {
        
        if (!this->_data->assets.isFontPresent("Text Font")){
            this->_data->assets.loadFont("Text Font", TEXT_FONT_FILEPATH);
        }


        /////
        this->_instructionsText.setString (this->displayInstructions());
        this->_instructionsText.setFont (this->_data->assets.getFont("Text Font"));
        this->_instructionsText.setCharacterSize (50);
        this->_instructionsText.setOrigin (_instructionsText.getGlobalBounds( ).width / 2, _instructionsText.getGlobalBounds( ).height / 2);
        this->_instructionsText.setPosition (WINDOW_WIDTH / 2,  WINDOW_HEIGHT / 3);

        ////


        if (!this->_data->assets.isTexturePresent("Plain bg")){
            this->_data->assets.loadTexture("Plain bg", PLAIN_BG_FILEPATH);
        }

        if (!this->_data->assets.isTexturePresent("Back btn")){   //to-do: use Return to main menu button instead
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

    void InstructionsState::handleInput ( ) {
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

    std::string InstructionsState::displayInstructions () {
        this->ss.str (std::string ( ));

        ss << "INSTRUCTIONS: \n----------------------------" << "\nPLAYER CONTROLS:\n\n";
        ss << "   PLAYER 1:" <<"\t      PLAYER 2: \n   ---------\t      ---------\n";
        ss << std::setw(10) << "LEFT : " << TOSTRING ( P1_LEFT ) << std::setw(18) << "LEFT : " << TOSTRING( P2_LEFT ) << "\n";
        ss << std::setw(10) << "RIGHT: " << TOSTRING ( P1_RIGHT ) << std::setw(18) << "RIGHT: " << TOSTRING( P2_RIGHT ) << "\n";
        ss << std::setw(10) << "JUMP : " << TOSTRING ( P1_JUMP ) << std::setw(18) << "JUMP : " << TOSTRING( P2_JUMP ) << "\n";
        ss << std::setw(10) << "KICK : " << TOSTRING ( P1_KICK ) << std::setw(18) << "KICK : " <<  TOSTRING( P2_KICK ) << "\n";

       return this->ss.str ( );
    }

    void InstructionsState::update ( ) { }

    void InstructionsState::draw ( ) {
        this->_data->window.clear( );
        this->_data->window.draw(this->_background);
        this->_data->window.draw(this->_backBtn);
        this->_data->window.draw(this->_exitBtn);
        // this->_data->window.draw(this->_text);
        this->_data->window.draw(this->_instructionsText);
        this->_data->window.display ( );
    }
}