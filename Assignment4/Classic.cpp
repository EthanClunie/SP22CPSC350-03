#include "Classic.h"

using namespace std;

/**
 * FindNumNeighbors
 * @brief Finds the number of neighbors for any given postion. Does so
 * by checking all 8 immediate positions surrounding this location
 * 
 * @param currRowPos 
 * @param currColPos 
 * @return int 
 */
int Classic::FindNumNeighbors(int currRowPos, int currColPos)
{
    int totalNumNeighbors = 0;

    int rowOnPadded = currRowPos+1;
    int colOnPadded = currColPos+1;

    // Check each position around some given (row, column) location
    for (int iRow = currRowPos; iRow <= currRowPos+2; iRow++)
    {
        for (int iCol = currColPos; iCol <= currColPos+2; iCol++)
        {
            if ((iRow == rowOnPadded) && (iCol == colOnPadded)) // exempts the given location
            {
                continue;
            }

            if (gridWithBoundaries.GetCharAt(iRow, iCol) == 'X') // Checks a position to see if it is same as an 'X'
            {
                ++totalNumNeighbors;
            }
        }
    }

    return totalNumNeighbors;
}

/**
 * CreateGridWithBoundaries
 * @brief Creates a grid that contains boundary conditions to check against
 * 
 * @param boardWithoutBoundaries 
 */
void Classic::CreateGridWithBoundaries(GameBoard boardWithoutBoundaries)
{
    int numRowsActualGrid = boardWithoutBoundaries.GetNumRows();
    int numColsActualGrid = boardWithoutBoundaries.GetNumCols();

    gridWithBoundaries.InitGridOfKnownSize(numRowsActualGrid + 2, numColsActualGrid + 2);
    
    for (int iRow = 0; iRow < (gridWithBoundaries.GetNumRows()); ++iRow)
    {
        for (int iCol = 0; iCol < (gridWithBoundaries.GetNumCols()); ++iCol)
        {
            if ((iRow == 0) || (iCol == 0) || (iRow == gridWithBoundaries.GetNumRows()-1) || (iCol == gridWithBoundaries.GetNumCols()-1))
            {
                gridWithBoundaries.ChangeCurrElementPos(iRow, iCol, '-');
            }
            else
            {
                char ch = boardWithoutBoundaries.GetCharAt(iRow - 1, iCol - 1);
                gridWithBoundaries.ChangeCurrElementPos(iRow, iCol, ch);
            }
        }
    }
}