/*

*/
#include "FileIO.h"

using namespace std;

/**
 * @brief Construct a new File IO object
 * 
 */
FileIO::FileIO()
{
}

/**
 * @brief Destroy the File IO object
 * 
 */
FileIO::~FileIO()
{
}

/**
 * LoadMapFile
 * @brief Takes a user inputed text file and converts that into the initial game board
 * 
 * @param inputMapFile 
 * @param gameGrid 
 */
void FileIO::LoadMapFile(string inputMapFile, GameBoard gameGrid)
{
    ifstream inFile(inputMapFile, ios::in);
    string lineRow;
    string lineColumn;

    if (!inFile.is_open())
    {
        cout << "Error Opening inFile" << endl;
        return;
    }
    
    string userRows;
    string userColumns;

    getline(inFile, userRows);
    getline(inFile, userColumns);

    int usrRow = stoi(userRows); // string to int type cast
    int usrCol = stoi(userColumns); // string to int type cast
    // Set someGrid rows and columns as above
    gameGrid.InitFileGrid(usrRow, usrCol);

    // Loop through each row of the grid and insert the provided lines from the input file
    // in those rows. Handle potential errors with the input map having different dimensions.

    int iCol = 0;
    while (getline(inFile, lineRow))
    {
        for (int iRow = 0; iRow < lineRow.length(); ++iRow)
        {
            // Take each char in lineRow[i] and pass to gameGrid
            gameGrid.ChangeCurrElementPos(iRow, iCol, lineRow[iRow]);
        }
        ++iCol;
    }


    inFile.close();
}

/**
 * SaveCurrentState
 * @brief Saves the current game state to a file named save.txt
 * 
 * @param fileToSave 
 */
void FileIO::SaveCurrentState(GameBoard currGameState)
{
    string outputFileName = "save.txt";
    ofstream outFile(outputFileName, ios::out);

    outFile.close();
}