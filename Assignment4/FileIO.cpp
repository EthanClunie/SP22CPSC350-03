/*

*/
#include <fstream>
#include <iostream>

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
 * @brief Loads a file for the initial game state from the user
 * 
 * @param inputMapFile 
 * @return string 
 */
void FileIO::LoadMapFile(string inputMapFile, char **someGrid)
{
    ifstream inFile(inputMapFile, ios::in);
    string line;

    // Loop through each row of the grid and insert the provided lines from the input file
    // in those rows. Hanlde potential errors with the input map having different dimensions.

    inFile.close();
}

/**
 * SaveCurrentState
 * @brief Saves the current game state to a file named save.txt
 * 
 * @param fileToSave 
 */
void FileIO::SaveCurrentState(char **currGameState)
{
    string outputFileName = "save.txt";
    ofstream outFile(outputFileName, ios::out);

}