#include "Definition.hpp"
#include "GameOver.hpp"
#include "MenuScreen.hpp"
#include "GameState.hpp"

namespace HeadBall {
    GameOver::GameOver (GameDataRef data, ScoreTimeRef scoreTime) : _data{data}, _scoreTime{scoreTime} { }

    void GameOver::init () {
        
        if (!this->_data->assets.isFontPresent("Text Font")){
            this->_data->assets.loadFont("Text Font", TEXT_FONT_FILEPATH);
        }

        this->_text.setString ("Game Over");
        this->_text.setFont (this->_data->assets.getFont("Text Font"));
        
        this->_text.setCharacterSize (30);
        this->_text.setOrigin(_text.getGlobalBounds( ).width / 2, _text.getGlobalBounds( ).height / 2);
        this->_text.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

        // if (!this->_data->assets.isSoundPresent("Crowd cheer on goal")){
        //     this->_data->assets.loadSound("Crowd cheer on goal", CROWD_CHEER_ON_GOAL_SFX_FILEPATH);
        // }
        
        
        // this->_crowdCheerOnGoal.setBuffer (this->_data->assets.getSound("Crowd cheer on goal"));
        // this->_crowdCheerOnGoal.play ( );

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
        }
    }

    void GameOver::update ( ) { }

    void GameOver::draw ( ) {
        this->_data->window.clear(sf::Color::Green );
        this->_data->window.draw(this->_text );
        this->_data->window.display( );
    }
}