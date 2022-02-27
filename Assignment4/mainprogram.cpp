/*
Main method for the Game of Life project.
Servers as a driver that just calls a few methods to run
the entire game through other classes.
*/
#include <iostream>
#include <string>

#include "Game.h"

using namespace std;

int main()
{
    Game* game = new Game();

    game->Play();

    delete game;
    return 0;
}