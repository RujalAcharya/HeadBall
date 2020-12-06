#pragma once

/* 
 This header file is used for defining all the parameters used in the programs.
 While changing the values, make sure that they are in the same format as before.
*/

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 1024
#define WINDOW_TITLE "HeadBall - The Game"

#define WORLD_GRAVITY_X 0.f
#define WORLD_GRAVITY_Y 10.0f

#define SPLASH_SCREEN_TIME 3.0f
#define GAME_TIME 6

#define GROUND_HEIGHT 100.0f
#define GROUND_COLOR Green
#define GROUND_FRICTION 2.0f

#define BALL_DIAMETER 50.0f
#define BALL_DENSITY 2.0f
#define BALL_FRICTION 1.5f
#define BALL_RESTITUTION 0.8f

#define VELOCITY_ITERATIONS 8
#define POSITION_ITERATIONS 3

// Assets and fonts

#define TEXT_FONT "fonts/Roboto/Roboto-Bold.ttf"





// Character Control
// Simply change the values below and rebuild the game to change the character controls

#define P1_LEFT F
#define P1_RIGHT H
#define P1_JUMP T
#define P1_KICK A

#define P2_LEFT Left
#define P2_RIGHT Right
#define P2_JUMP Up
#define P2_KICK Comma
