# SDES Encryption Algorithm
_Dylan Miller and Joel Byers_

_CSC 487_

## Overview
This C++ project includes functions for encryption and decryption using the SDES algorithm. It is split into 2 parts:
* SDES Functions
    * SDES.cpp
    * SDES.h
* Driver program
    * Main.cpp

## Building
This project can be build with g++:

`g++ *.cpp -o sdes.out`

## Running

### Basic useage

`./sdes.out encrypt input.txt output.txt key.txt`

### Usage
The program reads in data from a file, performs the encryption/decryption, and writes the output to a different file. The key used for encryption/decryption is also read from a file.

The program can be run in 2 modes:
* Encrytion
* Decryption

The first argument determines what mode the program is running in.

`./sdes.out encrypt`

`./sdes.out decrypt`

The rest of the arguments can be used to set the input, output, and key files.

`./sdes.out encrypt input.txt output.txt key.txt`