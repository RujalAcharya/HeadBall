#include "Definition.hpp"
#include "GameState.hpp"
#include "PausedState.hpp"
#include "HalfTime.hpp"
#include "GameOver.hpp"
#include "GoalState.hpp"

#include <sstream>

namespace HeadBall {
    GameState::GameState (GameDataRef data, ScoreTimeRef scoretime, bool isSecondHalf) : _data{data}, _scoreTime{scoretime}, _ground{data, this->_world}, _ball{data, this->_world}, _rightUpHill{data, this->_world}, _leftUpHill{data, this->_world}, _leftPost{data}, _rightPost{data}, _wall{data, this->_world}, _p1{data, this->_world}, _p2{data, this->_world}   {
                this->_isSecondHalf = isSecondHalf; 
    }

    void GameState::init () {
        if (!this->_data->assets.isFontPresent("Digit Font")){
            this->_data->assets.loadFont("Digit Font", DIGIT_FONT_FILEPATH);
        }


        if (!this->_data->assets.isSoundPresent("Button click")){
            this->_data->assets.loadSound("Button click", BTN_CLICK_SFX_FILEPATH);
        }

        if (!this->_data->assets.isSoundPresent("Short Whistle")){
            this->_data->assets.loadSound("Short Whistle", WHISTLE_START_SFX_FILEPATH);
        }

        if (!this->_data->assets.isSoundPresent("Long Whistle")){
            this->_data->assets.loadSound("Long Whistle", WHISTLE_HALFTIME_SFX_FILEPATH);
        }

        
        if (!this->_data->assets.isTexturePresent("Pause btn")){
            this->_data->assets.loadTexture("Pause btn", PAUSE_BTN_FILEPATH);
        }
        
        
        this->_btnClickSfx.setBuffer(this->_data->assets.getSound("Button click"));
        this->_shortWhistleSfx.setBuffer(this->_data->assets.getSound("Short Whistle"));
        this->_longWhistleSfx.setBuffer (this->_data->assets.getSound("Long Whistle"));


        this->_timeText.setString ("Timer");
        this->_timeText.setFont (this->_data->assets.getFont("Digit Font"));
        this->_timeText.setCharacterSize (50);
        this->_timeText.setOrigin (this->_timeText.getGlobalBounds( ).width / 2, this->_timeText.getGlobalBounds( ).height / 2);
        this->_timeText.setPosition (WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 500);

        this->_p1Score.setString ("00");
        this->_p1Score.setFont (this->_data->assets.getFont("Digit Font"));
        this->_p1Score.setCharacterSize (100);
        this->_p1Score.setOrigin (this->_p1Score.getGlobalBounds( ).width / 2, this->_p1Score.getGlobalBounds( ).height / 2);
        this->_p1Score.setPosition (UPHILL_WIDTH / 2, WINDOW_HEIGHT - GROUND_HEIGHT - UPHILL_HEIGHT / 2);

        this->_p2Score.setString ("00");
        this->_p2Score.setFont (this->_data->assets.getFont("Digit Font"));
        this->_p2Score.setCharacterSize (100);
        this->_p2Score.setOrigin (this->_p2Score.getGlobalBounds( ).width / 2, this->_p2Score.getGlobalBounds( ).height / 2);
        this->_p2Score.setPosition (WINDOW_WIDTH - UPHILL_WIDTH / 2, WINDOW_HEIGHT - GROUND_HEIGHT - UPHILL_HEIGHT / 2);



        this->_isPaused = false;

        this->_ground.init ( );
        this->_leftUpHill.init (sf::Vector2i (UPHILL_WIDTH / 2, WINDOW_HEIGHT - (UPHILL_HEIGHT / 2 + GROUND_HEIGHT)));
        this->_rightUpHill.init (sf::Vector2i (WINDOW_WIDTH - (UPHILL_WIDTH / 2), WINDOW_HEIGHT - ( UPHILL_HEIGHT / 2 + GROUND_HEIGHT)));
        this->_wall.init ( );

        this->_leftPost.init(sf::Vector2f(GOAL_POST_WIDTH / 2, WINDOW_HEIGHT - GROUND_HEIGHT - UPHILL_HEIGHT - GOAL_POST_HEIGHT / 2));
        this->_rightPost.init(sf::Vector2f(WINDOW_WIDTH - GOAL_POST_WIDTH / 2,  WINDOW_HEIGHT - GROUND_HEIGHT - UPHILL_HEIGHT - GOAL_POST_HEIGHT / 2), false);

        this->_ball.init ( );
        this->_p1.init ("P1 Still", P1_STILL_FILEPATH, sf::Vector2f (WINDOW_WIDTH / 3, WINDOW_HEIGHT / 2));
        this->_p2.init ("P2 Still", P2_STILL_FILEPATH, sf::Vector2f (2 * WINDOW_WIDTH / 3, WINDOW_HEIGHT / 2));

        if (!_isSecondHalf) {
            this->_scoreTime->time.resetTimer ( );
        }
        this->_scoreTime->time.resume ( );


        
        this->_pauseBtn.setTexture(this->_data->assets.getTexture("Pause btn"));
        this->_pauseBtn.setOrigin(_pauseBtn.getLocalBounds( ).width / 2, _pauseBtn.getLocalBounds( ).height / 2);
        this->_pauseBtn.setPosition(WINDOW_WIDTH - 100, WINDOW_HEIGHT / 2 - 400);


        if (this->_crowdCheerSfx.openFromFile(CROWD_CHEER_FILEPATH)) {
            this->_crowdCheerSfx.play();
            this->_crowdCheerSfx.setLoop(true);
        }

        this->_shortWhistleSfx.play ( );

    }

    void GameState::handleInput ( ) {
        sf::Event event;

        while (this->_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->_data->window.close( );
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    this->_crowdCheerSfx.stop();
                    
                    this->_data->machine.addState (StateRef (new PausedState (this->_data)), false);
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (this->_data->input.isSpriteClicked(this->_pauseBtn, sf::Mouse::Left, this->_data->window)) {
                    this->_crowdCheerSfx.stop();
                    this->_btnClickSfx.play();

                    this->_data->machine.addState (StateRef (new PausedState (this->_data)), false);
                }
            }
        }

        if (this->_data->input.isMoving("left")) {
            this->_p1.moveLeft ( );
        }

        if (this->_data->input.isMoving("right")) {
            this->_p1.moveRight ( );
        }

        if (this->_data->input.isMoving("left", "p2")) {
            this->_p2.moveLeft ( );
        }

        if (this->_data->input.isMoving("right", "p2")) {
            this->_p2.moveRight ( );
        }

        if (this->_data->input.isDoing ("jump")) {
            this->_playerJumpSfx.play();

            this->_p1.jump ( );
        }

        if (this->_data->input.isDoing ("jump", "p2")) {
            this->_playerJumpSfx.play();
            this->_p2.jump ( );
        }
        
    }

    void GameState::update ( ) {
        if (!this->_isPaused) {
            this->_scoreTime->time.processTime ( );

            this->_timeText.setString (this->_scoreTime->time.displayTimer ( ));

            if (this->_scoreTime->time.getTime ( ) >= 45 && !this->_isSecondHalf) {
                this->_scoreTime->time.pause ( );
                this->_longWhistleSfx.play ( );
                this->_data->machine.addState (StateRef (new HalfTime (this->_data, this->_scoreTime)));
            }

            if (this->_scoreTime->time.getTime ( ) >= 90) {
                this->_longWhistleSfx.play ( );
                this->_data->machine.addState (StateRef (new GameOver (this->_data)));
            }

            this->_world->Step (1 / 20.0, VELOCITY_ITERATIONS, POSITION_ITERATIONS);    

            this->_ball.processPosition ( );
            this->_p1.processPosition ( );
            this->_p2.processPosition ( );

            sf::IntRect leftPostRect (this->_leftPost.sprite( ).getPosition( ).x - this->_leftPost.sprite( ).getGlobalBounds( ).width / 2, this->_leftPost.sprite( ).getPosition( ).y - this->_leftPost.sprite( ).getGlobalBounds( ).height / 2, this->_leftPost.sprite( ).getGlobalBounds( ).width, this->_leftPost.sprite( ).getGlobalBounds( ).height);
            if (leftPostRect.contains(this->_ball.shape( ).getPosition( ).x, this->_ball.shape( ).getPosition( ).y)) {
                this->_scoreTime->p1Score ++;
                this->_scoreTime->time.pause ( );
                this->_shortWhistleSfx.play ( );
                this->_data->machine.addState (StateRef (new GoalState (this->_data, this->_scoreTime)) );
            }

            sf::IntRect rightPostRect (this->_rightPost.sprite( ).getPosition( ).x - this->_rightPost.sprite( ).getGlobalBounds( ).width / 2, this->_rightPost.sprite( ).getPosition( ).y - this->_rightPost.sprite( ).getGlobalBounds( ).height / 2, this->_rightPost.sprite( ).getGlobalBounds( ).width, this->_rightPost.sprite( ).getGlobalBounds( ).height);
            if (rightPostRect.contains(this->_ball.shape( ).getPosition( ).x, this->_ball.shape( ).getPosition( ).y)) {
                this->_scoreTime->p2Score ++;
                this->_scoreTime->time.pause ( );
                this->_shortWhistleSfx.play ( );
                this->_data->machine.addState (StateRef (new GoalState (this->_data, this->_scoreTime)) );
            }

            std::stringstream score;
            score << this->_scoreTime->p1Score;
            this->_p1Score.setString (score.str( ));

            score.str (std::string ( ));
            score << this->_scoreTime->p2Score;
            this->_p2Score.setString (score.str( ));

        }
    }

    void GameState::draw ( ) {
        if (!this->_isPaused) {
            this->_data->window.clear (sf::Color(135,206,235));
            this->_data->window.draw (this->_timeText);
            this->_data->window.draw (this->_ground.shape ( ));
            this->_data->window.draw (this->_pauseBtn);
            this->_data->window.draw (this->_leftUpHill.shape ( ));
            this->_data->window.draw (this->_rightUpHill.shape ( ));
            this->_data->window.draw (this->_ball.shape ( ));
            this->_data->window.draw (this->_p1.sprite ( ));
            this->_data->window.draw (this->_p2.sprite ( ));
            this->_data->window.draw (this->_p1Score);
            this->_data->window.draw (this->_p2Score);
            this->_data->window.draw (this->_leftPost.sprite ( ));
            this->_data->window.draw (this->_rightPost.sprite ( ));
            this->_data->window.display ( );
        }
    }

    void GameState::pause ( ) {
        this->_scoreTime->time.pause ( );
        this->_isPaused = true;
    }

    void GameState::resume ( ) {
        this->_scoreTime->time.resume ( );
        this->_isPaused = false;
    }
}