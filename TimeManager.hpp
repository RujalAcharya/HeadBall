#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>

namespace HeadBall {
    class TimeManager {
        public:
            TimeManager ( );
            ~TimeManager ( ) { }
            void processTime ( );
            std::string displayTimer ( );
            int getTime ( );
            void resetTimer ( );
            void pause ( );
            void resume ( );
            void setTime (sf::Time timer);
            void zero ( );

        private:
            sf::Clock _clock;
            sf::Time T;
            sf::Time tempTime; // used for storing time while paused, goal scored or during half time
             
            std::stringstream ss;

            int t;
            int vt;
            int s;
            int m;
    };
}