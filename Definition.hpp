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

#define SPLASH_SCREEN_TIME 1.0f                             //this is time in seconds for which splash screen is displayed
#define GAME_TIME 2                                         //this is how long the game should be in total in real life and is in minutes

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

#define FRAMES_PER_ANIMATION 4

// Assets
// fonts
#define TEXT_FONT_FILEPATH "assets/fonts/foo/foo.ttf"
#define DIGIT_FONT_FILEPATH "assets/fonts/open24dismay.ttf" // score, time, etc.

///////////////////////
// splash screen state
#define SPLASH_SCREEN_BACKGROUND_FILEPATH "assets/graphics/splash_screen_state/splash_screen.jpg"
#define NEPAL_FLAG_FILEPATH "assets/graphics/splash_screen_state/flags/np.png"

//////////////////////
// splash screen animation
#define SPLASH_SCREEN_ANIM_1 "assets/graphics/new_anim/1.png"
#define SPLASH_SCREEN_ANIM_2 "assets/graphics/new_anim/2.png"
#define SPLASH_SCREEN_ANIM_3 "assets/graphics/new_anim/3.png"
#define SPLASH_SCREEN_ANIM_4 "assets/graphics/new_anim/4.png"
#define SPLASH_SCREEN_ANIM_5 "assets/graphics/new_anim/5.png"
#define SPLASH_SCREEN_ANIM_6 "assets/graphics/new_anim/6.png"
#define SPLASH_SCREEN_ANIM_7 "assets/graphics/new_anim/7.png"//
#define SPLASH_SCREEN_ANIM_8 "assets/graphics/new_anim/8.png"
#define SPLASH_SCREEN_ANIM_9 "assets/graphics/new_anim/9.png"
#define SPLASH_SCREEN_ANIM_10 "assets/graphics/new_anim/10.png"
#define SPLASH_SCREEN_ANIM_11 "assets/graphics/new_anim/11.png"



/////////////
// main menu
#define MAIN_MENU_BG_FILEPATH "assets/graphics/main_menu/main_menu_bg.png"

//////////////
// game state
// characters
#define P1_IDLE_FILEPATH "assets/graphics/game_state/player/p1_idle.png" 
#define P1_R_FILEPATH "assets/graphics/game_state/player/p1_R.png"
#define P1_L_FILEPATH "assets/graphics/game_state/player/p1_L.png"

#define P2_IDLE_FILEPATH "assets/graphics/game_state/player/p2_idle.png"
#define P2_R_FILEPATH "assets/graphics/game_state/player/p2_R.png"
#define P2_L_FILEPATH "assets/graphics/game_state/player/p2_L.png"


// ball, field and goalpost
#define BALL_FILEPATH "assets/graphics/game_state/ball/ball1.png"
#define FIELD_FILEPATH "assets/graphics/game_state/environment/grass.png"
#define GOAL_POST1_FILEPATH "assets/graphics/game_state/environment/goal_1.png"
#define GOAL_POST2_FILEPATH "assets/graphics/game_state/environment/goal_2.png"


// paused state, half time && full time
// background
#define PAUSED_BG_FILEPATH "assets/graphics/paused_state/paused_state_bg.png"
#define FULL_TIME_BG_FILEPATH "assets/graphics/extra/full_time_bg.png"
#define HALF_TIME_BG_FILEPATH "assets/graphics/extra/half_time_bg.png"


///////////////
// goal state
#define RED_GOAL_BG_FILEPATH "assets/graphics/goal_state/red.png"
#define GREEN_GOAL_BG_FILEPATH "assets/graphics/goal_state/green.png"
#define YELLOW_GOAL_BG_FILEPATH "assets/graphics/goal_state/yellow.png"

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
#define REPLAY_BTN_FILEPATH "assets/graphics/all_buttons/replay_btn.png"


///////////////
// music clips
#define GAME_MUSIC_FILEPATH "assets/audio/music/game_music.ogg"
#define CROWD_CHEER_FILEPATH "assets/audio/music/crowd_cheer.ogg"

//////////////////
// sfx/sound clips
#define BTN_CLICK_SFX_FILEPATH "assets/audio/sfx/button_click.wav"
#define WHISTLE_SHORT_SFX_FILEPATH "assets/audio/sfx/whistle_short.wav"
#define WHISTLE_LONG_SFX_FILEPATH "assets/audio/sfx/whistle_long.wav"
#define PLAYER_JUMP_SFX_FILEPATH "assets/audio/sfx/player_jump.wav"
#define PLAYER_KICK_SFX_FILEPATH "assets/audio/sfx/player_kick.wav"
#define HARD_KICK_SFX_FILEPATH "assets/audio/sfx/ball_kick_hardest.wav"
#define CROWD_CHEER_ON_GOAL_SFX_FILEPATH "assets/audio/sfx/crowd_cheer_goal.wav"

/////////////////////
// Character Controls
// Simply change the values below and rebuild the game to change the character controls

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define P1_LEFT A
#define P1_RIGHT D
#define P1_JUMP W
#define P1_KICK G

#define P2_LEFT Left
#define P2_RIGHT Right
#define P2_JUMP Up
#define P2_KICK Comma


#define KICK_FORCE_SCALE 50