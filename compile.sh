#!/bin/bash
g++ -c sandboxgraphics.cpp
g++ sandboxgraphics.o -o sbox -lsfml-graphics -lsfml-window -lsfml-system
./sbox
