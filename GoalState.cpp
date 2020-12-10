#include "Definition.hpp"
#include "GoalState.hpp"
#include "GameState.hpp"
#include "MenuScreen.hpp"

namespace HeadBall {
    GoalState::GoalState (GameDataRef data, ScoreTimeRef scoretime, bool isSecondHalf) : _data{data}, _scoreTime{scoretime} {
        this->_isSecondHalf = isSecondHalf;
    }

    void GoalState::init () {

        if (!this->_data->assets.isFontPresent("Text Font")){
            this->_data->assets.loadFont("Text Font", TEXT_FONT_FILEPATH);
        }
        
        this->_text.setString("GOOOOOOOOOOOAAAAAAAAALLLLLLLLLLLL");
        this->_text.setFont (this->_data->assets.getFont("Text Font"));

        this->_text.setCharacterSize(50);
        this->_text.setOrigin(_text.getGlobalBounds( ).width / 2, _text.getGlobalBounds( ).height / 2);
        this->_text.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

        if (!this->_data->assets.isSoundPresent("Crowd cheer on goal")){
            this->_data->assets.loadSound("Crowd cheer on goal", CROWD_CHEER_ON_GOAL_SFX_FILEPATH);
        }
        
        
        this->_crowdCheerOnGoal.setBuffer (this->_data->assets.getSound("Crowd cheer on goal"));
        this->_crowdCheerOnGoal.play ( );

    }

    void GoalState::handleInput ( ) {
        sf::Event event;

        while (this->_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->_data->window.close( );
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::R) {
                    this->_scoreTime->time.resume ( );
                    this->_crowdCheerOnGoal.stop ( );
                    this->_data->machine.addState (StateRef(new GameState (this->_data, this->_scoreTime, this->_isSecondHalf)) );
                }
            }
        }
    }

    void GoalState::update ( ) { }

    void GoalState::draw ( ) {
        this->_data->window.clear(sf::Color::Green );
        this->_data->window.draw(this->_text );
        this->_data->window.display( );
    }
}