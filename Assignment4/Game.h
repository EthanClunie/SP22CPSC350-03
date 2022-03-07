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

        void InitGridRand();

        int FindNumNeighbors() {} //no implementation in this class
        bool AllDead();
        bool HasStagnated();

        int DetermineGameType();
};

#endif