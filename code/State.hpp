#pragma once

namespace HeadBall {
    /*!
     * @brief Abstract based class which inherits all the states of the game
     * 
     */
    class State {
        public:
            /*!
             * @brief Pure virtual function for initializing state related data
             * 
             */
            virtual void init ( ) = 0; 

            /*!
             * @brief Pure virtual function for handling user input
             * 
             */
            virtual void handleInput ( ) = 0;

            /*!
             * @brief Pure virtual function for updating state data
             * 
             */
            virtual void update ( ) = 0;

            /*!
             * @brief Pure virtual function for drawing state objects
             * 
             */
            virtual void draw ( ) = 0;

            /*!
             * @brief Virtual function for pausing the state
             * 
             */
            virtual void pause ( ) { }

            /*!
             * @brief Virtual function for resuming the object
             * 
             */
            virtual void resume ( ) { }

            /*!
             * @brief Vitrual function for performing animations
             * 
             */
            virtual void animate ( ) { }

            /*!
             * @brief Destroy the State object
             * 
             */
            virtual ~State ( ) = default;
    };
}