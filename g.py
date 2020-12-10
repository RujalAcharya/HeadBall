#! /usr/bin/env python  
import os  

files = "main.cpp AboutState.cpp AssetManager.cpp Ball.cpp  Game.cpp  GameOver.cpp GameState.cpp GoalPost.cpp GoalState.cpp Ground.cpp HalfTime.cpp InputManager.cpp InstructionsState.cpp  MenuScreen.cpp PausedState.cpp Player.cpp SplashScreen.cpp StateMachine.cpp TimeManager.cpp Uphill.cpp Wall.cpp"
libraries = "-lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lbox2d"
# flags = "-std=c++2a -O2 -pipe -Wall"
flags = "-std=c++2a -O2"
debugging_flags = " -fsanitize=address -g -ASAN_OPTIONS=new_delete_type_mismatch=0"

os.system(f"echo 'Compiler: g++ \nFlags: {flags} \nDebugging flags: {debugging_flags} \nCompiling...' ; time g++ {flags} {files} -o main {libraries} && echo '\n----------\nRunning...'; ./main")

# comment above line and uncomment below for clang++
# os.system(f"echo 'Compiling...' ; time clang++ -std=c++2a -O3 {files} -o main {libraries} && echo '\n----------\nRunning...'; time ./main")
