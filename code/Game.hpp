#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <string>
#include <memory>

#include "StateMachine.hpp"
#include "InputManager.hpp"
#include "AssetManager.hpp"
#include "TimeManager.hpp"

namespace HeadBall {
    /*!
     * @brief Struct where the necessaey game data used by all the states is stored
     * 
     */
    struct GameData {
        sf::RenderWindow window;
        StateMachine machine;
        InputManager input;
        AssetManager assets;
    };

    /*!
     * @brief Struct where the game time and player score is stored
     * 
     */
    struct ScoreTimeData {
        TimeManager time;
        int p1Score;
        int p2Score;
    };

    /*!
     * @brief The Shared Pointer of GameData Struct
     * 
     */
    typedef std::shared_ptr <GameData> GameDataRef;

    /*!
     * @brief The Shared Pointer of ScoreTimeData struct
     * 
     */
    typedef std::shared_ptr <ScoreTimeData> ScoreTimeRef;

    /*!
     * @brief The Shared Pointer that points to the Box2D world
     * 
     */
    typedef std::shared_ptr <b2World> WorldRef;

    /*!
     * @brief Class where game loop is processed
     * 
     */
    class Game {
        public:
            /*!
             * @brief Construct a new Game object
             * 
             * @param width 
             * @param height 
             * @param title 
             */
            Game (int width, int height, std::string title);

        private:
            /*!
             * @brief Run the game loop
             * 
             */
            void run ( );

            const float dt = 1.0f / 60.0f;                        //!< The delta time for framerate management
            sf::Clock _clock;                                     //!< The clock for getting ti

            GameDataRef _data = std::make_shared <GameData> ( );  //!< The shared pointer of game data
    };
}