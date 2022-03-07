#include "Classic.h"
using namespace std;

int Classic::FindNumNeighbors()
{

}

GameBoard Classic::CreateGridWithBoundaries(GameBoard boardWithoutBoundaries)
{
    int numRowsActualGrid = boardWithoutBoundaries.GetNumRows();
    int numColsActualGrid = boardWithoutBoundaries.GetNumCols();
    gridWithBoundaries.InitGridOfKnownSize(numRowsActualGrid + 2, numColsActualGrid + 2);
    
    for (int iRow = 0; iRow < (numRowsActualGrid + 2); ++iRow)
    {
        for (int iCol = 0; iCol < (numColsActualGrid + 2); ++iCol)
        {
            if ((iRow == 0) || (iCol == 0) || (iRow == numRowsActualGrid + 1) || (iCol == numColsActualGrid + 1))
            {
                gridWithBoundaries.ChangeCurrElementPos(iRow, iCol, '-');
            }
            else
            {
                char ch = boardWithoutBoundaries.GetCharAt(iRow, iCol);
                gridWithBoundaries.ChangeCurrElementPos(iRow + 1, iRow + 1, ch);
            }
        }
    }
    return gridWithBoundaries;
}