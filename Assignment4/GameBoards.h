#ifndef GAMEBOARDS_H
#define GAMEBOARDS_H

#include <string>
#include <iostream>
#include "FileHandler.h"

class GameBoards
{
    private:
        char **board;
        int numRows;
        int numColumns;

        FileHandler *fh;

        void DensityPlacement();

    public:
        GameBoards();
        GameBoards(const GameBoards &boardToCopy);
        ~GameBoards();

        void CreateRandomBoard();
        void CreatePredefinedBoard();

        int DetermineBoardMode();
        int DetermineBoardType();

        void DisplayBoard();
        void DisplayPaddedBoard();

        int GetNumRows();
        int GetNumColumns();
        char GetCharAt(int rowPos, int columnPos);

        void ChangeElementAt(int rowPos, int columnPos, char charToChangeTo);

        void SaveMapToFile(string outFileName);
        void CloseOutputFile();
};


#endif