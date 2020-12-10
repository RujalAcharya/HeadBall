#include "Definition.hpp"
#include "GameOver.hpp"
#include "MenuScreen.hpp"
#include "GameState.hpp"

#include <sstream>

namespace HeadBall {
    GameOver::GameOver (GameDataRef data, ScoreTimeRef scoreTime) : _data{data}, _scoreTime{scoreTime} { }

    void GameOver::init ( ) {
        
        if (!this->_data->assets.isFontPresent("Digit Font")) {
            this->_data->assets.loadFont("Digit Font", TEXT_FONT_FILEPATH);
        }

        if (!this->_data->assets.isTexturePresent ("Fulltime Background")) {
            this->_data->assets.loadTexture ("Fulltime Background", FULL_TIME_BG_FILEPATH);
        }

        if (!this->_data->assets.isSoundPresent("Crowd cheer on goal")) {
             this->_data->assets.loadSound("Crowd cheer on goal", CROWD_CHEER_ON_GOAL_SFX_FILEPATH);
        }
         if (!this->_data->assets.isSoundPresent("Button click")){
            this->_data->assets.loadSound("Button click", BTN_CLICK_SFX_FILEPATH);
        }

        if (!this->_data->assets.isTexturePresent ("Replay btn")) {
            this->_data->assets.loadTexture ("Replay btn", REPLAY_BTN_FILEPATH);
        }

        if (!this->_data->assets.isTexturePresent ("Exit btn")) {
            this->_data->assets.loadTexture ("Exit btn", EXIT_BTN_FILEPATH);
        }

        this->_background.setTexture (this->_data->assets.getTexture ("Fulltime Background"));
        this->_background.setOrigin (0, 0);

        this->_replayBtn.setTexture (this->_data->assets.getTexture ("Replay btn"));
        this->_replayBtn.setOrigin (this->_replayBtn.getGlobalBounds ( ).width / 2, this->_replayBtn.getGlobalBounds( ).height / 2);
        this->_replayBtn.setPosition((WINDOW_WIDTH / 2 - WINDOW_WIDTH / 4), (3 * WINDOW_HEIGHT / 4 + 50));

        this->_exitBtn.setTexture (this->_data->assets.getTexture ("Exit btn"));
        this->_exitBtn.setPosition((WINDOW_WIDTH / 2 + WINDOW_WIDTH / 4), (3 * WINDOW_HEIGHT / 4 + 50));

        std::stringstream ss;
        ss <<  this->_scoreTime->p1Score << "         " << this->_scoreTime->p2Score;
       
        this->_score.setString (ss.str ( ));
        this->_score.setFont (this->_data->assets.getFont("Digit Font"));
        this->_score.setCharacterSize (150);
        this->_score.setOrigin (_score.getGlobalBounds( ).width / 2, _score.getGlobalBounds( ).height / 2);
        this->_score.setPosition (WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

        if (this->_scoreTime->p1Score > this->_scoreTime->p2Score) {
            this->_winnerText.setString ("PLAYER 1 WINS");
        } else if (this->_scoreTime->p1Score < this->_scoreTime->p2Score) {
            this->_winnerText.setString ("PLAYER 2 WINS");
        } else {
            this->_winnerText.setString ("MATCH TIED");
        }
        
        this->_winnerText.setFont (this->_data->assets.getFont("Digit Font"));
        this->_winnerText.setCharacterSize (80);
        this->_winnerText.setOrigin(_winnerText.getGlobalBounds( ).width / 2, _winnerText.getGlobalBounds( ).height / 2);
        this->_winnerText.setPosition(WINDOW_WIDTH / 2, 3 * WINDOW_HEIGHT / 4 - 25);       
        
        this->_crowdCheerOnGoal.setBuffer (this->_data->assets.getSound("Crowd cheer on goal"));
        this->_crowdCheerOnGoal.play ( );

        this->_btnClickSfx.setBuffer(this->_data->assets.getSound("Button click"));

    }

    void GameOver::handleInput ( ) {
        sf::Event event;

        while (this->_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->_data->window.close( );
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    // this->_data->machine.addState (StateRef (new MenuScreen (_data)), false );
                    this->_scoreTime->time.zero ( );
                    this->_scoreTime->p1Score = 0;
                    this->_scoreTime->p2Score = 0;
                    this->_data->machine.addState (StateRef (new GameState (_data, _scoreTime)));
                }

                if (event.key.code == sf::Keyboard::Q) {
                    this->_data->window.close ( );
                }
            }

            if (this->_data->input.isSpriteClicked (this->_replayBtn, sf::Mouse::Left, this->_data->window)) {
                this->_btnClickSfx.play ( );
                
                this->_scoreTime->time.zero ( );
                this->_scoreTime->p1Score = 0;
                this->_scoreTime->p2Score = 0;
                this->_data->machine.addState (StateRef (new GameState (_data, _scoreTime)));
            }

            else if (this->_data->input.isSpriteClicked (this->_exitBtn, sf::Mouse::Left, this->_data->window)) {
                this->_btnClickSfx.play ( );

                this->_data->window.close ( );
            }
        }
    }

    void GameOver::update ( ) { }

    void GameOver::draw ( ) {
        this->_data->window.clear ( );
        this->_data->window.draw (this->_background);
        this->_data->window.draw (this->_score);
        this->_data->window.draw (this->_winnerText);
        this->_data->window.draw (this->_replayBtn);
        this->_data->window.draw (this->_exitBtn);
        this->_data->window.display ( );
    }
}
