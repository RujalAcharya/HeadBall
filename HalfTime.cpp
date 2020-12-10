#include "Definition.hpp"
#include "HalfTime.hpp"
#include "GameState.hpp"
#include "MenuScreen.hpp"

#include <sstream>

namespace HeadBall {
    HalfTime::HalfTime (GameDataRef data, ScoreTimeRef scoretime) : _data{data}, _scoreTime{scoretime} { }

    void HalfTime::init () {

        if (!this->_data->assets.isFontPresent("Digit Font")){
            this->_data->assets.loadFont("Digit Font", DIGIT_FONT_FILEPATH);
        }

        if (!this->_data->assets.isTexturePresent ("Halftime Background")) {
            this->_data->assets.loadTexture ("Halftime Background", HALF_TIME_BG_FILEPATH);
        }

        if (!this->_data->assets.isTexturePresent ("Resume btn")) {
            this->_data->assets.loadTexture ("Resume btn", RESUME_BTN_FILEPATH);
        }

        if (!this->_data->assets.isSoundPresent("Button click")){
            this->_data->assets.loadSound("Button click", BTN_CLICK_SFX_FILEPATH);
        }

        this->_btnClickSfx.setBuffer(this->_data->assets.getSound("Button click"));

        this->_background.setTexture (this->_data->assets.getTexture ("Halftime Background"));
        this->_background.setOrigin (0, 0);

        std::stringstream ss;

        ss <<  this->_scoreTime->p1Score << "         " << this->_scoreTime->p2Score;
       
        this->_score.setString (ss.str ( ));
        this->_score.setFont (this->_data->assets.getFont("Digit Font"));
        this->_score.setCharacterSize (150);
        this->_score.setOrigin (_score.getGlobalBounds( ).width / 2, _score.getGlobalBounds( ).height / 2);
        this->_score.setPosition (WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

        this->_resumeBtn.setTexture (this->_data->assets.getTexture("Resume btn"));
        this->_resumeBtn.setOrigin (_resumeBtn.getGlobalBounds( ).width / 2, _resumeBtn.getGlobalBounds( ).height / 2);
        this->_resumeBtn.setPosition (WINDOW_WIDTH / 2, (3 * WINDOW_HEIGHT / 4 + 25));

        if (this->_theme.openFromFile(GAME_MUSIC_FILEPATH)) {
            this->_theme.play();
            this->_theme.setLoop(true);
        }
    }

    void HalfTime::handleInput ( ) {
        sf::Event event;

        while (this->_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->_data->window.close( );
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    this->_theme.stop ( );
                    this->_scoreTime->time.resume ( );
                    this->_data->machine.addState (StateRef(new GameState (this->_data, this->_scoreTime, true)) );
                }
            }
        }

        if (this->_data->input.isSpriteClicked (this->_resumeBtn, sf::Mouse::Left, this->_data->window)) {
            this->_btnClickSfx.play ( );
            this->_theme.stop ( );
            this->_scoreTime->time.resume ( );
            this->_data->machine.addState (StateRef(new GameState (this->_data, this->_scoreTime, true)) );
        }
    }

    void HalfTime::update ( ) { }

    void HalfTime::draw ( ) {
        this->_data->window.clear ( );
        this->_data->window.draw (this->_background);
        this->_data->window.draw (this->_score);
        this->_data->window.draw (this->_resumeBtn);
        this->_data->window.display( );
    }
}