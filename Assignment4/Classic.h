/*
Header file for Classic class.
Contains the function definitions and any necessary private members
*/
#if !defined(CLASSIC_H)
#define CLASSIC_H

#include "Game.h"
using namespace std;

class Classic
{
    public:
        int FindNumNeighbors(int currRowPos, int currColPos);
        void CreateGridWithBoundaries(GameBoard boardWithoutBoundaries);
        
    private:
        GameBoard gridWithBoundaries;

};

#endif