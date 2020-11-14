#!/bin/bash
pushd build
g++ -c ../src/*.cpp -g -Wall && g++ *.o -o game.out -lSDL2main -lSDL2 -lSDL2_image 
popd
