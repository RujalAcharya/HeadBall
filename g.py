#! /usr/bin/env python  
import os  

files = "main.cpp AssetManager.cpp Ball.cpp  Game.cpp  GameOver.cpp GameState.cpp Player.cpp GoalPost.cpp Ground.cpp HalfTime.cpp InputManager.cpp MenuScreen.cpp PausedState.cpp SplashScreen.cpp StateMachine.cpp TimeManager.cpp Uphill.cpp"
link = "-lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lbox2d"

os.system(f"echo 'Compiling...' ; time g++ -std=c++2a -O3 {files} -o main {link} && echo '\n----------\nRunning...'; time ./main")

# comment above line and uncomment below for clang++
# os.system(f"echo 'Compiling...' ; time clang++ -std=c++2a -O3 {files} -o main {link} && echo '\n----------\nRunning...'; time ./main")
