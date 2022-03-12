/**
 * @file GameModes.h
 * @authors Ethan Clunie, Samuel Bernsen
 * @brief Header file for GameModes class. Contains method definitions for the methods
 * required to run each separate BoundaryMode (classic, doughnut, mirror)
 * @version 0.1
 * @date 2022-03-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef GAMEMODES_H
#define GAMEMODES_H

#include "GameBoards.h"

class GameModes
{
    public:
        GameModes();
        ~GameModes();
        
        int GetNumNeighbors(int rowPos, int columnPos, GameBoards &boardToCheck);
        void ChangeDoughnutBoundaries(GameBoards *Board1);
        void ChangeMirrorBoundaries(GameBoards *Board1);
};


#endif