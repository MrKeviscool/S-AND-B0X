#!/bin/bash
g++ -c sandbox.cpp
g++ sandbox.o -o sbox -lsfml-graphics -lsfml-window -lsfml-system
./sbox
