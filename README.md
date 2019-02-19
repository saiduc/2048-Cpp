# 2048 Game
A simple command line implementation of the 2048 game. This was a project as part of a programming module at Imperial College London. This was actually the first time I'd ever touched C++ and so it was a fun way to get started.

## Usage
Compile it however you compile C++ programs on your OS. For macOS and Linux with the G++ compiler, run within the directory the cource file is in:
```
g++ 2048.cpp -o 2048 
```
Then you can run the compiled binary file the normal way.

## Features
* Takes user input with wasd in the terminal
* Prints the board in terminal
* Allows configuration board to be loaded as a .txt file
* Detects when the player has won/lost

## Screenshots
<img width="350" alt="screenshot 2019-02-19 at 17 45 42" src="https://user-images.githubusercontent.com/40459599/53035868-5a725500-346e-11e9-9623-850e5d57b4b2.png">

## Requirements
* A C++11 compiler to compile the source code

## Some Notes on What I Learned
I'd never worked with C++ before this project so it isn't the best implementation of the game. Some of the code isn't optimised mathematically. For example, with the way the numbers shift, I manually shift each number individually. However, I am sure there is probably a better algorithm for this.

Instead of writing separate functions for each direction of movement, it is possible to use a single movement function in one direction, and emulate movement in other directions by rotating the board an appropriate amount before using the same movement function. A possible suggestion for anyone wanting to improve this!

Despite all this, I now feel confident with basic C++ and I feel I can tackle more complicated projects in the future. I will definitely be working more with C++ in the future. 

## License
This project is licensed under the terms of the MIT license. Do whatever you want with it!

## Acknowledgements
* The good people over on StackOverflow for all their help answering my questions
