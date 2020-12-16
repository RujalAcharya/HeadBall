#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>

namespace HeadBall {
    /*!
     * @brief The class that manages the game time
     * 
     */
    class TimeManager {
        public:
            /*!
             * @brief Construct a new Time Manager object
             * 
             */
            TimeManager ( );

            /*!
             * @brief Destroy the Time Manager object
             * 
             */
            ~TimeManager ( ) { }

            /*!
             * @brief Process the time in the game
             * 
             */
            void processTime ( );

            /*!
             * @brief Return the game time as a string that can simply be displayed
             * 
             * @return std::string The game time as a sttring
             */
            std::string displayTimer ( );

            /*!
             * @brief Get the time in minutes as an integer
             * 
             * @return int The game time in minutes
             */
            int getTime ( );

            /*!
             * @brief Reset the clock 
             * 
             */
            void resetTimer ( );

            /*!
             * @brief Pause the timer
             * 
             */
            void pause ( );

            /*!
             * @brief Resume the paused timer
             * 
             */
            void resume ( );

            /*!
             * @brief Set the Time 
             * 
             * @param timer The time as sf::Time
             */
            void setTime (sf::Time timer);

            /*!
             * @brief Set the time as zero
             * 
             */
            void zero ( );

        private:
            sf::Clock _clock;       //!< The clock for getting the current time
            sf::Time T;             //!< The Game time
            sf::Time tempTime;      //!< The temporary object used for storing time while paused, goal scored or during half time
             
            std::stringstream ss;   //!< The string stream used for returning the game time as a string

            //The integers used during processsing of time
            int t;
            int vt;
            int s;
            int m;
    };
}