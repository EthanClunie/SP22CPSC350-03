/*
Header file for FileIO class.
Contains the function definitions and any necessary private members
*/
#if !defined(FILEIO_H)
#define FILEIO_H

#include <string>
#include <fstream>
#include <iostream>
#include "Game.h"

using namespace std;

class FileIO
{
    public:
        FileIO();
        ~FileIO();
        void LoadMapFile(string inputMapFile, GameBoard gameGrid);
        void SaveCurrentState(GameBoard currGameState);
    private:
};

#endif