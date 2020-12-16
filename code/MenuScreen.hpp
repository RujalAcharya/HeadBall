#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"
#include "InputManager.hpp"

namespace HeadBall {
    /*!
     * @brief Derived class of State class with visibility mode 
     *        public that includes the functionality  of menuscreen
     * 
     */
    class MenuScreen : public State {
        public:
            /*!
             * @brief Construct a new Menu Screen object
             * 
             * @param data  The shared pointer of GameData
             */
            MenuScreen (GameDataRef data);

            /*!
             * @brief Initialize a new MenuScreen object
             * 
             */
            void init ( );

            /*!
             * @brief Handles the user input in Menu screen
             * 
             */
            void handleInput ( );

            /*!
             * @brief updates the window according to provided input
             * 
             */
            void update ( );

            /*!
             * @brief Draw all the SFML objects in the rendering window
             * 
             */
            void draw ( );

        private:
            GameDataRef _data;                                                  //!< The shared pointer of GameData
            ScoreTimeRef _scoreTime = std::make_shared <ScoreTimeData> ( );     //!< The shared pointer of ScoreTimeData
            sf::Sprite _background;                                             //!< The sprite object for background of Menu screen
            sf::Sprite _playBtn;                                                //!< The sprite object for "play" button
            sf::Sprite _instructionsBtn;                                        //!< The sprite object for "Instruction" button
            sf::Sprite _aboutBtn;                                               //!< The sprite object for "About" button
            sf::Sprite _exitBtn;                                                //!< The sprite object for "exit" button
            sf::Music _theme;                                                   //!< The music object for theme music
            sf::Text _text;                                                     //!< The text object for text in Menu screen
            sf::Sound _btnClickSfx;                                             //!< The sound object for sfx while clicking any button
    };
}