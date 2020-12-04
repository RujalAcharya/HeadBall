#! /usr/bin/env python

import os

os.system("g++ -std=c++20  main.cpp StateMachine.cpp  Game.cpp SplashScreen.cpp MenuScreen.cpp GameState.cpp TimeManager.cpp PausedState.cpp HalfTime.cpp GameOver.cpp -o main -lsfml-graphics -lsfml-system -lsfml-window")