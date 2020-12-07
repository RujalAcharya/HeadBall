#! /usr/bin/env python  
import os  

files = "main.cpp AssetManager.cpp Ball.cpp  Game.cpp  GameOver.cpp GameState.cpp Player.cpp Wall.cpp Ground.cpp GoalPost.cpp HalfTime.cpp InputManager.cpp MenuScreen.cpp PausedState.cpp SplashScreen.cpp StateMachine.cpp TimeManager.cpp Uphill.cpp"
libraries = "-lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lbox2d"
# flags = "-std=c++2a -O2 -pipe -Wall"
flags = "-std=c++2a -O2"
os.system(f"echo 'Compiler: g++ \nFlags: {flags} \nCompiling...' ; time g++ {flags} {files} -o main {libraries} && echo '\n----------\nRunning...'; time ./main")

# comment above line and uncomment below for clang++
# os.system(f"echo 'Compiling...' ; time clang++ -std=c++2a -O3 {files} -o main {libraries} && echo '\n----------\nRunning...'; time ./main")
