/*!
 * @file main.cpp
 * @authors Asmin Silwal, Prajwol Pradhan, Rujal Acharya, Sanjay KC
 * @brief Project for BECIE 1st year/2nd semester @IOE Pulchowk Campus
 * @version 1.0
 * @date 2020-12-17
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <iostream>

#include "Game.hpp"
#include "Definition.hpp"

/*!
 * @brief Main entry point to the game
 * 
 * @return int - Program return status code : 0 if successful return
 */
int main() {
    HeadBall::Game (WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    return EXIT_SUCCESS;
}
