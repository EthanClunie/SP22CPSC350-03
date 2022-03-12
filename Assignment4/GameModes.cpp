/**
 * @file GameModes.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "GameModes.h"

/**
 * GameMode
 * @brief Construct a new Game Modes:: Game Modes object
 * 
 */
GameModes::GameModes()
{
}


/**
 * ~GameMode
 * @brief Destroy the Game Modes:: Game Modes object
 * 
 */
GameModes::~GameModes()
{
}


/**
 * GetNumNeighbors
 * @brief Returns the number of neighbors of a given location on the passed in board for use in GameSim
 * 
 * @param row 
 * @param column 
 * @param boardToCheck 
 * @return int 
 */
int GameModes::GetNumNeighbors(int row, int column, GameBoards &boardToCheck)
{
    int totalNumNeighbors = 0;

    //int rowOnPadded = row+1;
    //int colOnPadded = column+1;

    // Check each position around some given (row, column) location
    for (int iRow = row-1; iRow <= row+1; iRow++)
    {
        for (int iCol = column-1; iCol <= column+1; iCol++)
        {
            if ((iRow == row) && (iCol == column)) // exempts the given location
            {
                continue;
            }

            if (boardToCheck.GetCharAt(iRow, iCol) == 'X') // Checks a position to see if it is same as an 'X'
            {
                ++totalNumNeighbors;
            }
        }
    }

    return totalNumNeighbors;
}


/**
 * ChangeDoughnutBoundaries
 * @brief Changes the boundaries of the mainGrid based on rules for Doughnut mode
 * 
 * @param Board1 
 */
void GameModes::ChangeDoughnutBoundaries(GameBoards *Board1)
{
    // Handles the corners
    Board1->ChangeElementAt(0,0, Board1->GetCharAt(Board1->GetNumRows(), Board1->GetNumColumns()));
    Board1->ChangeElementAt(0,Board1->GetNumColumns() + 1, Board1->GetCharAt(Board1->GetNumRows(), 1));
    Board1->ChangeElementAt(Board1->GetNumRows() + 1, 0, Board1->GetCharAt(1, Board1->GetNumColumns()));
    Board1->ChangeElementAt(Board1->GetNumRows() + 1, Board1->GetNumColumns() + 1, Board1->GetCharAt(1, 1));

    // Handles changing the row boundaries
    for (int i = 1; i < Board1->GetNumRows() + 1; ++i)
    {
        Board1->ChangeElementAt(i, 0, Board1->GetCharAt(i, Board1->GetNumColumns()));
        Board1->ChangeElementAt(i, Board1->GetNumColumns() + 1, Board1->GetCharAt(i, 1));
    }

    // Handles changing the column boundaries
    for (int i = 1; i < Board1->GetNumColumns() + 1; ++i)
    {
        Board1->ChangeElementAt(0, i, Board1->GetCharAt(Board1->GetNumRows(), i));
        Board1->ChangeElementAt(Board1->GetNumRows() + 1, i, Board1->GetCharAt(1, i));
    }
}


/**
 * ChangeMirrorBoundaries
 * @brief Changes the boundaries of the mainGrid based on rules for Mirror mode
 * 
 * @param Board1 
 */
void GameModes::ChangeMirrorBoundaries(GameBoards *Board1)
{
    // Handles Corner Boundaries
    Board1->ChangeElementAt(0,0, Board1->GetCharAt(1, 1));
    Board1->ChangeElementAt(0,Board1->GetNumColumns() + 1, Board1->GetCharAt(1,Board1->GetNumColumns()));
    Board1->ChangeElementAt(Board1->GetNumRows() + 1, 0, Board1->GetCharAt(Board1->GetNumRows(),1));
    Board1->ChangeElementAt(Board1->GetNumRows() + 1, Board1->GetNumColumns() + 1, Board1->GetCharAt(Board1->GetNumRows(),Board1->GetNumColumns()));
    
    //Handles Row Boundaries
    for (int i = 1; i < Board1->GetNumRows() + 1; ++i) 
    {
        Board1->ChangeElementAt(i, 0, Board1->GetCharAt(i, 1));
        Board1->ChangeElementAt(i, Board1->GetNumColumns() + 1, Board1->GetCharAt(i, Board1->GetNumColumns()));
    }

    // Handles Column Boundaries
    for (int i = 1; i < Board1->GetNumColumns() + 1; ++i) 
    {
        Board1->ChangeElementAt(0, i, Board1->GetCharAt(1, i));
        Board1->ChangeElementAt(Board1->GetNumRows() + 1, i, Board1->GetCharAt(Board1->GetNumRows(), i));
    }
}