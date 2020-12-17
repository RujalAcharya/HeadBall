#!/usr/bin/bash

files="main.cpp AboutState.cpp AssetManager.cpp Ball.cpp  Game.cpp  GameOver.cpp GameState.cpp GoalPost.cpp GoalState.cpp Ground.cpp HalfTime.cpp InputManager.cpp InstructionsState.cpp  MenuScreen.cpp PausedState.cpp Player.cpp SplashScreen.cpp StateMachine.cpp TimeManager.cpp Uphill.cpp Wall.cpp"
flags="-std=c++2a -O2 -pipe"
paths="-LExternal/lib -IExternal/include"
libs="-lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lbox2d"

export HEADBALL=${PWD}/External/lib
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${HEADBALL}

echo 'Compiling...' ; time g++ ${flags} ${files} -o headball ${paths} ${libs} && echo '----------Running...'; ./headball