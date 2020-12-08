#include "TimeManager.hpp"
#include "Definition.hpp"

namespace HeadBall {
    TimeManager::TimeManager ( ) {
        this->t = 0;
        this->vt = 0;
        this->s = 0;
        this->m = 0;
    }

    void TimeManager::resetTimer ( ) {
        this->_clock.restart ( );
    }

    void TimeManager::processTime ( ) {
        this->T = this->_clock.getElapsedTime() + this->tempTime;
        this->t = this->T.asSeconds();
        this->vt = this->t * (90  / GAME_TIME); //Increase game time by the factor of (90/GAME_TIME)
        this->m = this->vt / 60;    //to convert vt to minutes which is in seconds
        this->s = this->vt - this->m * 60;
    }

    int TimeManager::getTime ( ) {
        return this->m;
    }

    std::string TimeManager::displayTimer () {
        this->ss.str (std::string ( ));

        if (m < 10) {
            this->ss << 0 << this->m;
        } else {
            this->ss << this->m;
        }

        if (s < 10) {
            this->ss << ":" << 0 << this->s;
        } else {
            this->ss << ":" << this->s;
        }

        return this->ss.str ( );
    }

    void TimeManager::pause ( ) {
        this->tempTime = this->T;
    }

    void TimeManager::resume ( ) {
        this->resetTimer ( );
    }

    void TimeManager::setTime (sf::Time timer) {
        this->T = timer;
    }
    
    void TimeManager::zero ( ) {
        this->_clock.restart( );

        this-> T = sf::Time ( );
        this->tempTime = this->T;

    }
}