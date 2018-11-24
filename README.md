# PermAlias

A simple program that helps creating Permanent alias without the need to manually modifying any files yourself. The changes are made to .bash_aliases at your home directory.

## Requirements

You need to have your .bash_aliases on your home directory and have the dependencies for

- iostream
- cstdlib
- string
- regex
- fstream

## Installation

In order to be able to run the program, a Make file has been given to make it easier to use it later. It will run and something like this will go for about 10 seconds.

    Cleaning proyect...
    Building dependencies...
    Compiling proyect...
    g++ -std=gnu++11 src/PermAlias.cpp -o bin/PermAlias

After that you should be able to use the program normally


## Usage

The executable is at the bin folder and you can run it from the console normally. It will require the argument with the following syntax.

    ./PermAlias [NICKNAME]=[COMMAND]

[NICKNAME]: Alias name.
[COMMAND] : Instruction that wants to be linked with the alias.

So if you wanted to do a hello world with it, you would need to do something like

    ./PermAlias Hello=echo \"World\"