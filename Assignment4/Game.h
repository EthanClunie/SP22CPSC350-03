/*
Header file for Game class.
Contains the function definitions and any necessary private members
*/
#if !defined(GAME_H)
#define GAME_H

#include <iostream>
#include <string>

#include "GameBoard.h"

using namespace std;

class Game
{
    public:
        Game();
        ~Game();
        void Play();

        void SwapGrids(GameBoard Grid1, GameBoard Grid2);

    private:
        GameBoard gameGrid;
        GameBoard copyGrid;
        GameBoard boardWithBoundaries;

        void InitGridRand();

        bool AllDead();
        bool HasStagnated();

        int DetermineGameType();
        char DetermineDelayType();              // to be implemented

        void HandleDelayType(char delayType);   // to be implemented; can try the chrono library for the pause implementation
};

#endif