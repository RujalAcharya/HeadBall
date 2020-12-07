#pragma once

/* 
 This header file is used for defining all the parameters used in the programs.
 While changing the values, make sure that they are in the same format as before.
*/

#define WINDOW_WIDTH 1280.0f
#define WINDOW_HEIGHT 1024.0f
#define WINDOW_TITLE "HeadBall - The Game"

#define WORLD_GRAVITY_X 0.f
#define WORLD_GRAVITY_Y 10.0f

#define SPLASH_SCREEN_TIME 1.0f
#define GAME_TIME 6

#define GROUND_HEIGHT 100.0f
#define GROUND_COLOR Green
#define GROUND_FRICTION 2.0f

#define BALL_DIAMETER 50.0f
#define BALL_DENSITY 2.0f
#define BALL_FRICTION 1.5f
#define BALL_RESTITUTION 0.95f

#define UPHILL_HEIGHT 200.0f
#define UPHILL_WIDTH 200.0f

#define PLAYER_WIDTH 87.0f
#define PLAYER_HEIGHT 103.0f
#define PLAYER_DENSITY 5.0f
#define PLAYER_FRICTION 4.0f
#define MOVEMENT_VELOCITY 5.0f

#define VELOCITY_ITERATIONS 8
#define POSITION_ITERATIONS 3

#define WALL_THICKNESS 2

#define GOAL_POST_WIDTH 132.0f
#define GOAL_POST_HEIGHT 241.0f

// Assets
// fonts
#define TEXT_FONT_FILEPATH "assets/fonts/Roboto/Roboto-Bold.ttf"
#define DIGIT_FONT_FILEPATH "assets/fonts/open24dismay.ttf" // score, time, etc.

///////////////////////
// splash screen state
#define SPLASH_SCREEN_BACKGROUND_FILEPATH "assets/graphics/splash_screen_state/splash_screen.jpg"
#define NEPAL_FLAG_FILEPATH "assets/graphics/splash_screen_state/flags/np.png"


/////////////
// main menu
#define MAIN_MENU_BG_FILEPATH "assets/graphics/main_menu/main_menu_bg.png"

//////////////
// game state
// characters
#define P1_STILL_FILEPATH "assets/graphics/game_state/player/p1.png"    // STILL: not moving
#define P2_STILL_FILEPATH "assets/graphics/game_state/player/p2.png"
#define PLAYER_FOOT_FILEPATH "assets/graphics/game_state/player/foot.png"

// ball, field and goalpost
#define BALL_FILEPATH "assets/graphics/game_state/ball/ball1.png"
#define FIELD_FILEPATH "assets/graphics/game_state/environment/grass.png"
#define GOAL_POST1_FILEPATH "assets/graphics/game_state/environment/goal_1.png"
#define GOAL_POST2_FILEPATH "assets/graphics/game_state/environment/goal_2.png"


////////////////
// paused state or half time
// background
#define PAUSED_BG_FILEPATH "assets/graphics/paused_state/paused_state_bg.png"


/////////
// plain background for about and instructions page
#define PLAIN_BG_FILEPATH "assets/graphics/extra/plain_bg.png"


///////////////
// all buttons
#define PLAY_BTN_FILEPATH "assets/graphics/all_buttons/play_btn.png"
#define PAUSE_BTN_FILEPATH "assets/graphics/all_buttons/pause_btn.png"
#define RESUME_BTN_FILEPATH "assets/graphics/all_buttons/resume_btn.png"
#define INSTRUCTIONS_BTN_FILEPATH "assets/graphics/all_buttons/instructions_btn.png"
#define ABOUT_BTN_FILEPATH "assets/graphics/all_buttons/about_btn.png"
#define EXIT_BTN_FILEPATH "assets/graphics/all_buttons/exit_btn.png"
#define BACK_BTN_FILEPATH "assets/graphics/all_buttons/back_btn.png"

///////////////
// music clips
#define GAME_MUSIC_FILEPATH "assets/music/game_music.ogg"



// Character Control
// Simply change the values below and rebuild the game to change the character controls

#define P1_LEFT A
#define P1_RIGHT D
#define P1_JUMP W
#define P1_KICK G

#define P2_LEFT Left
#define P2_RIGHT Right
#define P2_JUMP Up
#define P2_KICK Comma


/* trial:
#define P1_LEFT A
#define P1_RIGHT D
#define P1_JUMP W
#define P1_KICK Q

#define P2_LEFT Left
#define P2_RIGHT Right
#define P2_JUMP Up
#define P2_KICK Space
*/