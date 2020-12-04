#include "TimeManager.hpp"
#include "Definition.hpp"

namespace HeadBall {
    TimeManager::TimeManager ( ) {
        this->t = 0;
        this->vt = 0;
        this->s = 0;
        this->m = 0;

        this->tempTime = sf::Time ();

        this->_clock.restart ( );
    }

    void TimeManager::resetTimer ( ) {
        this->_clock.restart ( );
    }

    void TimeManager::processTime ( ) {
        this->T = this->_clock.getElapsedTime() + this->tempTime;
        this->t = this->T.asSeconds();
        this->vt = this->t * 18; //Converting 5 minutes into 90
        this->m = this->vt / 60;
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
}