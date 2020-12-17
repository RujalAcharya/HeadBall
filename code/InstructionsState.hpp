#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>

#include "State.hpp"
#include "Game.hpp"

namespace HeadBall {
    /*!
     * @brief Derived class of State class with visibility mode public
     *        that provides a state to instuct the players about basic controls of game
     * 
     */
    class InstructionsState : public State {
        public:
            /*!
             * @brief Construct a new Instructions State object
             * 
             * @param data The shared pointer of GameData
             */
            InstructionsState (GameDataRef data);

            /*!
             * @brief Initializes a new InstructionsState object
             * 
             */
            void init ( );

            /*!
             * @brief Takes instruction to be displayed in the window
             *          and returns it
             * @return std::string returns the instructions 
             */
            std::string displayInstructions ( );

            /*!
             * @brief Handles input
             * 
             */
            void handleInput ( );

            /*!
             * @brief Updates the state according to the input 
             * 
             */
            void update ( );

            /*!
             * @brief Draws SFML objects of Instruction state
             * 
             */
            void draw ( );

        private:
            GameDataRef _data;          //!<  The shared pointer for all the game data

            sf::Sprite _background;     //!<  Background sprite to draw on the screen          
            sf::Sprite _backBtn;        //!<  Button to return back
            sf::Sprite _exitBtn;        //!<  Button to exit from the game

            sf::Sound _btnClickSfx;     //!<  Sound effect for button click

            sf::Text _instructionsText; //!<  Text to display `instructions` information
            std::stringstream ss;       //!<  String stream to update the controls as in definitions.hpp

    };
}
