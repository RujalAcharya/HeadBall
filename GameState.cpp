#include "Definition.hpp"
#include "GameState.hpp"
#include "PausedState.hpp"
#include "HalfTime.hpp"
#include "GameOver.hpp"

namespace HeadBall {
    GameState::GameState (GameDataRef data) : _data{data}, _ground{data, this->_world}, _ball{data, this->_world}, _rightUpHill{data, this->_world}, _leftUpHill{data, this->_world}, _p1{data, this->_world}, _p2{data, this->_world}   { }

    void GameState::init () {
        if (!this->_data->assets.isFontPresent("Digit Font")){
            this->_data->assets.loadFont("Digit Font", DIGIT_FONT_FILEPATH);
        }

        this->_text.setString ("Timer");
        this->_text.setFont (this->_data->assets.getFont("Digit Font"));
        this->_text.setCharacterSize (50);
        this->_text.setOrigin (this->_text.getGlobalBounds( ).width / 2, this->_text.getGlobalBounds( ).height / 2);
        this->_text.setPosition (WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 200);

        this->_isPaused = false;
        this->_isSecondHalf = false;

        this->_ground.init ( );
        this->_leftUpHill.init (sf::Vector2i (UPHILL_WIDTH / 2, WINDOW_HEIGHT - (UPHILL_HEIGHT / 2 + GROUND_HEIGHT)));
        this->_rightUpHill.init (sf::Vector2i (WINDOW_WIDTH - (UPHILL_WIDTH / 2), WINDOW_HEIGHT - ( UPHILL_HEIGHT / 2 + GROUND_HEIGHT)));

        this->_ball.init ( );
        this->_p1.init ("P1 Still", P1_STILL_FILEPATH, sf::Vector2f (WINDOW_WIDTH / 3, WINDOW_HEIGHT / 2));
        this->_p2.init ("P2 Still", P2_STILL_FILEPATH, sf::Vector2f (2 * WINDOW_WIDTH / 3, WINDOW_WIDTH / 2));

    }

    void GameState::handleInput ( ) {
        sf::Event event;

        while (this->_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->_data->window.close( );
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    this->_data->machine.addState (StateRef (new PausedState (this->_data)), false);
                }
            }
        }
    }

    void GameState::update (float dt) {
        if (!this->_isPaused) {
            this->_timer.processTime ( );

            this->_text.setString (this->_timer.displayTimer ( ));

            if (this->_timer.getTime ( ) >= GAME_TIME / 2 && !this->_isSecondHalf) {
                this->_isSecondHalf = true;
                this->_data->machine.addState (StateRef (new HalfTime (this->_data)), false);
            }

            if (this->_timer.getTime ( ) >= GAME_TIME) {
                this->_data->machine.addState (StateRef (new GameOver (this->_data)));
            }

            this->_world->Step (1 / 20.0, VELOCITY_ITERATIONS, POSITION_ITERATIONS);    

            this->_ball.processPosition ( );
            this->_p1.processPosition ( );
            this->_p2.processPosition ( );

        }
    }

    void GameState::draw (float dt) {
        if (!this->_isPaused) {
            this->_data->window.clear (sf::Color::Red);
            this->_data->window.draw (this->_text );
            this->_data->window.draw (this->_ground.shape ( ));
            this->_data->window.draw (this->_ball.shape ( ));
            this->_data->window.draw (this->_leftUpHill.shape ( ));
            this->_data->window.draw (this->_rightUpHill.shape ( ));
            this->_data->window.draw (this->_p1.sprite ( ));
            this->_data->window.draw (this->_p2.sprite ( ));
            this->_data->window.display( );
        }
    }

    void GameState::pause ( ) {
        this->_timer.pause ( );
        this->_isPaused = true;
    }

    void GameState::resume ( ) {
        this->_timer.resume ( );
        this->_isPaused = false;
    }
}