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

        if (!this->_data->assets.isTexturePresent("Red Goal")) {
            this->_data->assets.loadTexture ("Red Goal", RED_GOAL_BG_FILEPATH);
        }

        if (!this->_data->assets.isTexturePresent("Green Goal")) {
            this->_data->assets.loadTexture ("Green Goal", GREEN_GOAL_BG_FILEPATH);
        }        

        if (!this->_data->assets.isTexturePresent("Yellow Goal")) {
            this->_data->assets.loadTexture ("Yellow Goal", YELLOW_GOAL_BG_FILEPATH);
        }

        if (!this->_data->assets.isSoundPresent("Crowd cheer on goal")){
            this->_data->assets.loadSound("Crowd cheer on goal", CROWD_CHEER_ON_GOAL_SFX_FILEPATH);
        }
        
        
        this->_crowdCheerOnGoal.setBuffer (this->_data->assets.getSound("Crowd cheer on goal"));
        this->_crowdCheerOnGoal.play ( );

        this->_background.setTexture (this->_data->assets.getTexture ("Red Goal"));
        this->_background.setPosition (0, 0);

        this->_animationCounter = 0;

    }

    void GoalState::handleInput ( ) {
        sf::Event event;

        while (this->_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->_data->window.close( );
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    this->_scoreTime->time.resume ( );
                    this->_crowdCheerOnGoal.stop ( );
                    this->_data->machine.addState (StateRef(new GameState (this->_data, this->_scoreTime, this->_isSecondHalf)) );
                }
            }
        }
    }

    void GoalState::update ( ) {
        this->_animationCounter ++;
        if (this->_animationCounter == FRAMES_PER_ANIMATION * 3) {
            this->_background.setTexture (this->_data->assets.getTexture ("Green Goal"));
        }

        if (this->_animationCounter == FRAMES_PER_ANIMATION * 6) {
            this->_background.setTexture (this->_data->assets.getTexture ("Red Goal"));
        }

        if (this->_animationCounter == FRAMES_PER_ANIMATION * 9) {
            this->_background.setTexture (this->_data->assets.getTexture ("Yellow Goal"));
        }

        if (this->_animationCounter == FRAMES_PER_ANIMATION * 12) {
            this->_background.setTexture (this->_data->assets.getTexture ("Red Goal"));
            this->_animationCounter = 0;
        }
    }

    void GoalState::draw ( ) {
        this->_data->window.clear();
        this->_data->window.draw (this->_background);
        this->_data->window.display( );
    }
}